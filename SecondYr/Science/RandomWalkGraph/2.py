import random as rd
from math import *
from matplotlib import pyplot as graph


def disp(steps):
	x=0
	y=0
	z=0
	for i in range(1,steps):
#random gives [0,1] and we need [0,2*pi]
		phi = rd.random() * 2 * pi
		theta = rd.random() * pi
		x += sin(theta) * cos(phi)
		y += sin(theta) * sin(phi)
		z += cos(phi)

	return sqrt(x*x + y*y + z*z)


def prob(steps, drunks, r):  #n is iterations, steps is no of steps, drunks is no of drunks
	fav = 0
	for j in range(1,drunks):
		if disp(steps) >= r:
			fav += 1
	return fav

xaxis = []
yaxis = []

drunks = int(input("Enter number of drunks: "))
steps = int(input("Enter number of steps: "))
r = int(input("Max range of displacement from origin: "))

for i in range(0,r):
	xaxis.append(i)
	yaxis.append(prob(steps, drunks, i))

graph.plot(xaxis, yaxis)
graph.xlabel("R")
graph.ylabel("Number of drunks whose displacement is greater than R")
graph.show()