n = int(input())

res = [0] * n # 保存结果
flag = [False] * (n+1)
def dfs(u):
    if u == n:
        for i in res:
            print(i, end=" ")
        print()
    else:
        # 判断当前位置可以遍历哪些数
        for i in range(1, n+1):
            if flag[i] == False:
                res[u] = i
                flag[i] = True
                dfs(u + 1)
                # 恢复现场
                res[u] = 0
                flag[i] = False
dfs(0)
