from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister

def grover_oracle_circuit():
  n = 3
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(n, 'x')
  qc = QuantumCircuit(qy, qx)

  qc.x([qx[1], qx[0]])
  qc.mcx(list(qx), qy)

  qc.x([qx[1], qx[0]])
  qc.name = 'Oracle'
  return qc

def diffuser_circuit(n) :
  x = QuantumRegister(n, 'x')
  qc = QuantumCircuit(x)
  qc.h(x)
  qc.x(x)

  qc.barrier()
  qc.h(x[0])
  qc.mcx(x[1:n], x[0])
  qc.h(x[0])
  qc.barrier()

  qc.x(x)
  qc.h(x)

  qc.name = 'Diffuser'
  return qc

n = 3
qx = QuantumRegister(n, 'x')
qy = QuantumRegister(1, 'y')
c = ClassicalRegister(n, 'c')

circuit = QuantumCircuit(qy, qx, c)
circuit.x(0)
circuit.h(0)
circuit.h(qx)

for _ in range (2):
  circuit.append(grover_oracle_circuit(), range(n+1))
  circuit.append(diffuser_circuit(n), range(1, n+1))

circuit.measure(qx, c)
circuit.draw(fold=-1, output='mpl')