import time
import random

def kadane_algo(A):
    if len(A) == 0: # length is zero
        return "NULL"
    maxSum = float('-inf')
    i = 0 

    while i < len(A): #boundary

        sum = 0 # for new subarray -> initially sum = 0
        j = i # for traversing through the subarray

        while (j < len(A) ): # traversal boundary
            sum += A[j] # adding the elements in the subarray
            if sum > maxSum: # updating maxSum
                low = i # starting index of max subarray
                high = j # ending index of max subarray
                maxSum = sum # sum of max subarray
            j += 1 # increasing j
            if sum<0: # if sum = negative -> negative contribution to the subarray -> drop the subarray right there
                break # breaking the inner loop -> ending the subarray

        if sum<0:
            i = j # to traverse other subarray
        if j == len(A): # breaking the outer loop once the traversal pointer reaches end of list
            break

    return low,high,maxSum

def MaxSubarray(A):
    length = len(A)
    low = 0
    high = 0
    MaxSum = float('-inf')

    for l in range(length):
        sum = 0
        for r in range(l, length):
            sum += A[r]

            if sum > MaxSum:
                MaxSum = sum
                low = l
                high = r

    return low, high, MaxSum

# TESTS 
# Test1 = [-2, 4, -1, 2, 1, -5, 4, 3]
# print(kadane_algo(Test1))

# Test2 = [-7,  4, -2,  5, -1,  3, -6,  8, -3,  2,
# 4, -10,  6, -1,  2,  3, -2,  5, -8,  4,
# -3,  7, -2,  6, -4, -5,  9, -1,  3, -2,
# 4, -12,  5,  2, -1,  4, -3,  2, -1,  6]
# print(kadane_algo(Test2))
size = [10000,30000,50000]
for n in size:
    Test = [random.randint(-100,100) for _ in range(n)]
    start_brute = time.perf_counter()
    print("Sol. =",MaxSubarray(Test))
    print(f"Time taken by brute force is {time.perf_counter()-start_brute}.")
    start_kadane = time.perf_counter()
    print("Sol. =",kadane_algo(Test))
    print(f"Time taken by kadane algorithm is {time.perf_counter()-start_kadane}.")
    print()
    print()
# HUGE DIFFERENCE !!! *_*