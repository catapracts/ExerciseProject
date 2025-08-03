// 이동시맨틱 - 깊은 복사의 단점을 해결하기 위해 얕은 복사 수행하기
/*
깊은 복사 단점 : 어떤 객체 복사할때마다 새로 할당 하면서 원본객체 데이터를 하나씩 복사 = 객체 크기가 클수록 복사 수행 횟수 증가

*/

#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
    String() {
        cout << "String() : " << endl;
        strData = NULL;
        len = 0;
    }
    String(const char *str) {
        cout << "String(const char*) : " << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }
    //복사 생성자
    String(const String &rhs) {
        cout << "String(const String &rhs) :" << endl;
        len = rhs.len;
        alloc(len);
        strcpy(strData, rhs.strData);
    }
    ~String() {
        cout << "~String() : " << endl;
        release();
        strData = NULL;
    }
    // 복사 대입연산자
    String &operator=(const String &rhs){
        cout << "String &operator=(const String &rhs) : " << endl;
        if(this != &rhs) {
            release();
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);
        }
        return *this;
    }
    
    char *GetStrData() const {
        return strData;
    }

    int GetLen() const {
        return len;
    }
    void SetStrData(const char *str){
        cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }

private:
    void alloc(int len) {
        strData = new char[len + 1];
        cout << "strData allocated : " << (void*)strData << endl;
    }
    void release() {
        delete[] strData;
        if (strData) cout << "strData released : " << (void*)strData << endl;
    }
    char *strData;
    int len;
};

String getName() {
    cout << "==== 2 ====" << endl;
    String res("F-22"); // 이 사이에 코드 엄청 많다고 가정
    cout << "==== 3 ====" << endl;
    return res;
}


int main(){
    String a;
    cout << "==== 1 ====" << endl;
    a = getName(); // 상식적으로 깊은 복사는 1번만 일어나야 함 - 복사생성자 호출한 것도 아니고 대입연산자도 오버로딩해놨는데?
    // 실제 실행하면 복사 생성자 호출됨 -> 어디에서? 3이랑 4 사이 = return res 지나서 a = 되는 순간 발생 왜? -> 임시객체
    /*
        getName에서 return res하는 순간 res가 사라지므로 임시객체에 res 복사하고 그걸 a에 복사하고 임시객체 사라짐
        = 깊은복사 총 2번 발생
        지금 필요한건 저 a 객체 1개뿐인데 새로운 객체를 2개나 만들필요가 있나? 어차피 사라지니까 메모리낭비지?
        그러니까 복사생성자 말고 다른 생성자 사용해서 얕은복사만 하자 그리고 정의한 복사대입연산자 말고 얕은복사로 가자
        근데 얕은 복사하면 소멸자 2번 해제되거든? 무조건 1번만 호출하도록 설정해야함
        얕은 복사를 위해 C++에서 지원하는 기능 - 이동시맨틱
        이동시맨틱 기능 : move = 가리키는 주체만 바꿔서 마치 데이터가 이동하는 것처럼 보임, r-value필요
        r-value = 등호의 우변에만 있어야 하는 값들 (ex) 임시객체
        l-value = 등호의 좌변에만 있어야 하는 값들 / 메모리상 저장되어있는 값들
        (ex)
        int a = 5;
        5 = a; => 5는 우변만 가능
        a = 5; => a는 좌, 우 둘 다 가능
        a + 3 = 5;
        int f() {return 5;} f() = 1; -> 오류 / 임시객체에 어떤 값을 대입할 수 없으므로 ㅁ8임시객체는 r-value다.
        복사대입연산자 호출 중 = r-value를 매개변수로 갖는 연산자를 호출하면 되겠네
    */
    cout << "==== 4 ====" << endl;

    String &&r = getName(); // r-value참조자, 임시객체 return
}