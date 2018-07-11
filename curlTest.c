#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    CURLcode ret;
    
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://127.0.0.1");
        curl_easy_setopt(curl, CURLOPT_PORT, 1337L);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_SSLCERTTYPE, "PEM");
        curl_easy_setopt(curl, CURLOPT_SSLCERT, "openssl/cert.pem");
        curl_easy_setopt(curl, CURLOPT_SSLKEY, "openssl/key.pem");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        
        ret = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return 0;
}
