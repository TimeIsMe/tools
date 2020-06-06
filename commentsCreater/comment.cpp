#include "comment.h"

Comments::Comments()
{

}

QString Comments::getParams(){
    QString retQString = "";
    int count = 0;
    for(int i=0; i<4; i++){
        count = 0;
        if(this->comStruct.param[i].name.isEmpty()){
            continue;
        }
        retQString += QString("  * %1 %2 ").arg("@Param",-9,' ')\
                .arg(this->comStruct.param[i].name,-this->max_name_length,' ');
        retQString += this->comStruct.param[i].component.mid(30*count++,30) + "\r\n";
        while(!this->comStruct.param[i].component.mid(30*count,30).isNull()){
            retQString +=QString("  * %1 %2 %3\r\n").arg(" ", -9,' ')\
                    .arg(" ",-this->max_name_length,' ')\
                    .arg(this->comStruct.param[i].component.mid(30*count++,30));
        }
    }
    return retQString;
}

QString Comments::getBrief(){
    QString resultQString;
    int count = 0;
    resultQString += QString("  * %1 %2 %3\r\n")\
            .arg("@Brief",-9,' ')\
            .arg(" ",-this->max_name_length,' ')\
            .arg(this->comStruct.brief.mid(30*count++,30));
    while(!this->comStruct.brief.mid(30*count,30).isNull()){
        resultQString += QString("  * %1 %2 %3\r\n")\
                .arg(" ",-9,' ')\
                .arg(" ",-this->max_name_length,' ')\
                .arg(this->comStruct.brief.mid(30*count++,30));
    }
    return resultQString;
}

QString Comments::getRetval(){
    QString resultQString;
    int count = 0;
    resultQString += QString("  * %1 %2 ")\
            .arg("@Retval",-9,' ')\
            .arg(this->comStruct.retval.name,-this->max_name_length,' ');
    resultQString += QString(this->comStruct.retval.component.mid(30*count++,30)) + "\r\n";
    while(!this->comStruct.retval.component.mid(30*count,30).isNull()){
        resultQString += QString("  * %1 %2 %3\r\n")\
                .arg(" ",-9,' ')\
                .arg(" ",-this->max_name_length,' ')\
                .arg(this->comStruct.retval.component.mid(30*count++,30));
    }
    return resultQString;
}

QString Comments::getComments(commentStruct &comStruct){
    QString resultQString = "";
    this->comStruct = comStruct;
    this->max_name_length = this->comStruct.param[0].name.length();
    for(int i=1; i<4; i++){
        if(this->max_name_length < this->comStruct.param[i].name.length()){
            this->max_name_length = this->comStruct.param[i].name.length();
        }
    }
    (this->max_name_length > this->comStruct.retval.name.length())? this->max_name_length=this->max_name_length:\
                (this->max_name_length = this->comStruct.retval.name.length());

    resultQString = "/**\r\n";
    resultQString += QString("  * %1 %2\r\n")\
            .arg("@Function",-9,' ').arg(this->comStruct.function_name);
    resultQString += QString("  * %1 %2\r\n")\
            .arg("@Author",-9,' ').arg(this->comStruct.author);
    resultQString += getBrief();
    resultQString += getParams();
    resultQString += getRetval();
    resultQString += "  */";
    return resultQString;
}
