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