from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister

qr = QuantumRegister(9, name='r')
qx = QuantumRegister(9, name='x')
qy = QuantumRegister(1, name='y')
solution = ClassicalRegister(9, 'c')

circuit = QuantumCircuit(qy, qr, qx, solution)
circuit.x(qy)
circuit.h(qy)

adj_rooms = [[1, 3], [0, 2, 4], [1, 5], [0, 4, 6], [1, 3, 5, 7], [2, 4, 8], [3, 7], [4, 6, 8], [5, 7]]

def switch_func(switch, rooms) :
  circuit = QuantumCircuit(switch, rooms)
  for i in range(9):
    circuit.cx(switch[i], rooms[i])
    for c in adj_rooms[i]:
      circuit.cx(switch[i], rooms[c])
    circuit.barrier()
  return circuit

circuit.compose(switch_func(qx, qr), qx[:9]+qr[:9], inplace=True)
circuit.mcx(qr, qy)
circuit.draw(output='mpl', fold = -1)
