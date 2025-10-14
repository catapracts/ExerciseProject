from qiskit import QuantumCircuit
from qiskit.transpiler.preset_passmanagers import generate_preset_pass_manager
from qiskit_ibm_runtime import SamplerV2 as Sampler
from qiskit_aer import AerSimulator
from qiskit.circuit.library import QFT
import numpy as np

qc = QuantumCircuit(3)
qc.x([1,2])
qc.compose(QFT(3), range(3), inplace=True)
qc.compose(QFT(3, inverse=True), range(3), inplace=True)

qc_measured = qc.measure_all(inplace=False)
aer_sim = AerSimulator()
pm = generate_preset_pass_manager(backend=aer_sim, optimization_level=1)
isa_circuit = pm.run(qc_measured)
sampler = Sampler(mode=aer_sim)
job = sampler.run([isa_circuit], shots = 1000)
result = job.result()
count = result[0].data.meas.get_counts()
print(count)

