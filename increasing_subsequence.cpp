#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

#define INF 987654321
typedef pair<int, int> ci;

string str;
vector<int> bt;
vector<ci> temp;
vector<char> ans;

int main() {
    while (true) {
        getline(cin, str);
        if (str[0] == ' ' || str.size() == 0) break;

        // Check space or tab
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                str.resize(i);
                break;
            }
        }

        bt.resize(0);
        ans.resize(0);
        temp.resize(0);
        temp.push_back(ci(-INF, -1));
        for (int i = 0; i < str.size() + 1; i++) bt.push_back(0);

        for (int i = 0; i < str.size(); i++) {
            if (temp.back().first < str[i]) {
                bt[i] = temp.back().second;
                temp.push_back(ci(str[i], i));
            }
            else {
                auto iterator = lower_bound(temp.begin(), temp.end(), ci(str[i], i));
                bt[i] = (iterator - 1)->second;
                *iterator = ci(str[i], i);
            }
        }

        // Back-Tracking
        for (int i = temp.back().second; i >= 0; i = bt[i])
            ans.push_back(str[i]);

        for (int i = ans.size() - 1; i >= 0; i--)
            printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}
