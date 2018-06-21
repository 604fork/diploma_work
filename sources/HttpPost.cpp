#include "headers/HttpPost.h"
#include "headers/WriteCallback.h"
#include <curl/curl.h>

namespace HttpPost
{
    std::string httpPost(std::string const &post_payload)
    {
        std::string readBuffer;
        CURL *curl;
        CURLcode res;
        /*Get a curl handle*/
        curl = curl_easy_init();
        /*Check on curl*/
        if (curl)
        {
            /* First set the URL that is about to receive our POST. This URL can
            just as well be a https:// URL if that is what should receive the
            data. */
            curl_easy_setopt(curl, CURLOPT_URL, SERVER_URL); //SERVER_URL pass in CMakeLists.txt
            /* Now specify the POST data */
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_payload.c_str());
            /*Set the callback function that write answer from server*/
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            /*Set string data buffer for writing response from the server*/
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            /* Perform the request, res will get the return code */
            res = curl_easy_perform(curl);
            /*Check for errors*/
            if (res != CURLE_OK) fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            /* always cleanup */
            curl_easy_cleanup(curl);
        }
        return readBuffer;
    }
}
