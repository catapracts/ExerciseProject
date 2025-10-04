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
circuit = QuantumCircuit(qreg_q, creg_c)

circuit.x([qreg_q[2], qreg_q[3]])
circuit.barrier()
c_ha = half_adder(4)
circuit.compose(c_ha, range(2, 6), inplace=True)
circuit.barrier()
circuit.compose(c_ha.inverse(), range(2,6), inplace=True)
circuit.barrier()
circuit.measure(range(2,6), creg_c)
circuit.draw(output='mpl')
