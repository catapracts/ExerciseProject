/*
대입 연산자 오버로딩
*/


#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
    String() {
        cout << "String() 생성자 호출됨" << endl;
        strData = NULL;
        len = 0;
    }
    String(const char *str) {
        cout << "String(const char*) 생성자 호출됨" << endl;
        len = strlen(str);
        strData = new char[len + 1];
        cout << "strData 할당 : " << (void*)strData << endl;
        strcpy(strData, str);
    }
    ~String() {
        cout << "String() 소멸자 호출됨" << endl;
        delete[] strData;
        cout << "strData 해제됨 : " << (void*)strData << endl;
        strData = NULL;
    }

    String(const String &rhs) {
        cout << "String(const String &rhs) 생성자 호출됨" << endl;
        strData = new char[rhs.len + 1];
        cout << "strData 할당 : " << (void*)strData << endl;
        strcpy(strData, rhs.strData);
        len = rhs.len;
    }

    /*
        매개변수로 객체로 들어갈 경우 -> 복사생성자 진행되서 또 다른 객체가 생성되는 비효율 발생(이 클래스내 객체랑 main의 객체는 다른 거니까)
        그래서 &(reference변수)붙여서 사용하면 참조값만 가져오니까 복사생성자 나오는 과정을 줄일 수 있음
        아니면 처음부터 reference
        return하면 임시 객체 형성해서 반환되거든? = 객체 생성 과정 1번 더 거침
        그래서 return 타입도 &붙임
        strData가 NULL이면? -> delete연산자가 자동으로 아무 작동 안함
    */ 
    String &operator=(const String &rhs){
        if(this != &rhs) {// 자기 자신 할당하는 걸 방지하기 위해 추가 -> 매개변수로 받은 객체의 주소값이랑, 현재 객체의 주소값이랑 똑같나? = 내가 나를 복사하나?
            delete[] strData; // 원래 가진 메모리를 먼저 해제하고
            strData = new char[rhs.len + 1]; // 새롭게 할당
            cout << "strData 할당 : " << (void*)strData << endl;
            strcpy(strData, rhs.strData);
            len = rhs.len;
        }
        return *this; // 함수 실행당시 해당 함수에 속해있는 객체의 주소값 = this / 똑같으면 그냥 그대로 가
    }
    
    char *GetStrData() const {
        return strData;
    }

    int GetLen() const {
        return len;
    }

private:
    char *strData;
    int len;
};

int main(){
    String s1("Hello");
    String s2(s1);
    
    // 대입 연산자 - 선 객체 생성 후 객체 복사 => 연산자 오버로딩 사용해야함(연산자를 맴버변수인 것처럼 취급)
    String s3;
    //s3 = s1; // 이러면 에러남
    s3.operator=(s1); // =(연산자)를 재정의, 오버로딩하기
    s3.operator=(s3); // 이런 경우는 어떻게 할거냐? - 자기 자신을 할당하는 경우는? -> 실행은 되는데 쓰레기값들어감

    /*
    int a = 5, b, c=b=a;
    => =는 오른쪽에서부터 계산 시작, 반환 : 값 = return, 반환 타입은 자기자신
    String s4;
    s4 = s3 = s1;
    */

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
    cout << s3.GetStrData() << endl;
}