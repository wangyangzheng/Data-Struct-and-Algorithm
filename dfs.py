n = int(input())

path = n * [0]
st = (n + 1) * [False]

def dfs(u):
    if u == n:
        for i in path:
            print(i, end = ' ')
        print()
    else:
        for i in range(1, n + 1):
            if st[i] == False:
                path[u] = i
                st[i] = True
                dfs(u + 1)
                st[i] = False

dfs(0)
