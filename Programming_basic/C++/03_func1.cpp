#include <iostream>

using namespace std;

int inventory[64] = {0};
int score = 0;

// void getItem(int itemId) {
//     inventory[itemId]++;
// }

// void getItem(int itemId, int cnt) { //overload
//     inventory[itemId] += cnt;
// }


/*
default 매개변수 - 아무 값도 안 넣었을 때, 자동으로 넣는 값
default 매개변수는 오른쪽에서부터 배치 시작하기로 약속
*/

void getItem(int itemId, int cnt = 1, int sc = 0) {
    inventory[itemId] += cnt;
    score += sc;
}

int main() {
    getItem(6, 5);
    getItem(3, 2);
    getItem(3);
    getItem(11, 34, 7000);

    cout << score << endl;
    for(int i = 0; i < 16; i++){
        cout << inventory[i] << ' ';
    }
    cout << endl;

}

