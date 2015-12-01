# P12 longest decreasing subarray

def longest_dec_subarray(x):
	size=len(x)
	if size<1:
		return 0
	final_start=0
	longest_size=1
	local_size=1
	start=0; end=0
	while start<size-1:
		for end in range(start+1, size):
			if x[end]>=x[end-1] or end==size-1:
				if local_size>longest_size:
					longest_size=local_size
					final_start=start
				start=end
				local_size=1
				# print start
				break
			else:
				local_size+=1
	return x[final_start:final_start+longest_size]

