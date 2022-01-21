import numpy as np
import matplotlib.pyplot as plotter
import math

x = []
y = []
num = 0

with open('threadstest.csv' ,'r') as file:
	for eachline in file:
		splat = eachline.split(',')
		if splat[0] == '1':
			y.append(0 if float(splat[2]) == 0 else math.log(float(splat[2]), 10))
			x.append(float(splat[1]))
			num += 1
		else:
			continue

c = ['green' for x in range(num)]

plotter.scatter(np.array(x), np.array(y), c = c, alpha = 0.05)
plotter.show()