from qiskit import QuantumCircuit
from math import gcd, lcm
from numpy.random import randint
import numpy as np

N = 21
n = 5
t = 2*n + 1
a = randint(2, N)
g = gcd(a, N)

two_power_n = 1 << n
U = np.eye(two_power_n)
for j in range(N):
  U[j][j] = 0
  U[(a*j)%N][j] = 1
qcU = QuantumCircuit(n)
qcU.unitary(U, range(n))
qcU.draw(output='mpl')