def render(self,x,y,c1,c2,c3,c4,c5,c6,c7,c8):
	self.matrix[x][y] = c1
	self.matrix[x][y+1] = c2
	self.matrix[x][y+2] = c3
	self.matrix[x][y+3] = c4
	self.matrix[x+1][y] = c5
	self.matrix[x+1][y+1] = c6
	self.matrix[x+1][y+2] = c7
	self.matrix[x+1][y+3] = c8	

def render_brick(matrix, x, y):
	matrix[x][y] = matrix[x][y+1] = matrix[x][y+2] = matrix[x][y+3] = matrix[x+1][y] = matrix[x+1][y+1] = matrix[x+1][y+2] = matrix[x+1][y+3] = '\033[1;30m#\033[1;m'

class Board:
	def __init__(self, row, col):
		self.row = row
		self.col = col
		# Initialize matrix

		matrix = [[' ' for y in range(col)] for x in range(row)]
			
		for i in range(0, row):
			if 4*i > row-2:
				break
			for j in range(0, col):
				if 8*j > col-4:
					break
				render_brick(matrix, 4*i, 8*j)

		# Walls
		for y in range(0, row):
			if y == 0 or y == 1 or y == row - 2 or y == row - 1:
				for x in range(0, col):
					matrix[y][x] = 'X'
			else:
					matrix[y][0] = matrix[y][1] = matrix[y][2] = matrix[y][3] = matrix[y][col - 1] = matrix[y][col - 2] = matrix[y][col - 3] = matrix[y][col - 4] = 'X'
		self.matrix = matrix

	def get_matrix(self):
		return self.matrix

	def get_char(self,x,y):
		return self.matrix[x][y]
	def set_char(self,x,y,c):
		self.matrix[x][y] = c

	def render_board(self):
		for i in range(0, self.row):
			for j in range(0, self.col):
				print(self.matrix[i][j], end='')
			print("\n", end='')

	def render_empty(self, x, y):
		render(self,x,y, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ')

	def render_player(self, x, y):
		render(self,x,y, '\033[1;34m[\033[1;m', '\033[1;31m^\033[1;m', '\033[1;31m^\033[1;m', '\033[1;34m]\033[1;m', '\033[1;34m \033[1;m', '\033[1;34m]\033[1;m', '\033[1;34m[\033[1;m', '\033[1;34m \033[1;m')

	def render_horenemy(self, x, y):
		render(self,x,y, '\033[1;31m@\033[1;m', '\033[1;31m@\033[1;m', '\033[1;31m@\033[1;m', '\033[1;31m@\033[1;m', '\033[1;31m=\033[1;m', '\033[1;31m=\033[1;m', '\033[1;31m=\033[1;m', '\033[1;31m=\033[1;m')

	def render_verenemy(self, x, y):
		render(self,x,y, '\033[1;31m@\033[1;m', '\033[1;31m@\033[1;m', '\033[1;31m@\033[1;m', '\033[1;31m@\033[1;m', '\033[1;31m|\033[1;m', '\033[1;31m|\033[1;m', '\033[1;31m|\033[1;m', '\033[1;31m|\033[1;m')

	def render_bomb(self, x, y, frames):
		if frames == 4:
			render(self,x,y, '/', '-', '-', '\\', '\\', '-', '-', '/')
		if frames == 3:
			render(self,x,y, '/', '-', '-', '\\', '\\', '-', ' ', '/')
		if frames == 2:
			render(self,x,y, '/', '-', '-', '\\', '\\', ' ', ' ', '/')
		if frames == 1:
			render(self,x,y, '/', '-', ' ', '\\', '\\', ' ', ' ', '/')
	def render_explosion(self, x,y ):
		render(self, x,y, '\033[1;33mO\033[1;m', '\033[1;33mO\033[1;m', '\033[1;33mO\033[1;m', '\033[1;33mO\033[1;m', '\033[1;33mO\033[1;m', '\033[1;33mO\033[1;m', '\033[1;33mO\033[1;m', '\033[1;33mO\033[1;m')
		if self.matrix[x-2][y] != 'X':
			render(self, x-2,y, '\033[1;33m^\033[1;m', '\033[1;33m^\033[1;m', '\033[1;33m^\033[1;m', '\033[1;33m^\033[1;m', '\033[1;33m^\033[1;m', '\033[1;33m^\033[1;m', '\033[1;33m^\033[1;m', '\033[1;33m^\033[1;m')
		if self.matrix[x+2][y] != 'X':
			render(self, x+2,y, '\033[1;33mv\033[1;m', '\033[1;33mv\033[1;m', '\033[1;33mv\033[1;m', '\033[1;33mv\033[1;m', '\033[1;33mv\033[1;m', '\033[1;33mv\033[1;m', '\033[1;33mv\033[1;m', '\033[1;33mv\033[1;m')
		if self.matrix[x][y+4] != 'X':
			render(self, x,y+4, '\033[1;33m>\033[1;m', '\033[1;33m>\033[1;m', '\033[1;33m>\033[1;m', '\033[1;33m>\033[1;m', '\033[1;33m>\033[1;m', '\033[1;33m>\033[1;m', '\033[1;33m>\033[1;m', '\033[1;33m>\033[1;m')
		if self.matrix[x][y-4] != 'X':
			render(self, x,y-4,	'\033[1;33m<\033[1;m', '\033[1;33m<\033[1;m', '\033[1;33m<\033[1;m', '\033[1;33m<\033[1;m', '\033[1;33m<\033[1;m', '\033[1;33m<\033[1;m', '\033[1;33m<\033[1;m', '\033[1;33m<\033[1;m')
	def render_explosion_empty(self, x, y):
		if self.matrix[x-2][y] != 'X':
			render(self,x-2,y, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ')
		if self.matrix[x+2][y] != 'X':
			render(self,x+2,y, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ')
		if self.matrix[x][y-4] != 'X':
			render(self,x,y-4, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ')
		if self.matrix[x][y+4] != 'X':
			render(self,x,y+4, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ')
		render(self,x,y, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ')
#\033[1;31m
#\033[1;m