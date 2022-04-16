#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N], dist[N];
bool st[N];
int n, m;


int dj () {
    //��ʼ������Ϊ�ǳ���
    memset(dist, 0x3f, sizeof dist);
    // ��ʼ�����ľ���Ϊ0
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        //ÿ��ȡ����̾���
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        
        //�������б��
        st[t] = true;
        
        //���¸õ�ľ���
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]); 
        }
    }
    // ��ʾ���������·��
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        // �����ر� 
        g[a][b] = min(g[a][b], c);
    }
    cout << dj() << endl;
    return 0;
}
