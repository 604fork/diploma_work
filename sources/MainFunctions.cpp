#include "headers/MainFunctions.h"
#include "headers/PayloadMaker.h"
#define COMPOSITE_FUNCTION
#define FLOAT_FUNCTION

namespace MainFunctions
{

    MyTypes::AnswerMessage compositeFunction(MyTypes::CompositeType compositeType, MyTypes::unsignedInt unsignedInt)
    {
        const std::string function_name = "compositeFunction";
        std::string payload = PayloadMaker::compositeFunction(function_name, compositeType, unsignedInt);
#ifdef COMPOSITE_FUNCTION
        std::cout << "Http payload: " << payload << std::endl;
#endif
        std::string response = HttpPost::httpPost(payload);
#ifdef COMPOSITE_FUNCTION
        std::cout << "Http response: " << response << std::endl;
#endif
        rapidjson::Document document;
        document.Parse(response.c_str());
        MyTypes::AnswerMessage res;
        try
        {
            if (!document.IsObject()) throw "JSON is not valid";
            if (!document.HasMember("code")) throw "JSON don't has the code!";
            if (!document["code"].IsInt()) throw "JSON code is not int!";
            if (!document.HasMember("string")) throw "JSON don't has the string!";
            if (!document["string"].IsString()) throw "JSON string is not string!";
            float code = document["code"].GetInt();
            std::string string = document["string"].GetString();
            res = {code, string};
        }
        catch (char const *error)
        {
            std::cerr << error << std::endl;
            res = {-1, "Error"};
        }
        return res;
    }

    MyTypes::AnswerMessage floatFunction(float floatType)
    {
        const std::string function_name = "floatFunction";
        std::string float_type = std::to_string(floatType);
        std::string payload = PayloadMaker::floatFunction(function_name, floatType);
#ifdef FLOAT_FUNCTION
        std::cout << "Http payload: " << payload << std::endl;
#endif
        std::string response = HttpPost::httpPost(payload);
#ifdef FLOAT_FUNCTION
        std::cout << "Http response: " << response << std::endl;
#endif
        rapidjson::Document document;
        document.Parse(response.c_str());
        MyTypes::AnswerMessage res;
        try
        {
            if (!document.IsObject()) throw "JSON is not valid";
            if (!document.HasMember("floatValue")) throw "JSON don't has the floatValue!";
            if (!document["floatValue"].IsDouble()) throw "JSON code is not float!";
            if (!document.HasMember("string")) throw "JSON don't has the string!";
            if (!document["string"].IsString()) throw "JSON string is not string!";
            float code = document["floatValue"].GetDouble();
            std::string string = document["string"].GetString();
            res = {code, string};
        }
        catch (char const *error)
        {
            std::cerr << error << std::endl;
            res = {-1, "Error"};
        }
        return res;
    }
}