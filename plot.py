import matplotlib.pyplot as plt
import numpy as np

x = []
y = []

with open('points.txt', 'r') as f:
    page = f.read()
    lines = page.split('\n')

    for line in lines:
        if len(line.split(' ')) > 1:
            x.append(float(line.split(' ')[0]))
            y.append(float(line.split(' ')[1]))

with open('eqn.txt', 'r') as eqnfile:
    line = eqnfile.read()
    m = float(line.strip().split(' ')[0])
    b = float(line.strip().split(' ')[1])


g = np.linspace(min(x)-1, max(x)+1, 2)
f = (m * g) + b

plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.scatter(x, y)
plt.plot(g, f, color='#FF0000')
plt.show()
plt.close()
