from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit_aer import AerSimulator
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

def error_detection_circuit(n, k, genX, genZ):
  qx = QuantumRegister(n)
  qa = QuantumRegister(n-k)
  circuit = QuantumCircuit(qx, qa)
  circuit.h(qa)
  for i in range(n-k):
    for j in range(n):
      if genX[i][j] == '1':
        circuit.cx(qa[i], qx[j])
      if genZ[i][j] == '1':
        circuit.cz(qa[i], qx[j])
      circuit.barrier()
  circuit.h(qa)
  circuit.name = 'detection'
  return circuit

n = 7
k = 1
r = 3
qx = QuantumRegister(n, 'x')
qa = QuantumRegister(n-k, 'a')
cr = ClassicalRegister(n-k, 's')
circuit = QuantumCircuit(qx, qa, cr)

genX = ['1111000', '1100110', '1010101', '0000000', '0000000', '0000000']
genZ = ['0000000', '0000000', '0000000', '1111000', '1100110', '1010101']

checkX = ['1001011', '0101101', '0011110', '0000000', '0000000', '0000000']
checkZ = ['0000000', '0000000', '0000000', '1111000', '1010101', '0110011']

circuit.x(qx[n-k])

encoder = encoding_circuit(n, k, r, checkX, checkZ)
circuit.append(encoder, qx)

circuit.z(qx[4])
circuit.x(qx[4])
circuit.barrier()

detector = error_detection_circuit(n, k, genX, genZ)
circuit.compose(detector, qx[:]+qa[:], inplace=True)
circuit.measure(qa, cr)

aer_sim = AerSimulator()
pm = generate_preset_pass_manager(backend=aer_sim, optimization_level=1)

isa_circuit = pm.run(circuit)
sampler = Sampler(mode=aer_sim)
job = sampler.run([isa_circuit], shots=1000)
result = job.result()
count = result[0].data.s.get_counts()
print(count)