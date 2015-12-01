int baisedCoin(int[] p, int m) {
    for (int i = 0; i < m; i++) {
        int s = fairCoin();
        if (s < p[i]) {
            return 1;
        }  
        else if (s > p[i]) {
            return 0;
        }
     }
     return 0;
}



