from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit_aer import AerSimulator
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager

adj_rooms = [[1, 3], [0, 2, 4], [1, 5], [0, 4, 6], [1, 3, 5, 7], [2, 4, 8], [3, 7], [4, 6, 8], [5, 7]]

def show_lights(rooms, str=''):
  print(str)
  for i in range(3):
    for j in range(3):
      print(rooms[i*3+j], end = ' ')
    print()
  print()
  return

def switch_lights(switch, rooms):
  show_lights(rooms, 'initial status :')
  for i in range(9):
    if switch[i] == 1:
      rooms[i] = 1 - rooms[i]
      for c in adj_rooms[i]:
        rooms[c] = 1-rooms[c]
      show_lights(rooms, f'after switch {i} is on :')
  return

def switch_func(switch, rooms) :
  circuit = QuantumCircuit(switch, rooms)
  for i in range(9):
    circuit.cx(switch[i], rooms[i])
    for c in adj_rooms[i]:
      circuit.cx(switch[i], rooms[c])
    circuit.barrier()
  return circuit

def lights_oracle(qy, qr, qx):
  circuit = QuantumCircuit(qy, qr, qx)
  circuit.compose(switch_func(qx, qr), qx[:9]+qr[:9], inplace=True)
  circuit.mcx(qr, qy)
  circuit.compose(switch_func(qx, qr), qx[:9]+qr[:9], inplace=True)
  circuit.name = 'Oracle'
  return circuit

def diffuser_circuit(n) :
  x = QuantumRegister(n, 'x')
  qc = QuantumCircuit(x)
  qc.h(x)
  qc.x(x)

  qc.barrier()
  qc.h(x[0])
  qc.mcx(x[1:n], x[0])
  qc.h(x[0])
  qc.barrier()

  qc.x(x)
  qc.h(x)

  qc.name = 'Diffuser'
  return qc

def count(n, q_str, q_cnt):
  circuit = QuantumCircuit(q_str, q_cnt)
  for i in range(n):
    circuit.mcx([q_str[i], q_cnt[0], q_cnt[1], q_cnt[2], q_cnt[3]])
    circuit.mcx([q_str[i], q_cnt[0], q_cnt[1], q_cnt[2]])
    circuit.ccx(q_str[i], q_cnt[0], q_cnt[1])
    circuit.cx(q_str[i], q_cnt[0])
  circuit.name = 'Count'
  return circuit

qr = QuantumRegister(9, name='r')
qx = QuantumRegister(9, name='x')
qy = QuantumRegister(1, name='y')
c = ClassicalRegister(9, 'c')

circuit = QuantumCircuit(qy, qr, qx, c)
circuit.x(qy)
circuit.h(qy)

rooms = [0,0,0, 1,0,1, 1,1,0]
for i in range(9):
  if rooms[i] == 1:
    circuit.x(qr[i])

circuit.h(qx)

for _ in range(17):
  circuit.append(lights_oracle(qy,qr,qx), range(19))
  circuit.append(diffuser_circuit(9), qx)

circuit.measure(qx, reversed(c))


aer_sim = AerSimulator()
pm = generate_preset_pass_manager(backend=aer_sim, optimization_level=1)
isa_circuit = pm.run(circuit)
sampler = Sampler(mode=aer_sim)
job = sampler.run([isa_circuit], shots=1)
result = job.result()
count = result[0].data.c.get_counts()

answer = list(count.keys())[0]
print(answer)
switch_answer = [int(answer[i]) for i in range(9)]
problem = rooms.copy()
print('switches = ', switch_answer)
print('problem = ', problem)

switch_lights(switch_answer, problem)
solved = True
circuit.measure(qx, reversed(c))
circuit.draw(output='mpl', fold=-1)

for r in problem:
  if r != 1:
    solved = False
    break
if solved:
  print('lights are all turned on.')
  print(' press the switches ', end='')
  for i in range(len(switch_answer)):
    if switch_answer[i] == 1:
      print(i, end=',')
  print(' to turn all the lights')
else :
  print('Some lights are turned off. Try again,')