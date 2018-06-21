#ifndef COURSE_WORK_MYTYPES_H
#define COURSE_WORK_MYTYPES_H

namespace MyTypes
{
    struct EnumConstants
    {
        enum Val
        {
            ZERO_CONST,
            FIRST_CONST,
            SECOND_CONST,
            THIRD_CONST
        };
    };

    struct CompositeType
    {
        CompositeType() : type(EnumConstants::ZERO_CONST), unsignedChar(0) {}
        EnumConstants::Val type;
        unsigned char unsignedChar;
    };

    struct AnswerMessage
    {
        AnswerMessage(): code(0) {}
        AnswerMessage(float c, const std::string& t): code(c), text(t) {}
        float code;
        std::string text;
    };

    typedef unsigned int unsignedInt;
}

#endif
