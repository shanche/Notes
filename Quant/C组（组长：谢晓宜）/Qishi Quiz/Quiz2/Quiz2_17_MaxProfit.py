# -*- coding: utf-8 -*-
"""
Created on Tue Oct 13 21:01:05 2015

@author: Bo He
"""

# One transaction: buy once and sell once, and buy take place before sell.

stock_prices = [50,60,90,30,60,10,40]

def maxProfit(stock_prices):
    if len(stock_prices) < 2: return 0
    max_profit = 0
    mintillnow = stock_prices[0]
    for r in stock_prices:
        max_profit = max(max_profit, r - mintillnow)
        mintillnow = min(mintillnow, r)
            
    return max_profit
    
maxProfit(stock_prices)

# Two transactions: buy twice and sell twice, the first sell must take place before the second buy
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        import sys
        if len(prices) < 2 : return 0
        profit1 = 0
        profit2 = -sys.maxint-1
        buy1 = -prices[0]
        buy2 = -sys.maxint-1
        for i in range(1, len(prices)):
            if prices[i] < prices[i-1]:
                buy1 = max(buy1, -prices[i])
                buy2 = max(buy2, profit1-prices[i])
            else:
                profit1 = max(profit1, buy1 + prices[i])
                profit2 = max(profit2, buy2 + prices[i])
        
        return max(profit1, profit2)