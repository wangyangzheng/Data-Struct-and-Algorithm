//请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int n, m, k;

int dist[N], backup[N];

struct Edge{
    int a, b, c;
} edges[N];


int bf() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= k; i++) {
        //注意这里是backup防止串联
        memcpy(backup, dist, sizeof dist);
        for (int j = 1; j <= m; j++) {
            auto e = edges[j];
            int a = e.a, b = e.b, c = e.c;
            dist[b] = min(dist[b], backup[a] + c);
        }
    }
    return dist[n];
}

int main(){
    // n 是点数，m是边数，k是限制条件
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i].a = a, edges[i].b = b, edges[i].c = c;
    }
    int t = bf();
    if (t >= 0x3f3f3f3f / 2) puts("impossible");
    else cout << t << endl;
    return 0;
}
