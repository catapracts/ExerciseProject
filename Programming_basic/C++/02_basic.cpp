#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


int main(){
    int a(10); // int a = 10;
    int b(a); // a(5) 이렇게만 쓰면 오류남
    int c(a+5);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    // 범위기반 for문
    int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // for(int i = 0; i < 10; i++){
    //     cout << arr[i] << endl;
    // }
    // for (int n : arr) {
    //     cout << n << endl;
    // }

    for (int n : arr) {
        cout << n << ' ';
        n++;
    }
    cout << endl;

    for (int n : arr) {
        cout << n << ' ';
    }
    cout << endl;

    for (int &n : arr) {
        cout << n << ' ';
        n++;
    }
    cout << endl;

    for (int n : arr) {
        cout << n << ' ';
    }
    cout << endl;


    int d(5);
    int &p = d;
    p = 10;

    cout << p << endl; // 10
    cout << d << endl; // 10

    int e(5), f(7);
    swap(e, f);
    cout << "e = " << e << endl;
    cout << "f = " << f << endl;

    // r-value
    int g(5);
    int &r1 = g;
    int &&r2 = 3;
    int &&r3 = g * g; // 함숫값도 수정할 수 없는 값이므로 r-value로 참조 가능


}