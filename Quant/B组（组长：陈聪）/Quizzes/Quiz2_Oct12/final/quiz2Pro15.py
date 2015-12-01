def expandAroundCenter(str, c1, c2):
    left = c1
    right = c2
    length = len(str)
    
    while(left >= 0 and right <=length-1 and str[left] == str[right]):
        left-=1
        right+=1
        
    return str[left+1:right]
    
def longestPalindrome(str):
    n = len(str)
    if (n==0): return ""
    
    longest = str[0:1]
    for i in range(n):
        p1 = expandAroundCenter(str,i,i)
        if (len(p1) > len(longest)): longest = p1
        
        p2 = expandAroundCenter(str,i,i+1)
        if (len(p2) > len(longest)): longest = p2
        
    return longest
        
    
    
    
    