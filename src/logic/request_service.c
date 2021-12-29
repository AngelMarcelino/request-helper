#include "request_service.h"
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <curl/curl.h>

static struct ReadData {
    GString *str;
    int pos;
};

typedef struct ReadData ReadData;

static ReadData* initialize_read_data(gchar *body) {
    ReadData *readData = (ReadData*) malloc(sizeof(ReadData));
    readData->pos = 0;
    readData->str = g_string_new(body);
    return readData;
}

static int writefunc(void* ptr, int size, int nmemb, GString* s)
{
    int incommingStringLength = size * nmemb;
    gchar* incommingStr = malloc(incommingStringLength + 1);
    memcpy(incommingStr, ptr, incommingStringLength);
    incommingStr[incommingStringLength + 1] = '\0';
    g_string_append(s, incommingStr);
    free(incommingStr);
    return size * nmemb;
}

static int readfunc(char *buffer, int size, int nitems, void *userdata) {
    ReadData *dataWithHeader = (ReadData*) userdata;
    int dataToRead = dataWithHeader->str->len - dataWithHeader->pos;
    if (dataToRead > size * nitems) {
        dataToRead = size * nitems;
    }
    g_print("Data: ");
    g_print(dataWithHeader->str->str);
    g_print("\n");
    g_print("Data dataToRead: ");
    g_print("%d", dataToRead);
    g_print("\n");
    g_print("size: ");
    g_print("%d", size);
    g_print("\n");
    g_print("nitems: ");
    g_print("%d", nitems);
    g_print("\n");
    g_print("dataWithHeader->str->len: ");
    g_print("%d", dataWithHeader->str->len);
    g_print("\n");
    g_print("dataWithHeader->pos: ");
    g_print("%d", dataWithHeader->pos);
    g_print("\n");

    memcpy(buffer, dataWithHeader->str->str, dataToRead);
    char nil = '\0';
    memcpy(buffer + dataToRead, &nil, 1);
    dataWithHeader->pos += dataToRead;
    return dataToRead;
}

GString* postman_app_get(gchar* uri) {
    GString* resultData = g_string_new("");
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, uri);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, resultData);
        res = curl_easy_perform(curl);
        g_print("%s\n", resultData->str);
        curl_easy_cleanup(curl);
    }
    return resultData;
}

GString* postman_app_post(gchar* uri, gchar* body) {
    GString* resultData = g_string_new("");
    ReadData* readData = initialize_read_data(body);
    CURL* curl;
    CURLcode res;
    struct curl_slist * list = NULL;
    list = curl_slist_append(list, "Content-Type: application/json");
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, uri);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, resultData);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, readfunc);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, readData);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, readData->str->len);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        res = curl_easy_perform(curl);
        g_print("%s\n", resultData->str);
        curl_easy_cleanup(curl);
    }
    return resultData;
}


