#include <gtk/gtk.h>
// �������ں����
GtkWidget* window;
GtkWidget* button_1;
// ������ť��������ʡ��
// ��ť����¼�
void button_click(GtkWidget* widget, gpointer data) {
    const gchar* text = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar* current = gtk_entry_get_text(GTK_ENTRY(entry));
    gchar* new_text = g_strconcat(current, text, NULL);
    gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    g_free(new_text);
}
// �����ť����¼�
void button_clear(GtkWidget* widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}
// ���㰴ť����¼�
void button_calculate(GtkWidget* widget, gpointer data) {
    const gchar* expression = gtk_entry_get_text(GTK_ENTRY(entry));
    // ���м��㣬���������ʾ���ı�����
}
int main(int argc, char* argv[]) {
    // ��ʼ��GTK��
    // ��������
    // �����ı���
    // ������ť
    // ������ť�Ĵ������¼��󶨣�ʡ��
    // ��ʾ���ں����
    // ����GTK��ѭ��
    gtk_main();
}