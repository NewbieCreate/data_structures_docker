#include <stdio.h>

int main() {
    char ch;
    int in;
    double db;

    printf("Ch의 포인터 : %u \n", &ch);
    printf("in의 포인터 : %u \n", &in);
    printf("db의 포인터 : %u \n", &db);

    *&ch = 'P';   //포인터 &ch가 가리키는 기억공간에 P를 저장한다.
    *&in = 100;   // 포인터 &in 을 가리키는 기억공간에 100을 저장한다.
    *&db = 3.14;   // 포인터 &db가 가리키는 기억공간에 3.14를 저장한다.
    
    printf("변수 ch에 저장된 문자 : %c \n", ch);
    printf("변수 in에 저장된 문자 : %d \n", in);
    printf("변수 db에 저장된 문자 : %lf \n", db);

    int a = 100, b = 0;
    b = *&a;
    printf("b의 값 : %d \n", b);

    

    return 0;
}