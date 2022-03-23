import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


#-------------------------------------------------------------------------------
#	Author: Evan M. Cornuelle 						
#	Date: 02/27/2022							
#																				#
#	Description: Animnate a Monte-Carlo simulation for the calculation of Pi
#																				#
#-------------------------------------------------------------------------------

#Global variables											
N=1000											#Number of data points
time = 10										#Animation time in s !not working!
dt = time/N 										#Time incremebt for animation !not working!
numerator = []										#Inside circle array

#Set up the figure pane
fig, ax = plt.subplots(1,figsize=(7, 7))						#Set figure size				
ax.set_aspect('equal')									#Set the aspect ratio of the figure to 1:1
ax.set_xlim(0, 1), ax.set_xticks([])							#Set axes limits to [0,1] and remove all tics
ax.set_ylim(0, 1), ax.set_yticks([])


#Create data 
points = np.random.uniform(0,1,(N,2))							#Generate random (x,y) values


#Construct the scatter plot for animation
a = np.linspace(0,1,1000)								#Create x-data to plot circle
b = (1 - a**2)**(1/2)									#Calculate y-data for circle
ax.plot(a,b,'k-')									#Plot circle as a black line

scatter, = ax.plot([],[],'o',markersize=3,color='#1c9099')				#Empty scatter plot for animation
historyX, historyY = [], []								#Empty list to store animation history


#Update plot with rolling calculation of Pi
pi_template = r'$\pi = \frac{%i}{%i} = %f$'
text = ax.text(0.1, 0.9,'',math_fontfamily='dejavuserif')

for i in range(N):									#Find if random point is inside circle
	randomPointLength = points[i,0]**2 + points[i,1]**2
	numerator.append(not(np.floor(randomPointLength)))				#If floor == 0, append 1. If floor == 1 append 0

num = np.cumsum(numerator)								#Number of points in circle is cumsum(numerator)



#Function that will update the animation
def animate(i):

	historyX.append(points[i,0])
	historyY.append(points[i,1])

	scatter.set_data(historyX,historyY)
	text.set_text(pi_template %(num[i],(i+1),4*num[i]/(i+1)))

	return scatter, text
	

#Animate
ani = animation.FuncAnimation(fig,animate,frames = N,interval=1000*dt,blit=True,repeat=False)

#Show the plot
plt.show()


