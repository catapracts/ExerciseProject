from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit

def half_adder(n):
  qr = QuantumRegister(n)
  circuit = QuantumCircuit(qr)
  circuit.cx(qr[0], qr[2])
  circuit.cx(qr[1], qr[2])
  circuit.ccx(qr[0], qr[1], qr[3])
  circuit.name = 'half_adder'
  return circuit

qreg_q = QuantumRegister(4, 'q')
creg_c = ClassicalRegister(4, 'c')
circuit = QuantumCircuit(qreg_q, creg_c)

circuit.x([qreg_q[0], qreg_q[1]])
circuit.barrier()
c_ha = half_adder(4)
circuit.append(c_ha, [0, 1, 2, 3])
circuit.measure(qreg_q, creg_c)
circuit.draw(output='mpl')