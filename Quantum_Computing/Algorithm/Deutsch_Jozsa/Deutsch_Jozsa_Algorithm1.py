from qiskit import QuantumCircuit, QuantumRegister
import numpy as np

def dj_oracle_const(n):
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(n, 'x')
  qc = QuantumCircuit(qy, qx)
  np.random.seed()
  x = np.random.randint(2)
  if x == 1 :
    qc.x(0)
  qc.name = 'DJ-const'
  return qc

circuit = dj_oracle_const(3)
circuit.draw(output='mpl')