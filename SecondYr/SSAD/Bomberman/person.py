def empty_block(board, x, y):
    board[x][y] = ' '
    board[x][y+1] = ' '
    board[x][y+2] = ' '
    board[x][y+3] = ' '
    board[x+1][y] = ' '
    board[x+1][y+1] = ' '
    board[x+1][y+2] = ' '
    board[x+1][y+3] = ' '

class Person:
    def __init__(self, x=2, y=4):
        self.x = x
        self.y = y


    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

    def set_x(self, x):
        self.x = x

    def set_y(self, y):
        self.y = y


class Player(Person):
    def __init__(self, score = 0, lives = 3):
        Person.__init__(self)
        self.score = score
        self.lives = lives

    def get_score(self):
        return self.score
    def set_score(self, score):
        self.score = score
    def get_lives(self):
    	return self.lives
    def set_lives(self, lives):
    	self.lives = lives


    def move_up(self, board):
        if board[self.x-2][self.y] != 'X' and board[self.x-2][self.y] != '\033[1;30m#\033[1;m':
            empty_block(board, self.x, self.y)
            self.set_x(self.get_x() -2)

    def move_down(self, board):
        if board[self.x+2][self.y] != 'X' and board[self.x+2][self.y] != '\033[1;30m#\033[1;m':
            empty_block(board, self.x, self.y)
            self.set_x(self.get_x() +2)

    def move_left(self, board):
        if board[self.x][self.y-4] != 'X' and board[self.x][self.y-4] != '\033[1;30m#\033[1;m':
            empty_block(board, self.x, self.y)
            self.set_y(self.get_y() -4)

    def move_right(self, board):
        if board[self.x][self.y+4] != 'X' and board[self.x][self.y+4] != '\033[1;30m#\033[1;m':
            empty_block(board, self.x, self.y)
            self.set_y(self.get_y() +4)


class Enemy(Person):
    def __init__(self,x,y, dead = False):
        Person.__init__(self,x,y)
        self.dead = dead

    def is_position(self, x, y):
        if self.x == x and self.y == y:
            True
        else:
            False
    def get_dead(self):
        return self.dead
    def set_dead(self, dead):
        self.dead = dead


class VerEnemy(Enemy):
    def __init__(self, x, y):
        Enemy.__init__(self, x, y)

    def move(self, board, flag):
        if flag == "up":
            if board[self.x-2][self.y] != 'X' and board[self.x-2][self.y] != '\033[1;30m#\033[1;m':
                empty_block(board, self.x, self.y)
                self.set_x(self.get_x() -2)
            else:
             flag = "down"

        if flag == "down":
            if board[self.x+2][self.y] != 'X' and board[self.x+2][self.y] != '\033[1;30m#\033[1;m':
                empty_block(board, self.x, self.y)
                self.set_x(self.get_x() +2)
            else:
                flag = "up"
                empty_block(board, self.x, self.y)
                self.set_x(self.get_x() -2)

        return flag;



class HorEnemy(Enemy):
    def __init__(self, x, y):
        Enemy.__init__(self, x, y)

    def move(self, board, flag):
        if flag == "left":
            if board[self.x][self.y-4] != 'X' and board[self.x][self.y-4] != '\033[1;30m#\033[1;m':
                empty_block(board, self.x, self.y)
                self.set_y(self.get_y() -4)
            else:
                flag = "right"

        if flag == "right":
            if board[self.x][self.y+4] != 'X' and board[self.x][self.y+4] != '\033[1;30m#\033[1;m':
                empty_block(board, self.x, self.y)
                self.set_y(self.get_y() +4)
            else:
                flag = "left"
                empty_block(board, self.x, self.y)
                self.set_y(self.get_y() -4)
        return flag