from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit

def half_adder(n):
  qr = QuantumRegister(n)
  circuit = QuantumCircuit(qr)
  circuit.cx(qr[0], qr[2])
  circuit.cx(qr[1], qr[2])
  circuit.ccx(qr[0], qr[1], qr[2])
  circuit.name = 'half_adder'
  return circuit

qreg_q = QuantumRegister(4, 'q')
creg_c = ClassicalRegister(4, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)

circuit.x(qreg_q[0:2])
circuit.barrier()
circuit.compose(half_adder(4), range(4), inplace=True)
circuit.measure(qreg_q, creg_c)
circuit.draw(output='mpl')
