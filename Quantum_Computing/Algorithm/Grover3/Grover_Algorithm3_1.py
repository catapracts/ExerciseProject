from qiskit import QuantumCircuit, ClassicalRegister, QuantumRegister

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
circuit.draw(output='mpl', fold=-1)
