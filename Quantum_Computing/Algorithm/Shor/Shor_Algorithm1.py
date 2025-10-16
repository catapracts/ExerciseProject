from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.circuit.library import QFTGate
import numpy as np
from math import gcd
from numpy.random import randint

N = 21
n = 5
t = 2*n + 1
a = randint(2, N)
g = gcd(a, N)

qx = QuantumRegister(t, 'x')
qy = QuantumRegister(n, 'y')
c = ClassicalRegister(t, 'c')
qc_of = QuantumCircuit(qx, qy, c)
qc_of.x(qy[0])
qc_of.h(qx)

two_power_n = 1 << n
u_power = np.eye(two_power_n)
for j in range(N):
  u_power[j][j] = 0
  u_power[(a*j)%N][j] = 1

for i in range(t):
  qc_u_power = QuantumCircuit(n)
  qc_u_power.unitary(u_power, range(n))
  gate_u_power = qc_u_power.to_gate()
  gate_u_power.name = f'[*{a}mod{N}]^2^{i}'
  c_gate_u_power = gate_u_power.control(1)
  qc_of.append(c_gate_u_power, [qx[i]]+qy[:])
  u_power = u_power @ u_power
  qft_gate = QFTGate(num_qubits=t)
  inv_qft_gate = qft_gate.inverse()
  qc_of.append(inv_qft_gate, qx)

qc_of.measure(qx, c)
qc_of.draw(output='mpl', fold = -1)
