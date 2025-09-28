def cals(num):
    if num == 1:
        return 1
    else:
        return num * cals(num-1)

in_val = 4
result = cals(in_val)
print(result)
