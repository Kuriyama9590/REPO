#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.length();
    int maxLength = 0;

    unordered_set<char> charSet;
    int i = 0, j = 0;

    while (i < N && j < N) {
        if (charSet.find(s[j]) == charSet.end()) {
            charSet.insert(s[j]);
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        else {
            charSet.erase(s[i]);
            i++;
        }
    }

    cout << "最长不重复子串的长度为: " << maxLength << endl;

    return 0;
}
