#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �������ݽṹ
struct Student {
    double studyTime;
    double participation;
    double averageGrade;
    int interest;
};
// ����ѧϰС����Ϣ�ṹ
struct StudyGroup {
    double centerStudyTime;
    double centerAverageGrade;
    int label;
};
// ��������֮���ŷ�Ͼ���
double euclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
// K��ֵ���ຯ��
void kmeans(struct Student students[], int numStudents, struct StudyGroup groups[], int numGroups) {
    // ��ʼ��ѧϰС�������
    for (int i = 0; i < numGroups; ++i) {
        groups[i].centerStudyTime = students[i].studyTime;
        groups[i].centerAverageGrade = students[i].averageGrade;
        groups[i].label = i;
    }
    // ����������
    int maxIterations = 100;
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // ����ѧ���������ѧϰС��
        for (int i = 0; i < numStudents; ++i) {
            double minDistance = euclideanDistance(students[i].studyTime, students[i].averageGrade, groups[0].centerStudyTime, groups[0].centerAverageGrade);
            students[i].interest = groups[0].label;

            for (int j = 1; j < numGroups; ++j) {
                double distance = euclideanDistance(students[i].studyTime, students[i].averageGrade, groups[j].centerStudyTime, groups[j].centerAverageGrade);
                if (distance < minDistance) {
                    minDistance = distance;
                    students[i].interest = groups[j].label;
                }
            }
        }

        // ����ѧϰС�������
        int count[numGroups];
        for (int i = 0; i < numGroups; ++i) {
            groups[i].centerStudyTime = 0;
            groups[i].centerAverageGrade = 0;
            count[i] = 0;
        }

        for (int i = 0; i < numStudents; ++i) {
            int groupIndex = students[i].interest;
            groups[groupIndex].centerStudyTime += students[i].studyTime;
            groups[groupIndex].centerAverageGrade += students[i].averageGrade;
            count[groupIndex]++;
        }
        for (int i = 0; i < numGroups; ++i) {
            if (count[i] > 0) {
                groups[i].centerStudyTime /= count[i];
                groups[i].centerAverageGrade /= count[i];
            }
        }
    }
}

int main() {
    // ����ѧ����Ϣ
    struct Student students[] = {
        {6, 85, 80, 8},
        {8, 70, 75, 6},
        // ... (����ѧ����Ϣ)
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    // ����ѧϰС����Ϣ
    struct StudyGroup groups[4];

    // ����K��ֵ���ຯ��
    kmeans(students, numStudents, groups, 4);

    // ���������
    for (int i = 0; i < numStudents; ++i) {
        printf("ѧ�� %d ���䵽ѧϰС�� %d\n", i + 1, students[i].interest + 1);
    }

    return 0;
}