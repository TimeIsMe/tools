#ifndef COMMENTS_H
#define COMMENTS_H
#include <QString>

typedef struct{
    QString name;
    QString component;
}paramStruct;

typedef struct {
    QString function_name;
    QString author;
    QString brief;
    paramStruct param[4];
    paramStruct retval;
}commentStruct;

class Comments
{
private:
    commentStruct comStruct;
    int max_name_length;
    QString getParams();
    QString getBrief();
    QString getRetval();
public:
    Comments();
    QString getComments(commentStruct &comStruct);
};

#endif // COMMENTS_H
