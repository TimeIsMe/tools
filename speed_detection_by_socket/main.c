//#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>  
#include <sys/time.h>  
#include <stdlib.h>  
#include <signal.h>  

//#define DOUBLE_PORT
//#define SERVER 
#ifdef SERVER

static int status = 0;  
static struct itimerval oldtv;  
  
void set_timer()  
{  
    struct itimerval itv;  
    itv.it_interval.tv_sec = 1;  
    itv.it_interval.tv_usec = 0;  
    itv.it_value.tv_sec = 1;  
    itv.it_value.tv_usec = 0;  
    setitimer(ITIMER_REAL, &itv, &oldtv);  
}  
  
void signal_handler(int m)  
{  
	if(0 == status){
		status = 1;  
	}
    
    //printf("%d\n", count);  
}  

int main()
{
	int sockfd,new_fd,numbytes;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int sin_size;
	char buff[1024];
	double count = 0;
#ifdef DOUBLE_PORT
	pid_t cpid;
	
	if((cpid = fork()) == -1){
		perror("cpid!\r\n");
	}else if(cpid > 0){
		printf("This is parent process!\r\n");
		my_addr.sin_port=htons(6666);
	}else{
		printf("This is child process!\r\n");
		my_addr.sin_port=htons(6667);
	}
#else
	my_addr.sin_port=htons(6666);
#endif /*DOUBLE_PORT*/

	signal(SIGALRM,signal_handler);

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket!");
		exit(1);
	}
	printf("socket Success!,sockfd=%d\n",sockfd);
	//
	my_addr.sin_family=AF_INET;
	//my_addr.sin_port=htons(6666);
	my_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(my_addr.sin_zero),8);
	//
	if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1)
	{
		perror("bind");
		exit(1);
	}
	printf("bind Success!\n");
	//
	if(listen(sockfd,10)==-1)
	{
		perror("listen");
		exit(1);
	}
	printf("Listen.....\n");
	//
	while(1)
	{
		sin_size=sizeof(struct sockaddr_in);
		//
		if((new_fd = accept(sockfd,(struct sockaddr *)&their_addr,&sin_size))==-1)
		{
			perror("accept");
			exit(1);
		}
		printf("had accepted!\r\n"); 
		//
		if(!fork())
		{
			set_timer();
			printf("had set timer\r\n");
			while(1){
				if((numbytes = recv(new_fd,buff,1000,0))==-1)
				{
					perror("recv");
					exit(1);
				}
				count += numbytes;
				numbytes = 0;
				if(1==status){
					//printf("had receive %lf bit\r\n",count);
					printf("net rate:%0.0lfMB/s\r\n",count/131072);
					count = 0;
					status = 0;
				}
			}

			close(new_fd);
			exit(0);
		}
		//
	}
	close(sockfd);
	return 0;
}


#else

int main(int argc ,char * argv[])
{
	int sockfd,numbytes;
	char buff[100];
	struct hostent * he;
	struct sockaddr_in their_addr;
	int i=0;
	const char content[]="012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789\
						012345678901234567890123456789012345678901234567890123456789";
	//
	he=gethostbyname(argv[1]);
#ifdef DOUBLE_PORT
	pid_t cpid;
	cpid = fork();
	if(cpid == -1){
		perror("fork!\r\n");
	}else if(cpid > 0){		/*This is a parent process!*/
		their_addr.sin_port=htons(6666);
	}else{					/*This is a child process!*/
		their_addr.sin_port=htons(6667);
	}
#else
	their_addr.sin_port=htons(6666);
#endif /*DOUBLE_PORT*/
	//
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket!");
		exit(1);
	}
	//printf("socket Success!,sockfd=%d\n",sockfd);
	their_addr.sin_family=AF_INET;
	their_addr.sin_port=htons(6666);
	their_addr.sin_addr=*((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero),8);
	//
	if(connect(sockfd,(struct sockaddr *)&their_addr,sizeof(struct sockaddr))==-1)
	{
		perror("connect");
		exit(1);
	}


	while(1){
		if(send(sockfd,content,sizeof(content),0)==-1)
		{
			perror("send");
			exit(1);
		}
	}
	//printf("connect Success!\n");
	if(send(sockfd,"hello!I am client.",26,0)==-1)
	{
		perror("send");
		exit(1);
	}
	//printf("send .\n");
	if((numbytes = recv(sockfd,buff,100,0))==-1)
	{
		perror("recv");
		exit(1);
	}
	printf("recv is :%s\n",buff);
	//
	close(sockfd);
	return 0;
}


#endif
