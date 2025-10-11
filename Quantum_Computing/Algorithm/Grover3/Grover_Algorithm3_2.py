from qiskit import QuantumCircuit, ClassicalRegister, QuantumRegister

adj_rooms = [[1, 3], [0, 2, 4], [1, 5], [0, 4, 6], [1, 3, 5, 7], [2, 4, 8], [3, 7], [4, 6, 8], [5, 7]]

def switch_func3(switch, rooms):
  circuit = QuantumCircuit(switch, rooms)
  for row in range(3):
    for i in range(3*row, 3*row+3):
      circuit.cx(switch[i], rooms[i])
      for c in adj_rooms[i]:
        circuit.cx(switch[i], rooms[c])
    circuit.barrier()
    if row == 2: break
    for j in range(3*row, 3*row+3):
      circuit.cx(rooms[j], switch[j+3], ctrl_state=0)
    circuit.barrier()
  circuit.name = 'Switch3'
  return circuit

qr = QuantumRegister(9, 'r')
qx = QuantumRegister(9, 'x')
qy = QuantumRegister(1, 'y')
c = ClassicalRegister(3, 'c')

circuit = QuantumCircuit(qy, qr, qx, c)
circuit.x(qy)
circuit.h(qy)

rooms = [0, 0, 0, 1, 0, 1, 1, 1, 0]
for i in range(9):
  if rooms[i] == 1 :
    circuit.x(qr[i])

circuit.h(qx[:3])

circuit.barrier()
circuit.compose(switch_func3(qx, qr), qx[:9]+qr[:9], inplace=True)
circuit.draw(output='mpl', fold=-1, plot_barriers=False)
