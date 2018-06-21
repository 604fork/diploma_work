#ifndef COURSE_WORK_TOSTRING_H
#define COURSE_WORK_TOSTRING_H

#include <iostream>
#include <sstream>

template <class T>
std::string toString(const T& rValueToStr)
{
    std::stringstream stringStream;
    stringStream << rValueToStr;
    std::string string;
    string = stringStream.str();
    return string;
}

#endif //COURSE_WORK_TOSTRING_H
