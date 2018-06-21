#ifndef COURSE_WORK_PAYLOADMAKER_H
#define COURSE_WORK_PAYLOADMAKER_H

#include <iostream>
#include "headers/MyTypes.h"
class PayloadMaker
{
public:
    static std::string compositeFunction(std::string function_name, MyTypes::CompositeType compositeType,
        MyTypes::unsignedInt unsignedInt);

    static std::string floatFunction(std::string function_name, float floatType);

private:
};
#endif
