from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister

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
circuit.draw(output='mpl')
