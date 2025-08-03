/*
상수형 매개변수, method

const
1. 매개변수의 상수화(모든 함수)
2. method의 상수화(member method 한정)

*/

#include <iostream>

using namespace std;

// 은행계좌 프로그래밍
class Account {
public:
    Account() : money(0) {}
    Account(int money) : money(money) {}

    // 입금
    // 매개 변수의 상수화
    // 코드 길어질 때, 바뀌면 안 되는 변수가 바뀌는 실수 방지 가능
    void Deposit(const int d) {
        money += d;
        cout << d << "원 예금 완료" << endl;
    }

    void Draw(int d) {
        if(money >= d){
            money -= d;
            cout << d << "원 출금 완료" << endl;
        }        
    }

    // 잔액 확인
    // method 상수화 - 자기가 속한 class의 다른 member varable들을 건드리지 못 하게 막는것
    // 잔액 확인만 하면 되는데 잔액을 control하면 안 되니까
    // const가 맨 앞에 있을 경우 상수형 method가 아니라 return type이 const가 되는 것 => 애초에 return값 자체가 const라서...
    int ViewMoney() const { 
        return money;
    }

private:
    int money; // 잔액
};


int main() {
    Account a(100);
    a.Deposit(100);
    a.Draw(20);
    cout << a.ViewMoney() << endl;
}