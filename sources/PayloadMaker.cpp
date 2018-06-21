#include "headers/PayloadMaker.h"
#include "headers/MyTypes.h"
#include "headers/ToString.h"

std::string PayloadMaker::compositeFunction(std::string function_name, MyTypes::CompositeType compositeType,
                                            MyTypes::unsignedInt unsignedInt)
{
    std::string composite_type = std::to_string(compositeType.type);
    std::string unsigned_char = std::to_string(compositeType.unsignedChar);
    std::string unsigned_int = std::to_string(unsignedInt);
    std::string payload = "function_name=" + function_name + "&" +
                          "composite_type=" + composite_type + "&"
                          + "unsigned_char=" + unsigned_char + "&"
                          + "unsigned_int=" + unsigned_int;
    return payload;
}

std::string PayloadMaker::floatFunction(std::string function_name, float floatType)
{
    std::string float_type = std::to_string(floatType);
    std::string payload = "function_name=" + function_name + "&" + "float_type=" + float_type;
    return payload;
}