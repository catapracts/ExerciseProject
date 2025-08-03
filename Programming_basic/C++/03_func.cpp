#include <iostream>

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

// 서로 가리키는 주솟값 바꾸기
void swap(int* (&a), int* (&b)){  //int*(&a) = a라는 변수는 reference 변수인데, int형 pointer를 가리키는 변수다.
    int *tmp = a; // a에 저장된 주소값을 tmp에 저장
    a = b;
    b = tmp;
}

/*
함수 이름 같고 매개 변수 다르게 함 - 오버로딩
*/

int main() {
    int a = 10, b= 20;
    swap(a,b);

    double c = 2.22222, d = 3.33333;
    swap(c, d);

    int *e = &a, *f = &b;
    swap(e, f);

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "*e : " << *e << std::endl; // 값 출력됨
    std::cout << "*f : " << *f << std::endl; // 값 출력됨



}