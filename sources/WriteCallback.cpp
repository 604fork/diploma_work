#include "headers/WriteCallback.h"

namespace HttpPost
{
    size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *readBuffer)
    {
        size_t realsize = size * nmemb;
        ((std::string *) readBuffer)->append(contents, realsize);
        return realsize;
    }
}
