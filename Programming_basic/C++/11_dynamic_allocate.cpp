/*
Program Performance advanced - time, space(memory)
동적할당 : 원할 때만 사용 / 프로그램 실행 중 원하는만큼 원하는 시기에 메모리 할당
정적할당 : int a; -> 함수 실행 시 생성
*/

#include <iostream>

using namespace std;

int main() {
    // 변수 동적할당
    // int a = int(5); // 동적할당의 기본 표현
    int *a = new int(5); // new = 연산자 / 주소값을 반환함, int저장할 공간 만들고 값 5넣은 다음 생성된 메모리의 주소값을 a에 저장 = a가 int를 가리킨다.
    cout << a << endl; // 주소값 출력
    cout << *a << endl; // 값 출력
    *a = 18;
    cout << a << endl; // 주소값 출력
    cout << *a << endl; // 값 출력
    delete a; // 할당했던 메모리 회수 -> 이거 안 하면 메모리 계속 상주함 = 메모리 낭비됨 / 안 써도 회수되긴 하는데 쓰는게 좋긴함

    // 배열의 동적 할당 -> 가장 많이 사용
    // &arr[0] = arr
    int *arr; // 배열 동적할당 + 0번째 주소가리키는 중
    int len;

    cout << "동적할당할 배열 길이 입력 : ";
    cin >> len;
    arr = new int[len]; // int형 배열을 len길이만큼 만드는데, 0번째 주소값 반환
    for(int i = 0; i < len; i++) {
        arr[i] = len - i;
    }
    for(int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }

    delete arr; // 이렇게 쓰면 arr[0]만 회수됨
    delete[] arr; // 이렇게 해야 배열 전체 메모리가 회수됨

    // class 동적할당
    Vector2 s1; // Vector2 s1 = Vector2();
    Vector2 s2 = Vector2(3, 2);

    Vector2 *d1 = new Vector2();
    Vector2 *d2 = new Vector2(3, 6);

    cout << "(" << d1 -> GetX() << ", " << d1 -> GetY() << ")" << endl;
    cout << "(" << d2 -> GetX() << ", " << d2 -> GetY() << ")" << endl;

    // 생성은 순서대로 되는데, 회수는 동적할당 먼저 회수됨
    delete d1;
    delete d2;
}

class Vector2 {
    public:
        Vector2() : x(0), y(0) {
            cout << this << " : Vector2()" << endl;
        }
        Vector2(const float x, const float y) : x(x), y(y) {
            cout << this << " : Vector2(const float x, const float y)" << endl;
        }
        ~Vector2() {
            cout << this << " : Vector2()" << endl;
        }

        float GetX() const { return x; }
        float GetY() const { return y; }

    private:
        float x;
        float y;
};
