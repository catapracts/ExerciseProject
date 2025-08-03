"""
9x9
"""

for i in range(2,10):
    print(f"<< {i}단 >>")
    for j in range(1,10):
        print(f"{i} * {j} = {i*j}")


메뉴판 = ["어묵", "디저트", "사시미", "초밥", "피자", "짬뽕", "삼겹살"]

for i in 메뉴판:
    print(i, "delicious!")