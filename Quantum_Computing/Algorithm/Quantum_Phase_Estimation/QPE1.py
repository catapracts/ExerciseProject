from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.circuit.library import QFT
import numpy as np

t=3
n=1
qx = QuantumRegister(t, 'qx')
qy = QuantumRegister(n, 'qy')
c = ClassicalRegister(t, 'c')
qpe = QuantumCircuit(qx, qy, c)

phase = 1/8
qpe.x(qy)
qpe.barrier()
qpe.h(qx)
Un = 1
for qx_i in range(t):
  for i in range(Un):
    qpe.cp(2*np.pi*phase, qx[qx_i], qy)
  Un *= 2

qpe.compose(QFT(t, inverse=True), qx[:], inplace=True)
qpe.measure(qx, c)
qpe.draw(fold=-1, output='mpl')
