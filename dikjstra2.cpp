#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n, m;

int h[N], ne[N], e[N], idx, w[N];

int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; 
}


int dj () {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    //小顶堆
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    
    while (heap.size()) {
        //每次取出堆的顶部, 并弹出, 这一步就是对dj1的优化
        PII t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        
        //标记
        if (st[ver]) continue;
        st[ver] = true;
        
        // 遍历更新
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        //因为是有向图
        add(a, b, c);
    }
    
    cout << dj() << endl;
    return 0;
}