def reverseWords(word):
    length = len(word)
    if (length < 2): return word
    left = 0
    right = length-1
    
    while (left < right):
        tmp = word[left]
        word[right] = word[left]
        word[left = tmp
    
    return word
    

def reverseSentences(sentence):
    res = []
    reverseWords(sentence)
    
    pt1 = 0
    pt2 = 0
    
    while (pt2 != len(sentence)):
        if (sentence[pt2] != " "):
            pt2++
        sentence[pt1,pt2-1] = reverseWords(sentence[pt1,pt2-1])
        pt1 = pt2
        
    return sentence
    
      