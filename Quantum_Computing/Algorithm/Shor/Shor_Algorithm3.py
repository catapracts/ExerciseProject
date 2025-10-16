from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit_aer import AerSimulator
import numpy as np
from qiskit.circuit.library import QFTGate
from math import gcd, lcm
from numpy.random import randint
from fractions import Fraction

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

def estimate_order(sampler, isa_circuit, t):
  job = sampler.run([isa_circuit], shots=1)
  result = job.result()
  count = result[0].data.c.get_counts()
  phase = list(count.keys())
  s_pre = int(phase[0], 2)
  r_pre = 1<<t
  f = Fraction(s_pre/r_pre).limit_denominator(N-1)
  return f.denominator

def confirm_order(a, r, N):
  return (a**r % N == 1)

r = estimate_order(sampler, isa_circuit, t)
if confirm_order(a, r, N):
  found = True
else:
  r1 = r
  r2 = estimate_order(sampler, isa_circuit, t)
  if confirm_order(a, r2, N):
    r = r2
    found = True
  else :
    r = lcm(r1, r2)
    if r >= N :
      found = True
    elif confirm_order(a, r, N):
      found = True
    else :
      found = False
  print(f"r1={r1} r2={r2} estimated r={r}")

if (found) :
  print(f"estimated value {r} is an order of {a} for {N}")
else :
  print(f"{r} is NOT an order of {a} for {N} because {a}^{r} % {N} = {a**r}")