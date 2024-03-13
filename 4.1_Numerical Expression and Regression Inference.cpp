
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义线性回归结构体
typedef struct {
    double slope;      // 斜率
    double intercept;   // 截距
} LinearRegression;

// 定义函数计算皮尔逊相关系数
double pearson_correlation(int n, double x[], double y[]) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0, sum_y_squared = 0;

    for (int i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
        sum_y_squared += y[i] * y[i];
    }

    double numerator = n * sum_xy - sum_x * sum_y;
    double denominator = sqrt((n * sum_x_squared - sum_x * sum_x) * (n * sum_y_squared - sum_y * sum_y));

    return numerator / denominator;
}

int main() {
    // 创建数据集
    int n = 10;
    double heights[] = { 155, 160, 150, 165, 175, 152, 158, 162, 168, 170 };
    double weights[] = { 45, 50, 42, 55, 60, 48, 52, 56, 58, 59 };
    // 计算斜率和截距
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;
    for (int i = 0; i < n; ++i) {
        sum_x += heights[i];
        sum_y += weights[i];
        sum_xy += heights[i] * weights[i];
        sum_x_squared += heights[i] * heights[i];
    }
    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / n;
    // 输出斜率和截距
    printf("斜率: %lf\n", slope);
    printf("截距: %lf\n", intercept);
    // 计算皮尔逊相关系数
    double correlation = pearson_correlation(n, heights, weights);
    printf("皮尔逊相关系数: %lf\n", correlation);
    // 新的身高数据
    double new_heights[] = { 173, 178 };
    int num_new_heights = sizeof(new_heights) / sizeof(new_heights[0]);
    // 计算预测值
    for (int i = 0; i < num_new_heights; ++i) {
        double predicted_weight = slope * new_heights[i] + intercept;
        printf("新的身高数据: %lf, 预测的体重为: %lf\n", new_heights[i], predicted_weight);
    }
    return 0;
}