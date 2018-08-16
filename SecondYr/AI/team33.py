import copy

dim = 4
inf = float('inf')
def sub_matrix(matrix, index1, index2, dimension=dim):
        return [[matrix[i][j] for j in range(index2, index2 + dimension)] for i in range(index1, index1 + dimension)]

def evaluate_rows(matrix, ply):
    score = 0
    for row in matrix:
        score += 10 ** row.count(ply)
    return score / float(4 * 10 ** 4)

def evaluate_cols(matrix, ply):
    return evaluate_rows(zip(*matrix), ply)

def evaluate_diamonds(matrix, ply):
    score = 0
    submatrices = [sub_matrix(matrix, i, j, 3) for i in range(dim - 2) for j in range(dim - 2)]
    
    for mat in submatrices:
        count = 0
        if mat[0][1] == ply:
            count += 1
        if mat[1][0] == ply:
            count += 1
        if mat[1][2] == ply:
            count += 1
        if mat[2][1] == ply:
            count += 1
        score += 10 ** count
    
    return score / float(4 * 10 ** 4)

def win(matrix, ply):
    # Detect row win
    for row in matrix:
        if row.count(ply) == 4:
            return True
    # Detect col win
    for col in zip(*matrix):
        if col.count(ply) == 4:
            return True
    # Detect diam win
    submatrices = [sub_matrix(matrix, i, j, 3) for i in range(dim - 2) for j in range(dim - 2)]
    for mat in submatrices:
        count = 0
        if mat[0][1] == ply:
            count += 1
        if mat[1][0] == ply:
            count += 1
        if mat[1][2] == ply:
            count += 1
        if mat[2][1] == ply:
            count += 1
        if count == 4:
            return True
    # Lost, fegit
    return False

class Team33:
    def __init__(self):
        self.dim = 4
        self.matrix = None
        self.board = None
        self.block = None
        self.ply = None
   
    def move(self, board, old_move, flag):
        dim = self.dim
        # TODO Consider (-1, -1)
        self.ply = flag
        self.opp = 'x' if flag == 'o' else 'o'

        i = old_move[0] / 4
        j = old_move[1] / 4

        self.board_object = copy.deepcopy(board)
        self.board = self.board_object.board_status
        self.block = self.board_object.block_status
        self.matrix = sub_matrix(self.board, i, j)

        return self.find_best_move(old_move)

# LOCAL
    def evaluate_block(self, matrix):
        dim = self.dim
        score = 0.0

        if win(matrix, self.ply):
            return 1.0
        elif win(matrix, self.opp):
            return -1.0

        # Check rows
        score += evaluate_rows(matrix, self.ply)
        score -= evaluate_rows(matrix, self.opp)

        # Check cols
        score += evaluate_cols(matrix, self.ply)
        score -= evaluate_cols(matrix, self.opp)
        
        # Check diamond
        score += evaluate_diamonds(matrix, self.ply)
        score -= evaluate_diamonds(matrix,self.opp)

        # Nobody won / draw
        score /= 3.0 # Normalized b/w [-1, 1]
        # print 'Score of block', score
        return score

# GLOBAL
    def evaluate_board(self):
        score = 10 * self.evaluate_block(self.block) # Scaled by 10 to increase importance
        # 2D matrix of scores of individual submatrices
        submatrix_scores = [[self.evaluate_block(sub_matrix(self.board, i, j))\
            for j in range(0, dim * dim, dim)]\
            for i in range(0, dim * dim, dim)]

        # Center
        score += 3 * submatrix_scores[1][1]
        score += 3 * submatrix_scores[1][2]
        score += 3 * submatrix_scores[2][1]
        score += 3 * submatrix_scores[2][2]

        # Edges
        score += 4 * submatrix_scores[0][1]
        score += 4 * submatrix_scores[0][2]
        score += 4 * submatrix_scores[1][0]
        score += 4 * submatrix_scores[1][3]
        score += 4 * submatrix_scores[2][0]
        score += 4 * submatrix_scores[2][3]
        score += 4 * submatrix_scores[3][1]
        score += 4 * submatrix_scores[3][2]

        # Corners
        score += 6 * submatrix_scores[0][0]
        score += 6 * submatrix_scores[0][3]
        score += 6 * submatrix_scores[3][0]
        score += 6 * submatrix_scores[3][3]

        return score
        
    def minimax(self, depth, old_move, alpha=-inf, beta=inf, is_max=False):
        dim = self.dim
        i, j = old_move[0] / dim, old_move[1] / dim
        matrix = sub_matrix(self.board, i, j)

        # print(self.matrix)
        #score = self.evaluate_board()
        score = self.evaluate_block(matrix)
        if win(matrix, self.ply):
            return 1000
        elif win(matrix, self.opp):
            return -1000

        valid_moves = self.board_object.find_valid_move_cells(old_move)
        if valid_moves == []:
            return 0  # tie!

        if is_max:
            best = -inf
            ply = self.ply # player
        else:
            best = inf
            ply = self.opp # opponent

        for move in valid_moves:
            self.board_object.update(old_move, move, ply)
            if is_max:
                best = max(best, self.minimax(depth + 1, move, alpha, beta, not is_max))
                alpha = max(alpha, best)
            else:
                best = min(best, self.minimax(depth + 1, move, alpha, beta, not is_max))
                beta = min(best, beta)
            self.board_object.update(old_move, move, '-')  # Undo
            # Alpha beta check
            if beta <= alpha:
                break

        return best - depth

    def find_best_move(self, old_move):
        best_val = -inf
        best_move = [-1, -1]
        dim = self.dim

        moves = self.board_object.find_valid_move_cells(old_move)
        for move in moves:
            # Play
            i, j = move[0] % dim, move[1] % dim
            self.matrix[i][j] = self.ply
            # Evaluate
            move_val = self.minimax(0, old_move)
            print 'Move', move, 'Move Value', move_val
            # Undo
            self.matrix[i][j] = '-'
            if move_val > best_val:
                best_move = move
                best_val = move_val

        print 'Best Move', best_move
        return best_move
