from qiskit import QuantumCircuit, QuantumRegister
from qiskit.quantum_info import Statevector
import numpy as np

qr = QuantumRegister(3, 'x')
qc = QuantumCircuit(qr)

qc.x(qr[1:3])
qc.barrier()

qc.h(2)
qc.cp(np.pi/2, 1, 2)
qc.cp(np.pi/4, 0, 2)
qc.h(1)
qc.cp(np.pi/2, 0, 1)
qc.h(0)

sv = Statevector(qc)
sv.draw(output='latex')
#pip install ipython
#pip install sympy
