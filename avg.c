#include<stdio.h>

int main(){
    double ary[] = {1.5,20.1,16.4,2.3,3.5};
    int i;
    double temp = 0;
    for (i = 0; i < 5; i++){
        temp += *(ary + i);
    }
    printf("평균 시험점수는? : %.2lf", temp /= 5);
    int n = sizeof(ary) / sizeof(ary[0]);
    printf("ary의 길이는 ? : %d",n);
    return 0;
}