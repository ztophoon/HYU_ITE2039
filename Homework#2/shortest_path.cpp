#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define MAXN 20000

int D[MAXN + 1];
bool visit[MAXN + 1];
vector<pair<int, int>> Edge[MAXN + 1];
priority_queue<pair<int, int>> pq; //(거리, 정점):거리 순 정렬

int input(int* num){
    string str;
    cin >> str;

    try{
        *num = stoi(str);
    } catch (exception e){
        perror("error: input must be a integer");
        exit(1);
    }

    if(&num == 0) return 1;
    else return 0;
}

int main() {
    while(true){
        int n, m, a, b, d;

        //scanf("%d", &n);
        //if (!n) break;
        //scanf("%d", &m);
        //if (!m) break;

        input(&n);
        input(&m);

        for(int i = 0; i <= MAXN; i++){
            D[i] = 0;
            visit[i] = false;
            Edge[i].resize(0);
        }
        while(!pq.empty()) pq.pop();

        for (int i = 0; i < m; i++) {
            //scanf("%d %d %d", &a, &b, &d);
            input(&a); input(&b); input(&d);
            Edge[a].push_back(make_pair(b, d));
            Edge[b].push_back(make_pair(a, d));
        }

        pq.push(make_pair(0, 1));

        while (!pq.empty()) {
            int d = -pq.top().first;
            int v = pq.top().second;
            pq.pop();

            if (visit[v]) continue;
            visit[v] = true;
            D[v] = d;

            for (int i = 0; i < Edge[v].size(); i++)
                pq.push(make_pair(-(D[v] + Edge[v][i].second), Edge[v][i].first));
        }

        printf("%d\n", D[n]);
    }

    return 0;
}
