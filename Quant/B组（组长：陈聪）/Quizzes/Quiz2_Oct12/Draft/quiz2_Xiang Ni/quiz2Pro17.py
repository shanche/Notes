def maxProfit(self, prices):
        length=len(prices)
        if length < 2: return 0
        profit1=[0 for i in range(length)]
        profit2=[0 for i in range(length)]
        
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
        
        res=0
        for i in range(length):
            if profit1[i]+profit2[i]>res: res=profit1[i]+profit2[i]
        return res