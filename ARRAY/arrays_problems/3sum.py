'''Given an integer array nums, return all the triplets [nums[i], nums[j], 
nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.'''

# BRUTE FORCE 
def threeSum(nums: list[int]) -> list[list[int]]: # O(n^3)
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

# BETTER APPROACH -> O(n^2)
def threeSum_2(nums : list[int]) -> list[list[int]]:
    ans = []
    nums = sorted(nums)
    for i in range(len(nums)-2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        j = i+1
        k = len(nums)-1
        while(j<k):
            if nums[i] + nums[j] + nums[k] == 0:
                ans.append([nums[i], nums[j], nums[k]])

                while j < k and nums[j] == nums[j + 1]:
                    j += 1

                while j < k and nums[k] == nums[k - 1]:
                    k -= 1

                j += 1
                k -= 1

            elif (nums[j]+nums[k]< -(nums[i])):
                j += 1
            elif (nums[j]+nums[k] > -(nums[i])):
                k -=1 

    return ans
print(threeSum_2(nums))
