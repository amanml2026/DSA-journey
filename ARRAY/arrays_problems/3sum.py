'''Given an integer array nums, return all the triplets [nums[i], nums[j], 
nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.'''

def threeSum(nums: list[int]) -> list[list[int]]: # O(n^3) -> BRUTE FORCE 
    ans = [] 
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            for k in range(j + 1, len(nums)):
                if nums[i] + nums[j] + nums[k] == 0: # triplet
                    triplet = sorted([nums[i], nums[j], nums[k]])  # sorting for efficient check 
                    if triplet not in ans: # appending the list of triplet
                        ans.append(triplet)

    return ans # list of list of triplets

nums = [-1,0,1,2,-1,-4]
print(threeSum(nums))