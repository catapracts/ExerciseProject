def default_behavior(x, y=[]):
    y.append(x)
    return len(y)

print(default_behavior(1))
print(default_behavior(2))
print(default_behavior(3, [10, 20]))
print(default_behavior(4))