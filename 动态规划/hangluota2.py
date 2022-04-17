a = int(input())
from1, to, other = input().split()

def func(n, from1, to, other):
    if n == 1:
        print("move 1 from " + from1 + " to " + to)
        return
    func(n - 1, from1, other, to)
    print("move " + str(n) + " from " + from1 + " to " + to)
    func(n - 1, other, to, from1)

func(a, from1, to, other)
