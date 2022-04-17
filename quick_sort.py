def quick_sort(arr, left, right):
    //递归结束
    if left >= right:
        return
    i = left - 1
    j = right + 1
    x = arr[(i+j)//2]
    while left < right:
        while True:
            i += 1
            if arr[i] >= x:
                break
        while True:
            j -= 1
            if arr[j] <= x:
                break
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
        else:
            break
    quick_sort(arr, left, j)
    quick_sort(arr, j+1, right)


n = int(input())
a = list(map(int, input().split()))
quick_sort(a, 0, n-1)
print(' '.join(map(str, a)))
