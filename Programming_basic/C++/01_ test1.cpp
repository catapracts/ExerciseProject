/*
1. 이름, 정수 입력받고, 다음과 같이 출력
이름 입력 : XXX
점수 입력 : YYY
XXX님의 점수는 YYY입니다.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // string name;
    // int score;
    // cout << "이름 입력 : ";
    // cin >> name;
    // cout << endl;
    // cout << "점수 입력 : ";
    // cin >> score;
    // cout << endl;
    // cout << name << "님의 점수는" << score << "입니다." << endl;
    
    string name;
    int score;
    cout << "이름 입력 : ";
    cin >> name;
    
    cout << "점수 입력 : ";
    cin >> score;
    
    cout << name << "님의 점수는" << score << "입니다." << endl;




    /*
        2. 범위기반 for문 이용하여 2차원 배열 출력
        int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    */
   int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
   
//    for(int n : arr) {
//     for(int o : arr) {
//         cout << arr[n][o] << endl;
//         o++;
//     }
//     n++;
//    }

    // 배열포인터를 사용하여 2차원 배열 출력, reference변수 사용
    for(int(&ln)[3] : arr) {
        for(int &col : ln){
            cout << col << ' ';
        }
        cout << endl;
    }

    /*
    위 함수랑 같은 동작
    for(int(*ln)[3] = arr; ln < arr + 2; ln++) {
        for(int *c = *ln; c < *ln + 3; c++){
            cout << *c << ' ';
        }
        cout << endl;
    }
    
    */

    for(auto &ln : arr) {
        for(auto &col : ln){
            cout << col << ' ';
        }
        cout << endl;
    }

}



/*
3. 아래 함수에서 오류가 나는 이유

void drawRectangle(int i, int r, int t, int b) {
}

void drawRectangle(int x = 0, int y = 0, int w, int h) { // -> 오류 발상
}

답 : default매개변수는 오른쪽에서부터 써야하기 때문

정답
1. default매개변수는 오른쪽에서 시작
2. 매개변수의 갯수가 똑같아서 구분이 안 됨

*/