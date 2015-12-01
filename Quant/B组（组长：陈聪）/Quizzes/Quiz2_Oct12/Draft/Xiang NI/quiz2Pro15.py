def expandAroundCenter(str, c1, c2):
    left = c1
    right = c2
    length = len(str)
    
    while(left >= 0 && right <=length-1 && str[left] == str[right]):
        left--
        right++
        
    return str[left+1:right]
    
def longestPalindrome(str):
    length = len(str)
    if (n==0): return ""
    
    longest = str[0:1]
    for i in range(n):
        p1 = expandAroundCenter(str,i,i)
        if (len(p1) > len(longest)): longest = p1
        
        p2 = expandAroundCenter(str,i,i+1)
        if (len(p2) > len(longest)): longest = p2
        
    return longest
        
    
    
    
    