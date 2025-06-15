#include <stdio.h>

int main() {
    double ary[] = {1.5, 20.1, 16.4, 2.3, 3.5};
    int n = sizeof(ary) / sizeof(ary[0]);
    double *ap = ary + 4;
    
    for(int i = 0; i < 5; i++){
        printf("%.1lf\n", *ap);
        ap --;
    }
    return 0;
}