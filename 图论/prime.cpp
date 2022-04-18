#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
const int N = 510;
int g[N][N], INF = 0x3f3f3f3f;
int dist[N];
bool st[N];
int res;

int prime() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    return res;
}


int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prime();
    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}
