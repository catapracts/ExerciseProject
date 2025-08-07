#include<iostream>


using namespace std;

struct Calculator {

public:
    int Add(int a, int b) {
        int z = a + b;
        cout << a << " + " << b << " = " << z << endl;
        return z;
    }

    int Subtract(int a, int b) {
        int z = a - b;
        cout << a << " - " << b << " = " << z << endl;
        return z;
    }

    double Product(double a, double b) {
        double z = a * b;
        cout << a << " * " << b << " = " << z << endl;
        return z;
    }

    double Divide(double a, double b) {
        if( b == 0){
            cout << "Cannot divide by zero" << endl;
            return 0;
        }
        double z = a / b;
        cout << a << " / " << b << " = " << z << endl;
        return z;
    }

    // // 문자열이 정수로 변환 가능한지 확인하는 함수
    // bool isInteger(const string& s) {
    //     if (s.empty()) return false;

    //     // 첫 문자가 음수 부호일 수 있으므로 확인
    //     size_t start = 0;
    //     if (s[0] == '-') start = 1;

    //     for (size_t i = start; i < s.length(); ++i) {
    //         if (!isdigit(s[i])) {
    //         return false;
    //         }
    //     }

    //     return true;
    // }
};

int main() {

    Calculator cal;
    int a, b, number;
    double c, d;

    while(1) {
        cout << "Calculator activated!" << endl;
        cout << "choose menu with press number" << endl;
        cout << "==============================" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Product" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Quit" << endl;
        cout << "==============================" << endl;

        cout << "Enter the Number : ";
        cin >> number;

        switch(number) {
            case 1:
                cout << "Start Add Function" << endl;
                cout << "Input two Integer : ";
                if(!(cin >> a >> b)) {
                    cout << "Your input is wrong!" << endl;
                    cout << "Please try again" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                };
                cal.Add(a, b);
                cout << "End Add Function" << endl;
                cout << "" << endl;
                break;

            case 2:
                cout << "Start Subtract Function" << endl;
                cout << "Input two Integer : " << endl;
                if(!(cin >> a >> b)) {
                    cout << "Your input is wrong!" << endl;
                    cout << "Please try again" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                };
                cal.Subtract(a, b);
                cout << "End Subtract Function" << endl;
                cout << "" << endl;
                break;

            case 3:
                cout << "Start Product Function" << endl;
                cout << "Input two Real Number : " << endl;
                if(!(cin >> c >> d)) {
                    cout << "Your input is wrong!" << endl;
                    cout << "Please try again" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                };
                cal.Product(c, d);
                cout << "End Product Function" << endl;
                cout << "" << endl;
                break;
            
            case 4:
                cout << "Start Divide Function" << endl;
                cout << "Input two Real Number : " << endl;
                if(!(cin >> c >> d)) {
                    cout << "Your input is wrong!" << endl;
                    cout << "Please try again" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                };
                cal.Divide(c, d);
                cout << "End Divide Function" << endl;
                cout << "" << endl;
                break;

            case 5:
                cout << "Calculator Quit!" << endl;
                cout << "GoodBye!" << endl;
                exit(0);

        }
    }




}