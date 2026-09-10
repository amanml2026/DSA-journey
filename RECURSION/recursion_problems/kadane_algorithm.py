def kadane_algo(A):
    if len(A) == 0:
        return "NULL"
    maxSum = float('-inf')
    i = 0

    while i < len(A):

        sum = 0
        j = i

        while (j < len(A) ):
            sum += A[j]
            if sum > maxSum:
                low = i
                high = j
                maxSum = sum
            j += 1
            if sum<0:
                break

        if sum<0:
            i = j
        if j == len(A):
            break

    return low,high,maxSum

Test1 = [-2, 4, -1, 2, 1, -5, 4, 3]
print(kadane_algo(Test1))

Test2 = [-7,  4, -2,  5, -1,  3, -6,  8, -3,  2,
4, -10,  6, -1,  2,  3, -2,  5, -8,  4,
-3,  7, -2,  6, -4, -5,  9, -1,  3, -2,
4, -12,  5,  2, -1,  4, -3,  2, -1,  6]

print(kadane_algo(Test2))