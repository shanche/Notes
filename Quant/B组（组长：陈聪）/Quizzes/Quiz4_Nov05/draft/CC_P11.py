# P11 check palindrome sequence

def check_palindrone(x):
	x=list(x)
	size=len(x)
	start=0; end=size-1
	while start<end:
		if x[start]!=x[end]: return False
		start+=1
		end-=1
	return True