from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import QFT
import numpy as np

qc = QuantumCircuit(3)
qc.x([1,2])

qft_c = QFT(3)
qc.compose(qft_c, range(3), inplace=True)
qc.draw(output='mpl')
