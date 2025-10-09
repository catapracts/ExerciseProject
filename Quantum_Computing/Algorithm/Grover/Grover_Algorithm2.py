from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister

def diffuser_circuit(n) :
  x = QuantumRegister(n, 'x')
  qc = QuantumCircuit(x)
  qc.h(x)
  qc.x(x)

  qc.barrier()
  qc.h(x[0])
  qc.mcx(x[1:n], x[0])
  qc.h(x[0])
  qc.barrier()

  qc.x(x)
  qc.h(x)

  qc.name = 'Diffuser'
  return qc

circuit = diffuser_circuit(3)
circuit.draw(output='mpl')