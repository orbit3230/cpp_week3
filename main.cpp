#include <iostream>
using namespace std;

string bigAddition(string, string);
string bigSubtraction(string, string);

int main() {
    string a;
    string b;
    cout << "First number   >> ";
    cin >> a;
    cout << "Second number  >> ";
    cin >> b;

    cout << "Sum            >> " << bigAddition(a, b) << endl;
    cout << "Sub            >> " << bigSubtraction(a, b) << endl;

    return 0;
}