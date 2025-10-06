from qiskit import QuantumCircuit, QuantumRegister
def deutsch_oracle_circuit_x():
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(1, 'x')
  qc = QuantumCircuit(qy, qx)
  qc.cx(qx, qy)
  qc.name = 'Deutschx'
  return qc
circuit = deutsch_oracle_circuit_x()
circuit.draw(output='mpl')