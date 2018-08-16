class Board:
    def __init__(self, col, row):
        self.row = row
        self.col = col

        # Initialize blank board
        matrix = [[' ' for y in range(col)] for x in range(row)]
        self.matrix = matrix

    def print(self):
        for i in range(0, self.row):
            for j in range(0, self.col):
                print(self.matrix[i][j], end='')
            print("\n", end='')

    def render_empty(self, x, y):
        self.matrix[x][y] = ' '

    def render_obs(self, x, y):
        self.matrix[x][y] = 'o'

    def render_target(self, x, y):
        self.matrix[x][y] = '.'
