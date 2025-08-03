/*
namespace -> 함수나 변수의 이름 중복 방지
namespace안에서 변수 선언하면, 다른 곳에서 왔다는 명시가 없는 이상 해당 namespace안에 있는 변수로 처리
namespace 내용물 분리가능
중첩가능
식별자검색 - 가장 우선순위 : 선언 위치
using namespace -> 전역변수처럼 사용 가능 / 아무데서나 선언 가능 대신 어떤 범위 안에 넣으면 해당 범위 안에서만 사용가능
*/

#include <iostream>

using namespace std;

int n;
void set() {
    ::n = 10; // 명시적 전역변수 - 전역변수임을 알림
}

namespace one {
    int n;
    void set(){
        //one::n = 20;
        n = 20;
    }
}

namespace two {
    int n;
    void set() {
        //two::n = 30;
        n = 30;
    }
}

namespace three {
    int n;
    void set();
}


namespace four {
    int n;
    void set();

    namespace five {
        int n;
        void set();
        // int n -> 이게 위 말고 여기에 위치할 경우 five::n이 60이 아니라 50이 된다. 그런데 따로 함수 빼서 구현시키면 여기에 배치해도 정상 출력된다. = 식별자검색 - 가장 우선순위 : 선언 위치
        // 상위 namespace도 int n이 코드 맨 아래에 위치할 경우 ::n에 값을 넣어서 출력 (ex) ::n = 10인데, four::n의 값을 받아서, ::n=40이 출력된다.
    }
}

int main() {
    using namespace std;
    using namespace one;
    ::set();
    // set(); -> 이렇게 namespace가 특정 범위안에 존재하면, 전역에 있는 애랑 namespace에 있는 애랑 이름 같으면 생략 불가능, 근데 namespace안에 있는 또 다른 namespace는 생략가능 
    one::set();
    two::set();
    three::set();
    four::set();
    four::five::set();
    cout << ::n <<endl; // 10
    cout << one::n <<endl; // 20
    cout << two::n <<endl; // 30
    cout << three::n <<endl; // 40
    cout << four::n <<endl; // 50
    cout << four::five::n <<endl; // 60


}

// namespace three {
//     void set() {
//         n = 40;
//     }
// }

//위 함수랑 같은 형식
void three :: set() {
    n = 40;
}

void four ::set() {
    n = 50;
}

void four::five::set() {
    n = 60;
}