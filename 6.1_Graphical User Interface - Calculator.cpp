#include <gtk/gtk.h>
// 声明窗口和组件
GtkWidget* window;
GtkWidget* button_1;
// 其他按钮的声明，省略
// 按钮点击事件
void button_click(GtkWidget* widget, gpointer data) {
    const gchar* text = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar* current = gtk_entry_get_text(GTK_ENTRY(entry));
    gchar* new_text = g_strconcat(current, text, NULL);
    gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    g_free(new_text);
}
// 清除按钮点击事件
void button_clear(GtkWidget* widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}
// 计算按钮点击事件
void button_calculate(GtkWidget* widget, gpointer data) {
    const gchar* expression = gtk_entry_get_text(GTK_ENTRY(entry));
    // 进行计算，并将结果显示在文本框中
}
int main(int argc, char* argv[]) {
    // 初始化GTK库
    // 创建窗口
    // 创建文本框
    // 创建按钮
    // 其他按钮的创建和事件绑定，省略
    // 显示窗口和组件
    // 运行GTK主循环
    gtk_main();
}