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
    nums = sorted(nums) # sorted list of numbers
    for i in range(len(nums)-2): # last 2 elements will be pointed by j and k
        if i > 0 and nums[i] == nums[i - 1]: # avoid duplicate nums[i]
            continue
        # two pointers initailisation for each nums[i]
        j = i+1 
        k = len(nums)-1
        while(j<k):
            if (nums[i] + nums[j] + nums[k] == 0): # triplet found
                ans.append([nums[i], nums[j], nums[k]]) # appending the triplet into list
# if there are duplicates of nums[j] or nums[k] then moving pointers till duplicates are crossed to avoid duplicate triplets.
                while j < k and nums[j] == nums[j + 1]: 
                    j += 1

                while j < k and nums[k] == nums[k - 1]:
                    k -= 1

                j += 1
                k -= 1

            elif (nums[j]+nums[k]< -(nums[i])): # if the total is less than zero
                j += 1
            elif (nums[j]+nums[k] > -(nums[i])): # if total is more than zero
                k -=1 

    return ans # list of list of triplets
print(threeSum_2(nums))
