from math import gcd, lcm
from numpy.random import randint
import numpy as np

N = 21
n = 5
t = 2*n + 1
a = randint(2, N)
g = gcd(a, N)
print(f"a={a}, gcd({a}, {N}) = {g}")
