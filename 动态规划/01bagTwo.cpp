#include <iostream>
#include <cstdio>

using namespace std;
const int N = 1010;
int n, m;
int w[N], v[N];

int f[N][N];

int main(){
    cin >> n >> m;
    //注意
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int p1 = f[i - 1][j];
            int p2 = 0;
            int next = j - w[i] >= 0 ? f[i - 1][j - w[i]] : -1;
            if (next != -1) {
                p2 = next + v[i];
            }
            f[i][j] = max(p1, p2);
        }
    }
    cout << f[n][m];
    return 0;
}
