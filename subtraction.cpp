#include <string>
using namespace std;
int subEach(char, char);
/**
 * 두 문자열로 감싸진 big integer를
 * 각각의 자리 별로 뺀 후
 * 뺀 결과 값을 반환하는 메소드.
 */
string bigSubtraction(string a, string b) {
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
    bool beforeLessThanZero = false;
    for(int i = a.length()-1 ; i >= 0 ; i--) {
        next = subEach(a[i], b[i]);
        if(beforeLessThanZero) {
            next -= 1;
        }
        if(next < 0) {
            next += 10;
            result.insert(0, to_string(next));
            beforeLessThanZero = true;
        }
        else {
            result.insert(0, to_string(next));
            beforeLessThanZero = false;
        }
    }
    if(beforeLessThanZero) {
        result.replace(0, 1, to_string(next -= 10));
    }
    // 맨 앞자리에 0이 있다면 제거
    int length = result.length();
    for(int i = 0 ; i < length - 1 ; i++) {
        if(result[0] == '0')
            result.erase(0, 1);
        else
            break;
    }
    return result;
}
int subEach(char a, char b) {
    int x = a - '0';
    int y = b - '0';
    return x - y;
}