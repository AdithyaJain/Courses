from board1 import *
from person import *
from bomb import *
import sys, termios, tty, os, time


def getch():
	fd = sys.stdin.fileno()
	old_settings = termios.tcgetattr(fd)
	try:
		tty.setraw(sys.stdin.fileno())
		ch = sys.stdin.read(1)

	finally:
		termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
	return ch

def check_contact_enemy(player_pos, enemy1_pos, enemy1):
	if (player_pos == enemy1_pos) and (enemy1.get_dead() == False):
		return True
	else:
		return False

def death(player):
	os.system('clear')
	print("SCORE: ", end='')
	print(player.score)

def check_enemy_died(enemy1, bomb_coord1, bomb_coord2, bomb_coord3, bomb_coord4, bomb_coord5):
	if enemy1.get_dead() == False and ((enemy1.get_x(), enemy1.get_y()) == bomb_coord1 or (enemy1.get_x(), enemy1.get_y()) == bomb_coord2 or (enemy1.get_x(), enemy1.get_y()) == bomb_coord3 or (enemy1.get_x(), enemy1.get_y()) == bomb_coord4 or (enemy1.get_x(), enemy1.get_y()) == bomb_coord5):
		return True
	else:
		return False

def check_bomb_death(board, player, enemy1, enemy2, enemy3, enemy4, bomb):
	score = 0
	playerdead = False
	bomb_coord1 = (bomb.get_x(), bomb.get_y())
	bomb_coord2 = (bomb.get_x() - 2, bomb.get_y())
	bomb_coord3 = (bomb.get_x() + 2, bomb.get_y())
	bomb_coord4 = (bomb.get_x(), bomb.get_y() + 4)
	bomb_coord5 = (bomb.get_x(), bomb.get_y() - 4)
	if check_enemy_died(enemy1, bomb_coord1, bomb_coord2, bomb_coord3, bomb_coord4, bomb_coord5):
		enemy1.set_dead(True)
		score += 100
	if check_enemy_died(enemy2, bomb_coord1, bomb_coord2, bomb_coord3, bomb_coord4, bomb_coord5):
		enemy2.set_dead(True)
		score += 100
	if check_enemy_died(enemy3, bomb_coord1, bomb_coord2, bomb_coord3, bomb_coord4, bomb_coord5):
		enemy3.set_dead(True)
		score += 100
	if check_enemy_died(enemy4, bomb_coord1, bomb_coord2, bomb_coord3, bomb_coord4, bomb_coord5):
		enemy4.set_dead(True)
		score += 100

	if board.get_matrix()[bomb_coord1[0]][bomb_coord1[1]] == '\033[1;30m#\033[1;m':
		score += 20
	if board.get_matrix()[bomb_coord2[0]][bomb_coord2[1]] == '\033[1;30m#\033[1;m':
		score += 20
	if board.get_matrix()[bomb_coord3[0]][bomb_coord3[1]] == '\033[1;30m#\033[1;m':
		score += 20
	if board.get_matrix()[bomb_coord4[0]][bomb_coord4[1]] == '\033[1;30m#\033[1;m':
		score += 20
	if board.get_matrix()[bomb_coord5[0]][bomb_coord5[1]] == '\033[1;30m#\033[1;m':
		score += 20

	if (player.get_x(), player.get_y()) == bomb_coord1 or (player.get_x(), player.get_y()) == bomb_coord2 or (player.get_x(), player.get_y()) == bomb_coord3 or (player.get_x(), player.get_y()) == bomb_coord4 or (player.get_x(), player.get_y()) == bomb_coord5:
		player.set_lives(player.get_lives()-1)
		player.set_x(2)
		player.set_y(4)
	return (score, playerdead)


board = Board(40, 80)
player = Player()
player_current = (player.get_x, player.get_y)
enemy1 = VerEnemy(26,36)
enemy1_current = (enemy1.get_x, enemy1.get_y)
flag1 = "down"
enemy2 = HorEnemy(10,20)
enemy2_current = (enemy2.get_x, enemy2.get_y)
flag2 = "left"
enemy3 = HorEnemy(22,28)
enemy3_current = (enemy3.get_x, enemy3.get_y)
flag3 = "right"
enemy4 = HorEnemy(34,60)
enemy4_current = (enemy4.get_x, enemy4.get_y)
flag4 = "left"
bomb = Bomb(2,8,-2, True)






while (True):
# Rendering
	os.system('clear')
	
	if enemy1.get_dead() == True:
		board.render_empty(enemy1.get_x(), enemy1.get_y())
	if enemy2.get_dead() == True:
		board.render_empty(enemy2.get_x(), enemy2.get_y())
	if enemy3.get_dead() == True:
		board.render_empty(enemy3.get_x(), enemy3.get_y())
	if enemy4.get_dead() == True:
		board.render_empty(enemy4.get_x(), enemy4.get_y())
	if bomb.exploded == True:
		if bomb.get_frame() == 0:
			board.render_explosion(bomb.get_x(), bomb.get_y())
		elif bomb.get_frame() == -1:
			board.render_explosion_empty(bomb.get_x(), bomb.get_y())
		else:
			board.render_empty(bomb.get_x(), bomb.get_y())
	if bomb.exploded == False:
		board.render_bomb(bomb.get_x(), bomb.get_y(), bomb.get_frame())
	if enemy1.get_dead() == False:
		board.render_verenemy(enemy1.get_x(), enemy1.get_y())
	if enemy2.get_dead() == False:
		board.render_horenemy(enemy2.get_x(), enemy2.get_y())
	if enemy3.get_dead() == False:
		board.render_horenemy(enemy3.get_x(), enemy3.get_y())
	if enemy4.get_dead() == False:
		board.render_horenemy(enemy4.get_x(), enemy4.get_y())
	board.render_player(player.get_x(), player.get_y())
	board.render_board()
	print("Lives: ", end='')
	print(player.get_lives())
	print("Score: ",end='')
	print(player.get_score())


# Player movement
	press = getch()
	if press == 'w':
		player.move_up(board.get_matrix())
	if press == 's':
		player.move_down(board.get_matrix())
	if press == 'a':
		player.move_left(board.get_matrix())
	if press == 'd':
		player.move_right(board.get_matrix())
	if press == 'q':
		os.system('clear')
		break
	player_current = (player.get_x(), player.get_y())

# Bomb
	if press == 'b' and bomb.get_frame() < 0:
		bomb = Bomb(player.get_x(), player.get_y())

# Check if player comes in contact with enemy
	if check_contact_enemy(player_current, enemy1_current, enemy1) or check_contact_enemy(player_current, enemy2_current, enemy2) or check_contact_enemy(player_current, enemy3_current, enemy3) or check_contact_enemy(player_current, enemy4_current, enemy4):
		if player.get_lives() == 1:
			death(player)
			print("You Died")
			break
		else:
			player.set_lives(player.get_lives() - 1)
			player.set_x(2)
			player.set_y(4)

# Enemy moving
	flag1 = enemy1.move(board.get_matrix(), flag1)
	flag2 = enemy2.move(board.get_matrix(), flag2)
	flag3 = enemy3.move(board.get_matrix(), flag3)
	flag4 = enemy4.move(board.get_matrix(), flag4)
	enemy1_current = (enemy1.get_x(), enemy1.get_y())
	enemy2_current = (enemy2.get_x(), enemy2.get_y())
	enemy3_current = (enemy3.get_x(), enemy3.get_y())
	enemy4_current = (enemy4.get_x(), enemy4.get_y())

# Check if player comes in contact with enemy
	if check_contact_enemy(player_current, enemy1_current, enemy1) or check_contact_enemy(player_current, enemy2_current, enemy2) or check_contact_enemy(player_current, enemy3_current, enemy3) or check_contact_enemy(player_current, enemy4_current, enemy4):
		if player.get_lives() == 1:
			death(player)
			print("You Died")
			break
		else:
			player.set_lives(player.get_lives() - 1)
			player.set_x(2)
			player.set_y(4)


	if enemy1.get_dead() == True and enemy2.get_dead() == True and enemy3.get_dead() == True and enemy4.get_dead() == True:
		death(player)
		print("You win")
		break
# Bomb Logic
	bomb.set_frame(bomb.get_frame() - 1)
	if bomb.get_frame() == 0 and bomb.get_exploded() == False:
		result = check_bomb_death(board, player, enemy1, enemy2, enemy3, enemy4, bomb)
		bomb.set_exploded(True)
		player.set_score(player.get_score() + result[0])
		if result[1]:
			death(player)
			break