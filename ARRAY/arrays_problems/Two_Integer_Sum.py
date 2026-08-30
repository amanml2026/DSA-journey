'''
Given an array of integers numbers that is sorted in non-decreasing order.
Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up 
to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, 
therefore you may not use the same element twice.

'''

def twoSum(numbers: list[int], target: int) -> list[int]:
    # two pointers appraoch
    i = 0 #left pointer
    j = len(numbers) - 1 #right pointer
    while(i<j):
        total = numbers[i] + numbers[j] # total of both the elements
        if total == target: # total = target --> return indices
            return [i+1,j+1] 
        elif total < target: #total less than target --> move the left pointer one step to right
            i += 1
        else: # total more than the target --> move the right pointer to left by one step
            j -= 1

nums = [1,2,3,4]
print(twoSum(nums,3))

