"""
9/2 -> 4.5
9//2 -> 4
9%2 -> 1
"""

for i in range(1, 21):
    if i % 2 == 0:
        print(f"{i} is even")
    else:
        print(f"{i} is odd")


for i in range(1, 31):
    if i % 3 == 0:
        print(f"{i} is 3의 배수")
    else:
        print(f"{i} is 3의 배수 아님")


for i in range(1, 21):
    if i % 3 == 0 and i % 5 == 0:
        print(f"{i} is 3과 5의 배수")
    elif i % 3 == 0:
        print(f"{i} is 3의 배수")
    elif i % 5 == 0:
        print(f"{i} is 5의 배수")
    else:
        print(f"{i} is what?")



