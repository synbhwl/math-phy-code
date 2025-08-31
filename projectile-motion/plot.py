import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter

with open("projectile-motion/positions.txt") as f:
    content = f.read()

position_list = content.split("\n")

x = []
y = []

fig, ax = plt.subplots()

line, = ax.plot(0, 0, 'o', markersize=15, color='#FF0000')

for position in position_list:
    if len(position) > 1:
        x.append(float(position.split(" ")[0]))
        y.append(float(position.split(" ")[1]))

ax.set_xlim(min(x)-1, max(x)+1)
ax.set_ylim(min(y)-1, max(y)+1)
ax.set_xlabel("Distance")
ax.set_ylabel("Height")

    
def animate(i):
    line.set_data(x[i], y[i])
    return line,

ani = FuncAnimation(fig, animate, frames=len(x), interval=20, blit=True)

# writer = PillowWriter(fps=30)
# ani.save("projectile-motion/ball.gif", writer=writer)

plt.show()
plt.close()