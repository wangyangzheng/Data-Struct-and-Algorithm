#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;
int n, m;
int w[N], v[N];
int st[N];

int func(int w[], int v[], int i, int j) {
    if (i == n) {
        return 0;
    }
    int p1 = func(w, v, i + 1, j);
    int p2 = 0;
    for (int k = 1; k * w[i] <= j; k++) {
        p2 = func(w, v, i + 1, j - k * w[i]) + k * v[i];
    }
    return max(p1, p2);
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    cout << func(w, v, 0, m);
    return 0;
}
