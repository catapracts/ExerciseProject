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

problem = [0, 0, 0, 1, 0, 1, 1, 1, 0]
switch_answer = [0, 0, 1, 1, 0, 0, 1, 0, 1]

print('switches = ', switch_answer)
print('problem = ', problem)

switch_lights(switch_answer, problem)

solved = True
for r in problem:
  if r != 1:
    solved = False
    print('The problem is not solved')
    break
  if solved:
    print('lights are all turned on.')
    print(' press the switches ', end = '')
    for i in range(len(switch_answer)):
      if switch_answer[i] == 1:
        print(i, end = ',')
    print(' to turn all the lights.')

