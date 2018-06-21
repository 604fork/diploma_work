#include <iostream>
#include <iomanip>
#include "rapidjson/document.h"
#include "headers/MainFunctions.h"

#define COMPOSITE_FUNCTION
//#define FLOAT_FUNCTION

int main() {

#ifdef COMPOSITE_FUNCTION
    MyTypes::CompositeType compositeType;
    compositeType.type = MyTypes::EnumConstants::FIRST_CONST;
    compositeType.unsignedChar = 0xFF;
    MyTypes::unsignedInt unsignedInt = 0x01;
    MyTypes::AnswerMessage answerMessage;
    answerMessage = MainFunctions::compositeFunction(compositeType, unsignedInt);
    std::cout << "answerMessage.code = " << answerMessage.code << " "
        << "answerMessage.text = " <<  answerMessage.text << std::endl;
#endif

#ifdef FLOAT_FUNCTION
    MyTypes::AnswerMessage answerMessage;
    answerMessage = MainFunctions::floatFunction(1234.5);
    std::cout << std::setprecision(8) << "answerMessage.code = " << answerMessage.code << " "
              << "answerMessage.text = " <<  answerMessage.text << std::endl;
#endif

    return 0;
}