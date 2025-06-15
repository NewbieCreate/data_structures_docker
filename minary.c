#include <stdio.h>

// 함수 선언: 배열과 길이 전달
double ary_min(double *ap, int n);

int main() {
    double ary[] = {1.5, 20.1, 16.4, 2.3, 3.5};
    int n = sizeof(ary) / sizeof(ary[0]);
    double res;

    res = ary_min(ary, n);
    printf("배열의 최소값 : %.1lf\n", res);

    return 0;
}

// 함수 정의
double ary_min(double *ap, int n) {
    double min = ap[0];
    for (int i = 1; i < n; i++) {
        if (ap[i] < min)
            min = ap[i];
    }
    return min;
}