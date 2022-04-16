#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N], dist[N];
bool st[N];
int n, m;


int dj () {
    //初始化距离为非常大
    memset(dist, 0x3f, sizeof dist);
    // 初始化起点的距离为0
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        //每次取出最短距离
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        
        //将这点进行标记
        st[t] = true;
        
        //更新该点的距离
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]); 
        }
    }
    // 表示不存在最短路径
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        // 处理重边 
        g[a][b] = min(g[a][b], c);
    }
    cout << dj() << endl;
    return 0;
}
