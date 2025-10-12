from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit_aer import AerSimulator
import numpy as np

def simon_oracle3(rc, ra):
  qc = QuantumCircuit(rc, ra)
  qc.cx(ra[1],rc[1])
  qc.cx(ra[0],rc[2])
  qc.cx(ra[2],rc[2])
  return qc

def rank_mod2(matrix):
  rows, cols = matrix.shape
  rank = 0
  for c in range(cols):
    for r in range(rank, rows):
      if matrix[r, c] != 0:
        if r != rank:
          matrix[[rank, r]] = matrix[[r, rank]]
        for k in range(rank+1, rows):
          if matrix[k, c] == 1:
            matrix[k] ^= matrix[rank]
        rank += 1
        break
  return rank

def indep(sys, e):
  sys.append(e)
  matrix = np.array(sys)
  n = len(sys)
  if rank_mod2(matrix) == n:
    return True
  else:
    sys.pop()
    return False

def ge_mod2(A):
  n = len(A)+1
  matrix = np.matrix(A)

  for i in range(n-1):
    pivot = i
    while pivot < (n-1) and matrix[pivot, i] == 0:
      pivot += 1
    if pivot < (n-1):
      matrix[[i, pivot]] = matrix[pivot, i]
      for j in range(i+1, n-1):
        if matrix[j, i] == 1:
          matrix[j] ^= matrix[i]
  return matrix

def back_substitution_mod2(matrix):
  _, n = matrix.shape
  x = -2*np.ones(n, dtype=int)
  x[-2] = x[-1] = -1
  if matrix[n-2, -1] == 0 : x[-2] = 0
  elif matrix[n-2, -2] == 0 : x[-1] = 0
  for r in range(n-3, -1, -1):
    if matrix[:, r].sum() == 0:
      x[r] = 1
    value = 0
    for c in range(r, n):
      if matrix[r, c] == 1 :
        if x[c] < 0 : break
    unknown = 0
    for j in range(c+1, n):
      if matrix[r, j] == 1:
        if x[j] == -2: x[j] = -1
        if x[j] == -1: unknown = 1 - unknown
        else : value ^= x[j]
    if unknown == 1: x[c] = -1
    else :
      if x[c] == -1:
        for j in range(r+1, n):
          if x[j] == -1 : x[j] = value
      x[c] = value
  x1 = x.copy()
  for i in range(n):
    if x[i] == -1 : x1[i] = 1
  for r in range(n-1):
    v = 0
    for c in range(n) :
       v ^= matrix[r, c] & x1[c]
    if v == 1 : 
       for i in range(n):
          if x[i] == -1 : x[i] = 0
       return x
  return x1

def solve_simon(measured):
  sys_eq = []
  for z in measured.keys():
    n = len(z)
    if int(z) == 0 : continue
    eq = [int(zi) for zi in z]
    if len(sys_eq) == 0:
      sys_eq.append(eq)
      continue
    if(indep(sys_eq, eq)):
      if(len(sys_eq) == (n-1)):
        break
  print("The following z's are measuered : ")
  print(np.array(sys_eq))
  matrix = ge_mod2(sys_eq)
  print("REF matrix: ")
  print(matrix)
  b = back_substitution_mod2(matrix)
  return b

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


print("measured output : ", count)
b_simon = solve_simon(count)
print(f"The period of a function f(x)) with Simon Property is {b_simon}")

"""
Response Example
{'010': 1, '101': 1}
measured output :  {'010': 1, '101': 1}
The following z's are measuered : 
[[0 1 0]
 [1 0 1]]
REF matrix: 
[[1 1 1]
 [0 0 0]]
The period of a function f(x)) with Simon Property is [1 0 1]

{'101': 1, '010': 1}
measured output :  {'101': 1, '010': 1}
The following z's are measuered : 
[[1 0 1]
 [0 1 0]]
REF matrix: 
[[1 1 1]
 [1 1 1]]
The period of a function f(x)) with Simon Property is [0 1 1]
"""