numbers = [ 5, 1, 3, 9, 7 ]
squared_numbers = list(map(lambda x : x**2, numbers))
squared_numbers.sort(reverse=True)
print(squared_numbers[:3])
squared_numbers.sort()
print(squared_numbers)
