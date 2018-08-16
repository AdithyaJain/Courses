class Bomb:
	def __init__(self, x, y, frame = 5, exploded = False):
		self.x = x
		self.y = y
		self.frame = frame
		self.exploded = exploded

	def get_x(self):
		return self.x
	def get_y(self):
		return self.y
	def get_frame(self):
		return self.frame
	def get_exploded(self):
		return self.exploded
	def set_x(self,x):
		self.x = x
	def set_y(self,y):
		self.y = y
	def set_frame(self, frame):
		self.frame = frame
	def set_exploded(self, exploded):
		self.exploded = exploded