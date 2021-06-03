#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {

    size_t length;
    char *data;

}download_data;

int progress_callback(void *clientp, curl_off_t loadtotal, curl_off_t loadnow, curl_off_t ultotal, curl_off_t ulnow) {
    fprintf(stderr, "\rProgress: %011ld of %ld", loadnow, loadtotal);
    return 0;
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
  download_data *d = userdata;
  d->data = realloc(d->data, d->length + nmemb);
  memcpy(d->data + d->length, ptr, nmemb);
  d->length += nmemb;
  return nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl = curl_easy_init();

    if(argc == 0) {
        printf("you must enter a url");
    }

    else if(argc == 2) {
        if(curl) {
        CURLcode res;
        download_data datums = {0, 0};

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
        curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, progress_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &datums);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform failed: %s\n",
            curl_easy_strerror(res));
        else {
            /*printf("%s\n", datums.data);*/
        }

        curl_easy_cleanup(curl);

    }

    else {
        printf("you entered too many arguments");
    }

    }
    
}