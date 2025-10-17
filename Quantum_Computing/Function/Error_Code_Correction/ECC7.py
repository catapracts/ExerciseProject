from qiskit import QuantumCircuit, QuantumRegister
from qiskit.quantum_info import Statevector

qx = QuantumRegister(3, 'x')
qa = QuantumRegister(2, 'a')
circuit = QuantumCircuit(qx, qa)

circuit.x(qx[2])
circuit.barrier()

circuit.cx(qx[2], qx[0])
circuit.cx(qx[2], qx[1])
circuit.barrier()
circuit.h(qx)

circuit.z(qx[2])

circuit.barrier()
circuit.h(qx)
circuit.cx(qx[0], qa[0])
circuit.cx(qx[1], qa[0])
circuit.cx(qx[1], qa[1])
circuit.cx(qx[2], qa[1])
circuit.barrier()
circuit.h(qx)

sv = Statevector(circuit)
sv.draw(output='latex')
