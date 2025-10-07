from qiskit import QuantumCircuit, QuantumRegister
from numpy import random
def deutsch_oracle_circuit():
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(1, 'x')
  qc = QuantumCircuit(qy, qx)

  random.seed()
  f = random.randint(4)
  print('random number : ', f)
  if f == 0:
    pass
  elif f == 1:
    qc.x(qy)
  elif f == 2:
    qc.cx(qx, qy)
  else:
    qc.x(qx)
    qc.cx(qx, qy)
    qc.x(qx)

  qc.name = 'Deutsch'
  return qc

circuit = deutsch_oracle_circuit()
circuit.draw(output='mpl')