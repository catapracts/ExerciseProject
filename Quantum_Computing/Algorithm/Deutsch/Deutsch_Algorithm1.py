from qiskit import QuantumCircuit, QuantumRegister
def deutsch_oracle_circuit0():
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(1, 'x')
  qc = QuantumCircuit(qy, qx)
  qc.name = 'Deutsch0'
  return qc
circuit = deutsch_oracle_circuit0()
circuit.draw(output='mpl')