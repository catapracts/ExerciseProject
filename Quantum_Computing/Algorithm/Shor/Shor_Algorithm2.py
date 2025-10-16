from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit_aer import AerSimulator
import numpy as np
from qiskit.circuit.library import QFTGate
from math import gcd, lcm
from numpy.random import randint

N = 21
n = 5
t = 2*n + 1
a = randint(2, N)
g = gcd(a, N)

qx = QuantumRegister(t, 'x')
qy = QuantumRegister(n, 'y')
c = ClassicalRegister(t, 'c')
qc_of = QuantumCircuit(qx, qy, c)
qc_of.x(qy[0])
qc_of.h(qx)

two_power_n = 1 << n
u_power = np.eye(two_power_n)
for j in range(N):
  u_power[j][j] = 0
  u_power[(a*j)%N][j] = 1

for i in range(t):
  qc_u_power = QuantumCircuit(n)
  qc_u_power.unitary(u_power, range(n))
  gate_u_power = qc_u_power.to_gate()
  gate_u_power.name = f'[*{a}mod{N}]^2^{i}'
  c_gate_u_power = gate_u_power.control(1)
  qc_of.append(c_gate_u_power, [qx[i]]+qy[:])
  u_power = u_power @ u_power
  qft_gate = QFTGate(num_qubits=t)
  inv_qft_gate = qft_gate.inverse()
  qc_of.append(inv_qft_gate, qx)

qc_of.measure(qx, c)

aer_sim = AerSimulator()
pm = generate_preset_pass_manager(backend=aer_sim, optimization_level=1)
isa_circuit = pm.run(qc_of)
sampler = Sampler(mode=aer_sim)
job = sampler.run([isa_circuit], shots = 1)
result = job.result()
count = result[0].data.c.get_counts()
print(count)

phase = list(count.keys())
print("measured output state = ", phase[0])
