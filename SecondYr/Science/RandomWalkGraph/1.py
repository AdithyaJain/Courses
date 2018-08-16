import random as rd
from matplotlib import pyplot as graph
from math import *

def walk(steps):
	x=0
	for i in range(1, steps):
		if(rd.random() <0.5):
			x-=1
		else:
			x+=1
	return x

def prob(n, steps):
	fav = 0
	for i in range(1,n):
		disp1 = walk(steps)
		disp2 = walk(steps)
		if disp1 == disp2:
			fav+=1

	return fav/n

def analytical(steps):
	return (factorial(2*steps)/pow((pow(2,steps)*factorial(steps)),2))	

xaxis = []
yaxis = []
yaxis2 = []


r = int(input("Enter max limit to no of steps: "))


for i in range(0,r):
	xaxis.append(i)
	yaxis.append(prob(1000,i))
	yaxis2.append(analytical(i))

graph.plot(xaxis, yaxis, 'r')
graph.plot(xaxis, yaxis2, 'b')
graph.xlabel("No of steps")
graph.ylabel("Probability that the two meet")
graph.show()