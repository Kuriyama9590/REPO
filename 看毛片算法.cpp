﻿#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_next(string s)//abcbabccabc
{
    vector<int> next;
    int j, k;
    j = 0; k = -1;
    next.push_back(-1);
    for (int i = 1; i < s.size(); ++i) next.push_back(0);
    while (j < s.length() - 1)
    {
        if (k == -1 || s[j] == s[k])
        {
            j++; k++;
            next[j] = k;
        }
        else k = next[k];
    }
    return next;
}

int match(string main, string model) {
    vector<int> next = get_next(model);
    int i = 0, j = 0;
    int main_len = main.size();
    int model_len = model.size();

    while (i < main_len) {
        if (main[i] == model[j]) {
            ++i;
            ++j;
        }

        if (j == model_len) {
            return i - j;  // 在位置 i - j 处找到匹配
        }
        else if (i < main_len && main[i] != model[j]) {
            if (j != 0) {
                j = next[j - 1];
            }
            else {
                ++i;
            }
        }
    }

    return -1;
}

int main() {//aaaabababac abac
    int t;
    cin >> t;
    while (t--) {
        string main, model,exc;
        cin >> main >> model>>exc;
        cout << main << endl;
        int pos = match(main, model);
        if (pos!= -1){
            main.replace(pos, model.size(), "");
            main.insert(pos, exc);
        }
        cout << main << endl;
        
    }

    return 0;
}