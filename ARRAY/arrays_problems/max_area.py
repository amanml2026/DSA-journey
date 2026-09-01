'''
You are given an integer array heights where heights[i] represents the height of the i(th)bar.
You may choose any two bars to form a container. Return the maximum amount of water a container can store.

'''

# Brute force approach --> O(n^2)
def maxArea(heights: list[int]) -> int:
    MaxArea = 0 
    # iterating through each pair
    for i in range(len(heights)):
        for j in range(i+1,len(heights)):
            area = min(heights[i],heights[j]) * (j-i)

            if area > MaxArea: # if area of given pair of bars is greater than the MaxArea
                MaxArea = area

    return MaxArea # MaxArea

heights = [1,7,2,5,4,7,3,6]
# testing the brute force approach
print(maxArea(heights))

# Optimal solution --> using two pointers -> O(n)
def maxArea_optimised( heights: list[int]) -> int:
    MaxArea = 0
    # starting with maximising the width
    i = 0
    j = len(heights) - 1
    while(i<j):
        # area of the pair of bars
        area = (j-i)*min(heights[i],heights[j])
        if area > MaxArea:
            MaxArea = area
        # moving the pointer from the smaller value between heights[i] and heights[j]
        if (heights[i] < heights[j]):
            i += 1
        else:
            j -= 1

    return MaxArea # max area
# testing the optimal approach
print(maxArea_optimised(heights))