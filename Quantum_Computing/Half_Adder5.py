from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit

def half_adder(n):
  qr = QuantumRegister(n)
  circuit = QuantumCircuit(qr)
  circuit.cx(qr[0], qr[2])
  circuit.cx(qr[1], qr[2])
  circuit.ccx(qr[0], qr[1], qr[2])
  circuit.name = 'half_adder'
  return circuit

qreg_q = QuantumRegister(8, 'q')
creg_c = ClassicalRegister(4, 'c')
circuit = QuantumCircuit(qreg_q)

circuit.x([qreg_q[2], qreg_q[3]])
circuit.barrier()
circuit.compose(half_adder(4), qreg_q[2:4]+qreg_q[5:6]+qreg_q[7:8], inplace=True)

circuit.measure_all()
circuit.draw(output='mpl')
