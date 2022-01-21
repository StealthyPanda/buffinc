#from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plotter
import math

fig = plotter.figure()

threedplot = plotter.axes(projection= '3d')

"""x = np.outer(np.linspace(-2, 2, 100), np.ones(100))
y = x.copy().T
z = np.cos(x ** 2 + y ** 3)
"""

x=[]
y=[]
z=[]

with open('threadstest.csv', 'r') as file:
	for eachline in file:
		splat = eachline.split(',')
		#x.append(math.log(float(splat[0])))
		#y.append(math.log(float(splat[1])))
		z.append(0 if float(splat[2]) == 0 else math.log(float(splat[2]), 10))
		y.append(float(splat[1]))
		x.append(float(splat[0]))

def avg(buffx, buffy):
	global x, y, z
	indices = []
	average = 0
	num = 0
	for index in range(len(z)):
		if (buffx == x[index]) and (buffy == y[index]):
			average += z[index]
			num+=1
	average = average/num
	return average

c = [[1 * (1 if (z[index] < avg(x[index], y[index])) else 0), 1 * (1 if (z[index] >= avg(x[index], y[index])) else 0), 0] for index in range(len(x))]
print(c)

threedplot.scatter(x, y, z, c = c)
#threedplot.set_title("BRUH")
plotter.show()