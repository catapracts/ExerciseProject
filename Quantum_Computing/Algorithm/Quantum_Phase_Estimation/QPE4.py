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
qc = QuantumCircuit(3)
qc.append(cUgate, [0,1,2])
qc.draw(output='mpl')