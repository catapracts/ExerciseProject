#include <iostream>
#include <string>

// namespace a {
//     int n;
// }

// namespace b {
//     int n;
// }

using namespace std;


int main() {
    cout << "Hello World!" << endl;

    // a::n = 10;
    // b::n = 20;

    cout << "Hello World!" << 10 << 'C' << endl; //endl = \n

    int a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;

    string str;
    str = "Hello";
    cout << str << endl;

    string name;
    cout << "name : ";
    cin >> name;
    string message = "Hello, " + name + "sir";
    cout << message << endl;

}