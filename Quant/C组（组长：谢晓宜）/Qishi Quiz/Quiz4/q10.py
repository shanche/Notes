import numpy as np

def intriangle(p1, p2, p3, p):
	"""p1, p2, p3 are 2 dimensional vectors
	aranged clock-wise on the plane"""
	t1 = np.cross(p1-p, p2-p)
	t2 = np.cross(p2-p, p3-p)
	t3 = np.cross(p3-p, p1-p)

	if ((t1>0 and t2>0 and t3>0) 
			or (t1<0 and t2<0 and t3<0)):
		return True
	else:
		return False

if __name__ == "__main__":
	p1 = np.array([0,0])
	p2 = np.array([2,0])
	p3 = np.array([0,4])
	p = np.array([1,1])
	q = np.array([2,2])

	print intriangle(p1,p2,p3,p)
	print intriangle(p1,p2,p3,q)
