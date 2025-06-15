#include<stdio.h>

void line_up(double *, double *, double *);
void exchange(double *, double *);

int main() {
    double max, mid, min;
    printf("숫자 세개를 입력하세요 :");
    scanf("%lf%lf%lf", &max, &mid, &min);
    line_up(&max, &mid, &min);
    printf("큰수부터 차례대로 출력하면 : %lf, %lf, %lf\n", max, mid, min);

    return 0;
}

void line_up(double *mp, double *ip, double *np){
    if(*mp < * ip)  exchange(mp, ip);
    if(*mp < *np) exchange(mp, np);
    if(*ip < *np) exchange(ip, np);
}

void exchange(double *xp, double *yp) {
    double temp;
    
    temp = *yp;
    *yp = *xp;
    *xp = temp;
}