'''Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than 
the previous element. The elements do not have to be consecutive in the original array.'''

# CAVEAT --> THIS SOLUTION IS ONLY EFFICIENT FOR ELEMENTS OF SMALL RANGE ONLY !!!

nums = [13,12,5,4,9,14,18,15,16,17,20,33,1]
def longestConsecutive(nums):
    if len(nums) == 0:
        return 0
    low = min(nums) # finding min
    high = max(nums) # finding max

    frequency = [0] * (high-low+1) # frequency table
    for i in range(len(nums)):
        frequency[nums[i]-low] += 1 # adding frequencies

    i = consq = 0
    while(i<len(frequency)):
        j = i
        while( j<len(frequency) and frequency[j]>0 ):
            j += 1
        if(j-i>consq):
            consq = j-i
        i = j+1 # to not iterate through same elements again
    return consq # longest sequence

print(longestConsecutive(nums))

# Better solution by first sorting the elements --> O(nlogn)
def longestConsecutive_2( nums: list[int]) -> int:
    nums = list(set(nums))
    sorted_nums = sorted(nums)
    i=0
    maxS = 0
    while(i<len(sorted_nums)):
        j = i
        seq = 1
        while(j < len(sorted_nums)-1 and sorted_nums[j+1] == sorted_nums[j]+1):
            seq += 1
            j += 1
        if(maxS<seq):
            maxS = seq
        i = j + 1

    return maxS

print()
