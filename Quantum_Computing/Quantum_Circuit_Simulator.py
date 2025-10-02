from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit_aer import AerSimulator
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.visualization import plot_distribution

qt = QuantumRegister(1, 'target')
qc = QuantumRegister(2, 'control')
cr = ClassicalRegister(3, 'm')
circuit = QuantumCircuit(qt, qc, cr)

circuit.x(qt)
circuit.x(qc)

circuit.barrier()

circuit.ccx(qc[1], qc[0], qt)

circuit.measure([0, 1, 2], cr)

aer_sim = AerSimulator()
pm = generate_preset_pass_manager(backend=aer_sim, optimization_level=1)
isa_circuit = pm.run(circuit)
sampler = Sampler(mode=aer_sim)
job = sampler.run([isa_circuit], shots=1000)

result = job.result()
count = result[0].data.m.get_counts()
print (count)

#plot_distribution(count)
