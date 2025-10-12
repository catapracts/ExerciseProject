from qiskit import QuantumCircuit, QuantumRegister

def simon_oracle3(rc, ra):
  qc = QuantumCircuit(rc, ra)
  qc.cx(ra[1],rc[1])
  qc.cx(ra[0],rc[2])
  qc.cx(ra[2],rc[2])
  return qc

n = 3
ra = QuantumRegister(n, 'a')
rc = QuantumRegister(n, 'c')
qc = QuantumCircuit(rc, ra)

oracle = simon_oracle3(rc, ra)
oracle.draw(output='mpl')
