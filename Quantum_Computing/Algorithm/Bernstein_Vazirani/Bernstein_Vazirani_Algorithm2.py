from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
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

n = 5
qx = QuantumRegister(n, 'x')
qy = QuantumRegister(1, 'y')
c = ClassicalRegister(n, 'c')

circuit = QuantumCircuit(qy, qx, c)
circuit.x(qy)
circuit.h(qy)
circuit.h(qx)
circuit.barrier()

circuit.compose(bv_oracle_circuit(n), range(n+1), inplace=True)
circuit.barrier()
circuit.h(qx)
circuit.measure(qx, reversed(c))
circuit.draw(output='mpl')