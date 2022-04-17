n = int(input())

def leftToMid(n):
    if n == 1:
        print("move 1 from left to mid")
        return
    leftToRight(n - 1)
    print("move " + str(n) + " from left to mid")
    rightToMid(n - 1)

def leftToRight(n):
    if n == 1:
        print("move 1 from left to right")
        return
    leftToMid(n - 1)
    print("move " + str(n) + " from left to right")
    midToRight(n - 1)

def midToRight(n):
    if n == 1:
        print("move 1 from mid to right")
        return
    midToLeft(n - 1)
    print("move " + str(n) + " from mid to right")
    leftToRight(n - 1)

def midToLeft(n):
    if n == 1:
        print("move 1 from mid to left")
        return
    midToRight(n - 1)
    print("move " + str(n) + " from mid to left")
    rightToMid(n - 1)

def rightToMid(n):
    if n == 1:
        print("move 1 from right to mid")
        return
    rightToleft(n - 1)
    print("move " + str(n) + " from right to mid")
    leftToMid(n - 1)

def rightToleft(n):
    if n == 1:
        print("move 1 from right to left")
        return
    rightToMid(n - 1)
    print("move" + str(n) + " from right to left")
    midToLeft(n - 1)

leftToMid(n)
