#ifndef COURSE_WORK_MAINFUNCTIONS_H
#include "rapidjson/document.h"
#include "headers/HttpPost.h"
#include "headers/base64.h"
#include "headers/MyTypes.h"

namespace MainFunctions
{
    MyTypes::AnswerMessage compositeFunction(MyTypes::CompositeType compositeType, MyTypes::unsignedInt unsignedInt);
    MyTypes::AnswerMessage floatFunction(float floatType);
}
#define COURSE_WORK_MAINFUNCTIONS_H

#endif
