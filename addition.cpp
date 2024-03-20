#include <iostream>
#include <string>
using namespace std;
int addEach(char, char);
/**
 * 두 문자열로 감싸진 big integer를
 * 각각의 자리 별로 더하여
 * 더해진 결과 값을 반환하는 메소드.
 */
string bigAddition(string a, string b) {
    // 차이나(china X)는 자리수만큼 앞에 0을 넣어서 자릿수를 맞추는 작업
    if(a.length() > b.length()) {
        int gap = a.length() - b.length();
        for(int i = 0 ; i < gap ; i++) {
            b.insert(0, "0");
        }
    }
    else {
        int gap = b.length() - a.length();
        for(int i = 0 ; i < gap ; i++) {
            a.insert(0, "0");
        }
    }

    string result = "";
    int next;
    bool beforeMoreThanTen = false;
    for(int i = a.length()-1 ; i >= 0 ; i--) {
        next = addEach(a[i], b[i]);
        if(beforeMoreThanTen) {
            next += 1;
        }
        if(next >= 10) {
            next -= 10;
            result.insert(0, to_string(next));
            beforeMoreThanTen = true;
        }
        else {
            result.insert(0, to_string(next));
            beforeMoreThanTen = false;
        }
    }
    if(beforeMoreThanTen) {
        result.insert(0, "1");
    }
    return result;
}
int addEach(char a, char b) {
    int x = a - '0';
    int y = b - '0';
    return x + y;
}