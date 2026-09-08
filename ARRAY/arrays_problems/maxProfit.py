'''
You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.

You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.

Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.
'''

def maxProfit( prices: list[int]) -> int:
    l = 0 # buying point
    r = 1 # selling point
    maxP = 0
    while(r<len(prices)): # bound of the pointer
        if (prices[r]>prices[l]): # we are in profit
            profit = prices[r] - prices[l]
            maxP = max(profit,maxP)
        else:
            l = r # r is the least value seen se far -> therefore we want low buying price so setting l=r
        r += 1

    return maxP # maximum profit
# testing the function
prices = [10,1,5,6,7,1]
print(maxProfit(prices)) # 6