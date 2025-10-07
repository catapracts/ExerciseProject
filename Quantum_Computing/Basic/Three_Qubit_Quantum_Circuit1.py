from qiskit import QuantumCircuit
circuit = QuantumCircuit(3,3)

circuit.x(0)
circuit.x([2,1])

circuit.barrier()

circuit.ccx(2, 1, 0)

circuit.measure([0, 1, 2], [0, 1, 2])

circuit.draw(output='mpl')
circuit.draw(output='mpl', fold=-1)
