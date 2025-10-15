from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.circuit.library import QFT
import numpy as np
from qiskit.visualization import array_to_latex

U = [[np.exp(2j*np.pi/8), 0, 0, 0],
     [0, np.exp(2j*np.pi*2/8), 0, 0],
     [0, 0, np.exp(2j*np.pi*3/8), 0],
     [0, 0, 0, np.exp(2j*np.pi*4/8)]]

Ucircuit = QuantumCircuit(2)
Ucircuit.unitary(U, [0,1])

Ugate = Ucircuit.to_gate()
Ugate.name = "U"

cUgate = Ugate.control(1)

t = 3
n = 2
qx = QuantumRegister(t, 'x')
qy = QuantumRegister(n, 'y')
c = ClassicalRegister(t, 'c')
qpe = QuantumCircuit(qx, qy, c)

qpe.x(qy[0])
qpe.barrier()
qpe.h(qx)
Un = 1
for qx_i in range(t):
  for i in range(Un):
    qpe.append(cUgate, [qx[qx_i], qy[0], qy[1]])
  Un *= 2

qpe.compose(QFT(t, inverse=True), qx[:], inplace=True)
qpe.measure(qx, c)
qpe.draw(fold=-1, output='mpl')
