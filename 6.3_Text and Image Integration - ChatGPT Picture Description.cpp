#include <stdio.h>
#define API_KEY "YOUR_API_KEY"
// 构建请求的URL
void build_url(char* url, const char* image_path) {
    char endpoint[] = "https://api.deepai.org/api/text-generator";
    sprintf(url, "%s?image=%s", endpoint, image_path);
}
// 处理API响应
void handle_response(char* response) {
    // 提取生成的文本描述
    const char* keyword = "\"output\":";
    char* description = strstr(response, keyword);
    if (description) {
        description += strlen(keyword);
        description[strcspn(description, "\"")] = '\0';  // 移除描述中的引号
        printf("Description: %s\n", description);
    }
    else {
        printf("Failed to extract description from API response.\n");
    }
}
// 发送API请求并获取响应
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