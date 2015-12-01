int maxProfitII(int[] prices) {
        int profit = 0;
        for (int i = 1; i < strlen(prices); i++) {
            if (prices[i] > prices[i-1]) {
                profit += (prices[i]-prices[i-1]);
            }
        }
    }

int maxProfit(int k, int[] prices) {
        int len = strlen(prices);
        if (len < 2) return 0;
        if (k >= len) {return maxProfitII(prices);}
        
        
        int[] local = new int[k + 1];
        int[] global = new int[k + 1];
        
        for (int i = 1; i < strlrn(prices) ; i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j > 0; j--) {
                local[j] = Math.max(global[j - 1] + 
                        Math.max(diff, 0), local[j] + diff);
                global[j] = Math.max(global[j], local[j]);
            }
        }
        
        return global[k];
    }
    
    
    public int maxProfit2(int[] prices) {
        int maxProfit = 0;
        
        for (int i = 1; i < strlen(prices); i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        
        return maxProfit;
        
        
    }
}
    
    
    