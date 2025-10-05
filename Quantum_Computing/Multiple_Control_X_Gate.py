from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit

def mcx_test(controls, targets):
  qc = QuantumCircuit(controls, targets)
  qc.cx(controls[0], targets[0], ctrl_state='0')
  qc.ccx(controls[0], controls[1], targets[1], ctrl_state='01')
  qc.mcx([controls[0], controls[1], controls[2], controls[3]], targets[2])
  qc.mcx(controls[0:4], targets[3], ctrl_state='0001')
  qc.name = 'mcx_test'
  return qc

qreg_c = QuantumRegister(4, 'controls')
qreg_t = QuantumRegister(4, 'targets')
qreg_etc = QuantumRegister(2, 'etc')
creg = ClassicalRegister(4, 'measure')
circuit = QuantumCircuit(qreg_c, qreg_t, qreg_etc, creg)

circuit.compose(mcx_test(qreg_c, qreg_t), qreg_c[0:4]+qreg_t[:4], inplace=True)
circuit.barrier()
circuit.compose(mcx_test(qreg_c, qreg_t).inverse(), range(2,10), inplace=True)
circuit.measure(qreg_t, range(3, -1, -1))
circuit.draw(output='mpl')
