#include <stdio.h>

// �������ݽṹ
struct Student {
    int ChineseScore;
    int MathScore;
    int ScienceScore;
    int SubjectInterest;
    int SubjectAbility;
    int HomeworkScore;
};
// ����������ڵ�
struct TreeNode {
    int featureIndex;
    double threshold;
    int leftChild;
    int rightChild;
    int classLabel;
};
// ���������ģ��
struct DecisionTreeModel {
    struct TreeNode nodes[/* ���ڵ����� */];
};
// ���庯������Ԥ����ҵ�Ѷ�
int predictDifficulty(struct DecisionTreeModel model, struct Student student) {
    int currentNode = 0;
    while (model.nodes[currentNode].classLabel == -1) {
        int featureIndex = model.nodes[currentNode].featureIndex;
        double threshold = model.nodes[currentNode].threshold;
        if (student.featureIndex[featureIndex] <= threshold) {
            currentNode = model.nodes[currentNode].leftChild;
        }
        else {
            currentNode = model.nodes[currentNode].rightChild;
        }
    }
    return model.nodes[currentNode].classLabel;
}
int main() {
    // �����µ�ѧ����Ϣ
    struct Student student1 = { 95, 60, 65, 0, 1, 70 };
    struct Student student2 = { 60, 95, 80, 1, 2, 80 };

    // ����������ģ��
    struct DecisionTreeModel model = {
        // �������ڵ���Ϣ
    };

    // ģ��Ԥ����ʺϵ���ҵ�Ѷ�
    int predictedDifficulty1 = predictDifficulty(model, student1);
    int predictedDifficulty2 = predictDifficulty(model, student2);

    // ���Ԥ����
    printf("��ѧ��1: ����=%d, ��ѧ=%d, ��ѧ=%d, ��Ȥ=%d, ����=%d, ��ҵ=%d\n", student1.ChineseScore, student1.MathScore, student1.ScienceScore, student1.SubjectInterest, student1.SubjectAbility, student1.HomeworkScore);
    printf("Ԥ����ҵ�Ѷ�: %d\n", predictedDifficulty1);

    printf("��ѧ��2: ����=%d, ��ѧ=%d, ��ѧ=%d, ��Ȥ=%d, ����=%d, ��ҵ=%d\n", student2.ChineseScore, student2.MathScore, student2.ScienceScore, student2.SubjectInterest, student2.SubjectAbility, student2.HomeworkScore);
    printf("Ԥ����ҵ�Ѷ�: %d\n", predictedDifficulty2);

    return 0;
}