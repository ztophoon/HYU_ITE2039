#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321
#define SIZE_OF_ARR 1005

int* sum;
int** dp;
string str;
vector<int> v;

int mergeSlides(int i, int j) {
    if (i == j) return dp[i][j] = 0;
    if (dp[i][j] != INF) return dp[i][j];

    for (int k = i; k < j; k++) {
        if (i == 0) dp[i][j] = min(mergeSlides(i, k) + mergeSlides(k + 1, j) + sum[j], dp[i][j]);
        else dp[i][j] = min(mergeSlides(i, k) + mergeSlides(k + 1, j) + (sum[j] - sum[i - 1]), dp[i][j]);
    }

    return dp[i][j];
}

int main() {
    while (true) {
        v.resize(0);
        str.resize(0);

        getline(cin, str);
        if (str[0] == ' ' || str.size() == 0) break;

        // Parsing input string
        string num = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                v.push_back(atoi(num.c_str()));
                num = "";
            }
            else num += str[i];
        }
        v.push_back(atoi(num.c_str()));

        if (v.size() != 1) {
            sum = (int*)malloc(sizeof(int) * v.size());
            for (int i = 0; i < v.size(); i++) {
                if (i == 0) sum[i] = v[i];
                else sum[i] = sum[i - 1] + v[i];
            }

            dp = (int**)malloc(sizeof(int*) * v.size());
            for (int i = 0; i < v.size(); i++) {
                dp[i] = (int*)malloc(sizeof(int) * v.size());
                for (int j = 0; j < v.size(); j++) dp[i][j] = INF;
            }
            for (int i = 0; i < v.size(); i++)
                for (int j = 0; j < v.size(); j++) dp[i][j] = INF;

            printf("%d\n", mergeSlides(0, v.size() - 1));

            for (int i = 0; i < v.size(); i++) free(dp[i]);
            free(dp);
            free(sum);
        }
        else printf("%d\n", v[0]);
    }
    return 0;
}