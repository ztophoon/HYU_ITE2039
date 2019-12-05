#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000001
#define mp make_pair

vector<pair<int,pair<int,int>>> vec;

int arr[MAX];

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

int main() {
    while(true){
        int v, e, a, b, w;

        scanf("%d", &v);
        if (!v) break;
        scanf("%d", &e);
        if (!e) break;

        for (int i = 1; i <= MAX; i++) arr[i] = i;
        vec.resize(0);

        for (int i = 0; i < e; i++) {
            scanf("%d %d %d", &a, &b, &w);
            vec.push_back(mp(w, mp(a, b)));
        }
        sort(vec.begin(), vec.end());

        //printf("------\n");
        int ans = 0, cnt = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (cnt == v - 1) break;
            if (uni(vec[i].second.first, vec[i].second.second)) {
                //printf("%d %d %d\n", vec[i].second.first, vec[i].second.second, vec[i].first);
                ans += vec[i].first;
                cnt++;
            }
        }
        //printf("------\n");

        printf("%d\n", ans);
    }
    return 0;
}
