import numpy as np

def x_operator(n,k,r,checkZ):
  x_ops = np.zeros(shape=[k, 2*n], dtype=int)
  for row in range(k):
    for col in range(n-k-r):
      if checkZ[r+col][n-k+row] == '1':
        x_ops[row][r+col] = 1
  for row in range(k):
    x_ops[row][n-k+row] = 1
  for row in range(k):
    for col in range(r):
      if checkZ[col][n-k+row] == '1':
        x_ops[row][n+col] = 1
  return x_ops

checkX = ['1001011', '0101101', '0011110', '0000000', '0000000', '0000000']
checkZ = ['0000000', '0000000', '0000000', '1111000', '1010101', '0110011']
x_ops = x_operator(7, 1, 3, checkZ)
print(x_ops)
