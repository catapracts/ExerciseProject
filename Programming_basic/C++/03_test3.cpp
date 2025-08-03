/*
1. 다음 프로그램의 출력 결과?

#include <iostream>

using namespace std;

int main() {
    char str[] = "Hello World!";

    cout << str << endl;
    cout << str* << endl;
}

내 답 : 
Hello World
H

정답 : 
Hello, World!
H


2. 빈칸 채우기 + 다음 프로그램의 출력 결과?
#include <iostream>

using namespace std;

int main() {
    int a = 10, b= 20, c = 30;
    int *p = ?a;
    int &r = ?b;
    int **pp = ?p;
    int* (&rp) = ?p;

    r = c / ?p;
    rp = ?c;
    ?pp = 40;
    ?p = 50;
    *pp = ?a;
    ?rp = 60;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << *p << endl;
    cout << r << endl;
    cout << **pp << endl;
    cout << *rp << endl;
}


내 답 : 
    int *p = &a;
    int &r = *b;
    int **pp = &p;
    int* (&rp) = *p;

    r = c / *p;
    rp = &c;
    &pp = 40;
    &p = 50;
    *pp = &a;
    &rp = 60;

    50
    3
    60
    50
    3
    50
    60



정답 : 
    int *p = &a;
    int &r = b;
    int **pp = &p;
    int* (&rp) = p;

    r = c / *p;
    rp = &c;
    **pp = 40;
    *p = 50;
    *pp = &a;
    *rp = 60;

    60
    3
    50
    60
    3
    60
    60

*/