from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import QFT
import numpy as np

qc = QuantumCircuit(3)
qc.x([1,2])

qc.compose(QFT(3), range(3), inplace=True)
qc.compose(QFT(3, inverse=True), range(3), inplace=True)
qc.draw(output='mpl')