from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister

qt = QuantumRegister(1, 'target')
qc = QuantumRegister(2, 'control')
cr = ClassicalRegister(3, 'm')
circuit = QuantumCircuit(qt, qc, cr)

circuit.x(qt)
circuit.x(qc)

circuit.barrier()

circuit.ccx(qc[1], qc[0], qt)

circuit.measure([0, 1, 2], cr)

circuit.draw(output='mpl')
