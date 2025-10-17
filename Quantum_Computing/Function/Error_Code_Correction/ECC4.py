from qiskit import QuantumCircuit, QuantumRegister

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
circuit.draw(output='mpl', plot_barriers=False)
