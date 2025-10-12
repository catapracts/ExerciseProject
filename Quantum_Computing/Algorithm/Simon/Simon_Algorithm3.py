from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit_aer import AerSimulator

def simon_oracle3(rc, ra):
  qc = QuantumCircuit(rc, ra)
  qc.cx(ra[1],rc[1])
  qc.cx(ra[0],rc[2])
  qc.cx(ra[2],rc[2])
  return qc

n = 3
ra = QuantumRegister(n, 'a')
rc = QuantumRegister(n, 'c')
rma = ClassicalRegister(n, 'ma')
rmc = ClassicalRegister(n, 'mc')
qc = QuantumCircuit(rc, ra, rmc, rma)

qc.h(ra)
qc.barrier()
qc.compose(simon_oracle3(rc, ra), range(2*n), inplace=True)
qc.barrier()
qc.measure(rc, rmc)
qc.barrier()
qc.h(ra)
qc.barrier()
qc.measure(ra, rma)

aer_sim = AerSimulator()
pm = generate_preset_pass_manager(backend=aer_sim, optimization_level=1)
isa_circuit = pm.run(qc)
sampler = Sampler(mode=aer_sim)
job = sampler.run([isa_circuit], shots=2)
result = job.result()
count = result[0].data.ma.get_counts()
print(count)
