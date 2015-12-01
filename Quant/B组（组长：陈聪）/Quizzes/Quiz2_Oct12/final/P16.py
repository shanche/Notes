# wu chi de python code

def revSentence(sentence):
    s = sentence.split()
    s.reverse()
    print "reversed sentence is:"
    for i in range(len(s)): 
        print s[i],