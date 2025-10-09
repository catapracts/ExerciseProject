from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister

def grover_oracle_circuit():
  n = 3
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(n, 'x')
  qc = QuantumCircuit(qy, qx)

  qc.x([qx[1], qx[0]])
  qc.mcx(list(qx), qy)

  qc.x([qx[1], qx[0]])
  qc.name = 'Oracle'
  return qc

circuit = grover_oracle_circuit()
circuit.draw(output='mpl')
