from cashflowModel import * 
import numpy as np

n = len(z)
k = np.arange(n)

#frq = k/T
#frq = frq[range(int(n/2))]


Y = np.fft.fft(y)

plt.plot(abs(Y))
plt.show()
