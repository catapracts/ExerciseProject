from qiskit import QuantumCircuit, QuantumRegister
import numpy as np

def bv_oracle_circuit(n):
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(n, 'x')
  qc = QuantumCircuit(qy, qx)

  np.random.seed()
  s = np.random.randint(2, size=n)
  print("s = ", s)

  for i in range(n):
    if s[i] == 1:
      qc.cx(qx[i], qy)
  
  qc.name = "BV Oracle"
  return qc

circuit = bv_oracle_circuit(5)
circuit.draw(output='mpl')