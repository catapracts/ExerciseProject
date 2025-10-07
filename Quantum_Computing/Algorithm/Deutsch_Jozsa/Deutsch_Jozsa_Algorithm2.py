from qiskit import QuantumCircuit, QuantumRegister
import numpy as np

def dj_oracle_balanced(n):
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(n, 'x')
  qc = QuantumCircuit(qy, qx)

  np.random.seed()
  k = np.random.randint(1, n+1)
  a = np.random.permutation(n)
  a = a[:k]
  print(a)
  for x in a :
    qc.cx(qx[x], qy)
  
  qc.name = 'DJ-balance'
  return qc

circuit = dj_oracle_balanced(3)
circuit.draw(output='mpl')