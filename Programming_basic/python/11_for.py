"""
while -> use with ambiguous scope of condition
for -> use with certain range of condition
"""

fighters = ["F-14", "F-18", "F-15", "F-16", "F-22", "F-35"]
#fighters = "F-14 F-18 F-15 F-16 F-22 F-35"

for fighter in fighters:
    print(f"{fighter} take off.")


print("All planes are taked off.")


count = 1

for i in range(1, 11):
    print(f"{i}th track")

print("all track is completed")


num = 0

for j in range(1, 101):
    print(j)
    # num += j
    num -= j

print(num)