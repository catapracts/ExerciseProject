from qiskit import QuantumCircuit, QuantumRegister
import numpy as np

def x_operator(n,k,r,checkZ):
  x_ops = np.zeros(shape=[k, 2*n], dtype=int)
  for row in range(k):
    for col in range(n-k-r):
      if checkZ[r+col][n-k+row] == '1':
        x_ops[row][r+col] = 1
  for row in range(k):
    x_ops[row][n-k+row] = 1
  for row in range(k):
    for col in range(r):
      if checkZ[col][n-k+row] == '1':
        x_ops[row][n+col] = 1
  return x_ops

def encoding_circuit(n, k ,r, checkX, checkZ):
  x_op = x_operator(n, k, r, checkZ)[0]
  print("X = ", x_op)
  qx = QuantumRegister(n)
  circuit = QuantumCircuit(qx)

  for i in range(r, n-k):
    if x_op[i] == 1:
      circuit.cx(qx[n-k], qx[i])
  for i in range(r):
    if x_op[n+i] == 1:
      circuit.cz(qx[n-k], qx[i])
  circuit.barrier()

  for i in range(r):
    circuit.h(qx[i])
    for j in range(n):
      if i == j:
        continue
      if checkX[i][j] == '1':
        circuit.cx(qx[i], qx[j])
      if checkZ[i][j] == '1':
        circuit.cz(qx[i], qx[j])
    circuit.barrier()
  
  circuit.name = 'encoder'
  return circuit

n = 7
k = 1
r = 3
qx = QuantumRegister(n, 'x')
circuit = QuantumCircuit(qx)

checkX = ['1001011', '0101101', '0011110', '0000000', '0000000', '0000000']
checkZ = ['0000000', '0000000', '0000000', '1111000', '1010101', '0110011']

circuit.x(qx[n-k])
circuit.barrier()

encoder = encoding_circuit(n, k, r, checkX, checkZ)
circuit.compose(encoder, qx, inplace=True)

circuit.draw(output='mpl', fold=-1, plot_barriers=False)
