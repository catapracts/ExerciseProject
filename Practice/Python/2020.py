#2020정보처리기사 실기

"""
2020.11 문제

lol = [[1,2,3], [4,5], [6,7,8,9]]
=구성 : [0][0],[0][1],[0][2] / [1][0], [1][1] / [2][0], [2][1], [2][2], [2][3]
=초기화 :  1, 2, 3 / 4, 5 / 6, 7, 8, 9

print(lol[0]) = lol list의 0th row 출력 = [1,2,3]
print(lol[2][1]) = lol[2][1] 값 출력 = 7
for sub in lol: = lol의 row수만큼 반복 수행 + lol의 각 row가 저장될 변수 sub 선언
for item in sub: = sub의 element수 만큼 반복 수행 + sub의 element를 저장할 변수 item 선언
print(item, end='') = item에 저장된 값 출력 후 1칸 띄우기(' ')
print() = cursor를 다음 row로 이동
=> sub = [1, 2, 3] / [4, 5] / [6, 7, 8, 9]
=> item = 123 / 45 / 6789
"""

lol = [[1,2,3], [4,5], [6,7,8,9]]
print(lol[0])
print(lol[2][1])
for sub in lol:
    for item in sub:
        print(item, end='')
    print()
    print(sub)
    print()