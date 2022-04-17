#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;
int w[N], v[N];
int n, m;


int func(int w[], int v[], int i, int j) {
    if (j < 0) return -1;
    if (i == -1) return 0;
    int p1 = func(w, v, i - 1, j);
    int p2 = 0;
    int next = func(w, v, i - 1, j - w[i]);
    if (next != -1) {
        p2 = next + v[i];
    }
    return max(p1, p2);
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    cout << func(w, v, n - 1, m);
    return 0;
}
