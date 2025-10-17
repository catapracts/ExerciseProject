from qiskit import QuantumCircuit, QuantumRegister

qx = QuantumRegister(3, 'x')
qa = QuantumRegister(2, 'a')
circuit = QuantumCircuit(qx, qa)

circuit.x(qx[2])
circuit.barrier()

circuit.cx(qx[2], qx[0])
circuit.cx(qx[2], qx[1])
circuit.barrier()

circuit.x(qx[1])
circuit.barrier()

circuit.cx(qx[0], qa[0])
circuit.cx(qx[1], qa[0])
circuit.cx(qx[1], qa[1])
circuit.cx(qx[2], qa[1])
circuit.barrier()

circuit.ccx(qa[0], qa[1], qx[0], ctrl_state='01')
circuit.ccx(qa[0], qa[1], qx[1], ctrl_state='11')
circuit.ccx(qa[0], qa[1], qx[2], ctrl_state='10')

circuit.draw(output='mpl')