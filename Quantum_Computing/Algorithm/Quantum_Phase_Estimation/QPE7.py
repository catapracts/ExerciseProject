from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.circuit.library import QFT, PhaseEstimation
from qiskit.visualization import array_to_latex
import numpy as np

U = [[np.exp(2j*np.pi/8), 0, 0, 0],
     [0, np.exp(2j*np.pi*2/8), 0, 0],
     [0, 0, np.exp(2j*np.pi*3/8), 0],
     [0, 0, 0, np.exp(2j*np.pi*4/8)]]

Ucircuit = QuantumCircuit(2)
Ucircuit.unitary(U, [0,1])

Ugate = Ucircuit.to_gate()
Ugate.name = "U"

t = 3
n = 2
qx = QuantumRegister(t, 'x')
qy = QuantumRegister(n, 'y')
c = ClassicalRegister(t, 'c')
qpe = QuantumCircuit(qx, qy, c)

qpe.x(qy[0])
qpe.append(PhaseEstimation(t, Ugate), qx[:]+qy[:])
qpe.measure(qx, reversed(c))
qpe.draw(output='mpl', fold=-1)
