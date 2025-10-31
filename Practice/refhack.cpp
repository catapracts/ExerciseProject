#include <iostream>

int data1 = 0;

int main() {
    // null 삽입. NULL = 0 입니다.
    int& b = *(int*)0;
    int* arr[0];
    
    // 참조 덮어쓰기 (debug에서만 됨)
    arr[0] = &data1;

    b = 10;
    std::cout << data1;

    return 0;
}