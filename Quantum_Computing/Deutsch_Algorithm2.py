from qiskit import QuantumCircuit, QuantumRegister
def deutsch_oracle_circuit1():
  qy = QuantumRegister(1, 'y')
  qx = QuantumRegister(1, 'x')
  qc = QuantumCircuit(qy, qx)
  qc.x(qy)
  qc.name = 'Deutsch1'
  return qc
circuit = deutsch_oracle_circuit1()
circuit.draw(output='mpl')