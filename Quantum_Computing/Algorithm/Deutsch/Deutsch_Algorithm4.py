from qiskit import QuantumCircuit, QuantumRegister
def deutsch_oracle_circuit_notx():
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(1, 'x')
  qc = QuantumCircuit(qy, qx)
  qc.x(qx)
  qc.cx(qx, qy)
  qc.x(qx)
  qc.name = 'Deutsch_notx'
  return qc
circuit = deutsch_oracle_circuit_notx()
circuit.draw(output='mpl')