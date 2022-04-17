#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;
int w[N], v[N];

int f[N][N];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            int p1 = f[i + 1][j];
            int p2 = 0;
            int next = j - w[i] >= 0 ? f[i + 1][j - w[i]] : -1;
            if (next != -1) {
                p2 = v[i] + next;
            }
            f[i][j] = max(p1, p2);
        }
    }
    cout << f[0][m] << endl;
    return 0;
}
