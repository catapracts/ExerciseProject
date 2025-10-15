from qiskit.visualization import array_to_latex
import numpy as np

U = [[np.exp(2j*np.pi/8), 0, 0, 0],
     [0, np.exp(2j*np.pi*2/8), 0, 0],
     [0, 0, np.exp(2j*np.pi*3/8), 0],
     [0, 0, 0, np.exp(2j*np.pi*4/8)]]

array_to_latex(U, prefix="U = ", max_size=16)
