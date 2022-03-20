import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def randomPoint(abscissaRange,ordinateRange):
	
	abscissa = abscissaRange*np.random.random()
	ordinate = ordinateRange*np.random.random()

	randomPoint = [abscissa,ordinate]

	return randomPoint

def isNumerator(point):
	
	isNumerator = False
	randomPointLength = point[0]**2 + point[1]**2

	if randomPointLength <= 1:
		isNumerator = True

	return isNumerator


def result(data,N):
	numerator = 0
	
	for index in range(N):
		
		point = data[index-1]
		
		if isNumerator(point):
			numerator+=1
		else:
			numerator=numerator

	return 4*numerator/N

N=10000
data = [randomPoint(1,1) for index in range(N)]
res = result(data,N)

x,y = zip(*data)


a = np.linspace(0,1,1000)
b = (1 - a**2)**(1/2)

fig,ax = plt.subplots(1)

ax.set_aspect('equal')
ax.set(xlim=(0, 1), xlabel='X')
ax.set(ylim=(0, 1), ylabel='Y')

plt.plot(x,y,'o',markersize=3,color='#1c9099')
plt.plot(a,b,color='black')
plt.text(0.5,0.5,'Pi = ' + str(res))

plt.show()

