'''Given an integer array nums, return all the triplets [nums[i], nums[j], 
nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.'''

def threeSum(nums: list[int]) -> list[list[int]]:
    ans = []
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            for k in range(j + 1, len(nums)):
                if nums[i] + nums[j] + nums[k] == 0:
                    triplet = sorted([nums[i], nums[j], nums[k]])
                    if triplet not in ans:
                        ans.append(triplet)

    return ans