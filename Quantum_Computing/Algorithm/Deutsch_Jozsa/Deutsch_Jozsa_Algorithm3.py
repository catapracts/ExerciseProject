from qiskit import QuantumCircuit, QuantumRegister
import numpy as np

def dj_oracle(n):
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(n, 'x')
  qc = QuantumCircuit(qy, qx)
  np.random.seed()
  condition = np.random.choice(['constant', 'balanced'])
  print(condition)

  if condition == 'constant' :
    x = np.random.randint(2)
    print(x)
    if x==1 :
      qc.x(qy)

  else : 
    k = np.random.randint(1, n+1)
    a = np.random.permutation(n)
    a = a[:k]
    print(a)
    for x in a :
      qc.cx(qx[x], qy)
  
  qc.name = 'DJ-Oracle'
  return qc

circuit = dj_oracle(3)
circuit.draw(output='mpl')