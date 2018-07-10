#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    CURLcode ret;
    
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "0.0.0.0");
        curl_easy_setopt(curl, CURLOPT_PORT, 5000L);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        ret = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return 0;
}
