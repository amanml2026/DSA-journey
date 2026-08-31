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