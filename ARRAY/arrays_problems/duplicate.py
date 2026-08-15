'''
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
'''
# APPROACH:
# We will just use the 'set' datatype of python and compare the length of original list and set

def hasDuplicate(nums: list[int]) -> bool:
    return (len(set(nums))!=len(nums))
