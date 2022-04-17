def quick_sort(nums, left, right):
    if left >= right:
        return 
    x = nums[(left + right) // 2]
    i, j = left - 1, right + 1
    while i < j:
        while True:
            i += 1
            if nums[i] >= x:
                break
        while True:
            j -= 1
            if nums[j] <= x:
                break
        if i < j:
            nums[i], nums[j] = nums[j], nums[i]
        else: break
    quick_sort(nums, left, j)
    quick_sort(nums, j + 1, right)

n = int(input())
a = list(map(int, input().split()))

quick_sort(a, 0, n - 1)
print(" ".join(map(str, a)))
