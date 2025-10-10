from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister

adj_rooms = [[1, 3], [0, 2, 4], [1, 5], [0, 4, 6], [1, 3, 5, 7], [2, 4, 8], [3, 7], [4, 6, 8], [5, 7]]

def switch_func(switch, rooms) :
  circuit = QuantumCircuit(switch, rooms)
  for i in range(9):
    circuit.cx(switch[i], rooms[i])
    for c in adj_rooms[i]:
      circuit.cx(switch[i], rooms[c])
    circuit.barrier()
  return circuit

def lights_oracle(qy, qr, qx):
  circuit = QuantumCircuit(qy, qr, qx)
  circuit.compose(switch_func(qx, qr), qx[:9]+qr[:9], inplace=True)
  circuit.mcx(qr, qy)
  circuit.compose(switch_func(qx, qr), qx[:9]+qr[:9], inplace=True)
  circuit.name = 'Oracle'
  return circuit

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

qr = QuantumRegister(9, name='r')
qx = QuantumRegister(9, name='x')
qy = QuantumRegister(1, name='y')
solution = ClassicalRegister(9, 'c')

circuit = QuantumCircuit(qy, qr, qx, solution)
circuit.x(qy)
circuit.h(qy)

rooms = [0, 0, 0, 1, 0, 1, 1, 1, 0]
for i in range(9):
  if rooms[i] == 1 :
    circuit.x(qr[i])
circuit.h(qx)

circuit.compose(lights_oracle(qy, qr, qx), qy[:]+qr[:]+qx[:], inplace=True)
circuit.barrier()
circuit.compose(diffuser_circuit(9), qx, inplace=True)
circuit.draw(output='mpl')