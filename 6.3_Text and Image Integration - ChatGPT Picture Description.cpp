#include <stdio.h>
#define API_KEY "YOUR_API_KEY"
// ���������URL
void build_url(char* url, const char* image_path) {
    char endpoint[] = "https://api.deepai.org/api/text-generator";
    sprintf(url, "%s?image=%s", endpoint, image_path);
}
// ����API��Ӧ
void handle_response(char* response) {
    // ��ȡ���ɵ��ı�����
    const char* keyword = "\"output\":";
    char* description = strstr(response, keyword);
    if (description) {
        description += strlen(keyword);
        description[strcspn(description, "\"")] = '\0';  // �Ƴ������е�����
        printf("Description: %s\n", description);
    }
    else {
        printf("Failed to extract description from API response.\n");
    }
}
// ����API���󲢻�ȡ��Ӧ
size_t curl_write_callback(char* data, size_t size, size_t nmemb, char* response) {
    size_t response_length = size * nmemb;
    memcpy(response, data, response_length);
    return response_length;
}
int main() {
    char image_path[100];
    char url[200];
    char response[100000];
    printf("Enter image path (or 'quit' to exit): ");
    fgets(image_path, sizeof(image_path), stdin);
    curl_post_request(url, response);
    handle_response(response);
}