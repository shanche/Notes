import numpy as np

def maxProfit(prices):
    prices=np.array(prices)
    length=prices.size
    if length < 2: return 0
    profit1=np.zeros(length)
    profit2=np.zeros(length)
    
    # find the maximal profits with one transaction 
    #  in sub list prices[0],...,price[i]
    minP=prices[0]
    for i in range(1,length):
        minP=min(minP, prices[i])
        profit1[i]=max(profit1[i-1],prices[i]-minP)
    
    # find the maximal profits with one transaction 
    #  in sub list prices[i+1],...,price[n-1]    
    maxP=prices[length-1]
    for i in range(length-2,1,-1):
        maxP=max(maxP,prices[i])
        profit2[i]=max(profit2[i+1],maxP-prices[i])
    
    res=(profit1+profit2).max()

    return res