import numpy as np
import unittest
from copy import deepcopy


class Solution:
	def __init__(self, input_board):
		self.board = deepcopy(np.array(input_board))
		self.board = np.flipud(np.fliplr(self.board))
		self.board_shape = self.board.shape
		self.calculated = np.zeros(self.board_shape, dtype=bool)
		self.max_value = np.zeros(self.board_shape)
		self.max_value[0][0]=self.board[0][0]
		self.calculated[0][0] = True

	def max_sum(self, i, j):
		if i<0 or j<0:
			print "illegal i or j, return -1"
			return -1
		if self.calculated[i][j]==True:
			return self.max_value[i][j]

		if i==0:
			self.max_value[i][j] = self.max_sum(i, j-1) + self.board[i][j]
			self.calculated[i][j] = True
			return self.max_value[i][j]

		if j==0:
			self.max_value[i][j] = self.max_sum(i-1, j) + self.board[i][j]
			self.calculated[i][j] = True
			return self.max_value[i][j]

		self.max_value[i][j] = max(self.max_sum(i, j-1) + self.board[i][j],\
			self.max_sum(i-1, j) + self.board[i][j])
		self.calculated[i][j] = True
		return self.max_value[i][j]
