#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义数据结构
struct Student {
    double studyTime;
    double participation;
    double averageGrade;
    int interest;
};
// 定义学习小组信息结构
struct StudyGroup {
    double centerStudyTime;
    double centerAverageGrade;
    int label;
};
// 计算两点之间的欧氏距离
double euclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
// K均值聚类函数
void kmeans(struct Student students[], int numStudents, struct StudyGroup groups[], int numGroups) {
    // 初始化学习小组的中心
    for (int i = 0; i < numGroups; ++i) {
        groups[i].centerStudyTime = students[i].studyTime;
        groups[i].centerAverageGrade = students[i].averageGrade;
        groups[i].label = i;
    }
    // 最大迭代次数
    int maxIterations = 100;
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // 分配学生到最近的学习小组
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

        // 更新学习小组的中心
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
    // 定义学生信息
    struct Student students[] = {
        {6, 85, 80, 8},
        {8, 70, 75, 6},
        // ... (其他学生信息)
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    // 定义学习小组信息
    struct StudyGroup groups[4];

    // 调用K均值聚类函数
    kmeans(students, numStudents, groups, 4);

    // 输出聚类结果
    for (int i = 0; i < numStudents; ++i) {
        printf("学生 %d 分配到学习小组 %d\n", i + 1, students[i].interest + 1);
    }

    return 0;
}