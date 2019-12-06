#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001
#define mp make_pair

int arr[MAX];
vector<pair<int,pair<int,int>>> vec;

int find(int x) {
    if (arr[x] == x) return x;
    else return arr[x] = find(arr[x]);
}

int uni(int x, int y) {
    if (find(x) != find(y)) {
        arr[find(x)] = find(y);
        return 1;
    }
    else return 0;
}

int input(int* num){
    string str;
    cin >> str;

    try{
        *num = stoi(str);
    } catch (exception e){
        fprintf(stderr, "wrong input included(input must be a integer).\n");
        exit(1);
    }

    if(*num == 0) return 1;
    else return 0;
}

int main() {
    while(true){
        int v, e, a, b, w;

        if (input(&v) || input(&e)) {
            fprintf(stderr, "wrong input included(input must be a none-zero).\n");
            exit(1);
        }

        for (int i = 1; i <= MAX; i++) arr[i] = i;
        vec.resize(0);

        for (int i = 0; i < e; i++) {
            // check for zero input
            if (input(&a) || input(&b)) {
                fprintf(stderr, "wrong input included(input must be a valid city id).\n");
                exit(1);
            }
            // check for valid city_id
            if(a > v || b > v){
                fprintf(stderr, "wrong input included(input must be a valid city id).\n");
                exit(1);
            }
            input(&w);
            vec.push_back(mp(w, mp(a, b)));
        }
        sort(vec.begin(), vec.end());

        int ans = 0, cnt = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (cnt == v - 1) break;
            if (uni(vec[i].second.first, vec[i].second.second)) {
                ans += vec[i].first;
                cnt++;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
