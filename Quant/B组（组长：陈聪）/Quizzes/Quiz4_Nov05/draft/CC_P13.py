
import numpy as np
from copy import deepcopy

# board=np.array([
# [0,0,6,0,0,0,0,0,8],
# [1,0,0,0,0,4,5,2,0],
# [0,9,0,2,0,0,0,4,0],
# [8,1,4,0,0,7,0,0,0],
# [6,0,0,0,0,0,0,0,5],
# [0,0,0,6,0,0,4,3,7],
# [0,3,0,0,0,6,0,5,0],
# [0,4,2,7,0,0,0,0,9],
# [9,0,0,0,0,0,3,0,0]
# ])


# board=np.array([
# [0,1,0,9,0,3,0,0,6],
# [0,0,0,0,0,0,9,4,0],
# [0,0,0,6,2,0,0,7,0],
# [1,0,0,3,7,0,4,9,0],
# [0,0,0,0,6,0,0,0,0],
# [0,7,2,0,5,1,0,0,3],
# [0,3,0,0,9,8,0,0,0],
# [0,8,9,0,0,0,0,0,0],
# [4,0,0,7,0,6,0,2,0]
# 	])











def sudoku(input_board):
	board=deepcopy(input_board)
	hline=[[] for i in range(9)]
	vline=[[] for i in range(9)]
	box=[[] for i in range(9)]



	known = np.array(board)>0

	find_box = {}

	for i in range(3):
		for j in range(3):
			find_box[(i,j)]=box[0]
	for i in range(3):
		for j in range(3, 6):
			find_box[(i,j)]=box[1]
	for i in range(3):
		for j in range(6, 9):
			find_box[(i,j)]=box[2]

	for i in range(3, 6):
		for j in range(3):
			find_box[(i,j)]=box[3]
	for i in range(3, 6):
		for j in range(3, 6):
			find_box[(i,j)]=box[4]
	for i in range(3, 6):
		for j in range(6, 9):
			find_box[(i,j)]=box[5]

	for i in range(6, 9):
		for j in range(3):
			find_box[(i,j)]=box[6]
	for i in range(6, 9):
		for j in range(3, 6):
			find_box[(i,j)]=box[7]
	for i in range(6, 9):
		for j in range(6, 9):
			find_box[(i,j)]=box[8]


	for i in range(9):
		for j in range(9):
			if known[i][j]:
				num=board[i][j]
				hline[i].append(num)
				vline[j].append(num)
				find_box[(i,j)].append(num)

	def check_legal(num, i, j):
		if num in hline[i]: return False
		if num in vline[j]: return False
		if num in find_box[(i, j)]: return False
		return True


	i=0; j=0




	while i<8 or j<8:
		if known[i][j]:
			if j<8: j+=1
			else: i+=1; j=0
			continue

		num=board[i][j]
		while True:
			num+=1
			if num>9:            # failed, trace back
				board[i][j]=0
				while True:
					if j>0: j-=1
					else: 
						i-=1; j=8
						if i<0: 
							print "No solution!"
							return -1	
					if not known[i][j]: break
				num=board[i][j]
				hline[i].remove(num)
				vline[j].remove(num)
				find_box[(i,j)].remove(num)
				# print "trace back (%d, %d)"% (i, j)
				continue

			if check_legal(num, i, j):
				hline[i].append(num)
				vline[j].append(num)
				find_box[(i,j)].append(num)
				board[i][j]=num
				# print (i, j, num)
				break
		if j<8: j+=1
		else: i+=1; j=0

	print "Solution!"
	print board
	return board























