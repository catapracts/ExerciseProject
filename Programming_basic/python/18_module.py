"""
module = 어떤 기능이 담긴 파이썬 파일
library = module의 집합체
python standard library

"""

import time
print(1)
time.sleep(2) #초 단위 딜레이 넣기
print(2)

for i in range(1,20):
    print(f"{i} : Hi!")
    time.sleep(1)


import random
x = random.random() # 0 이상 1 미만 난수
print(x)

x1=random.randint(1, 100) # 기본 : 1 이상 10 미만 난수
print(x1)

x2 = [1,2,3,4,5,6,7,8,9]
random.shuffle(x2)
print(x2)

x3 = random.choice(x2) #무작위로 1개 선택
print(x3)

x4 = random.sample(x2) #무작위로 여러 개 선택
print(x4)

import datetime

today = datetime.date.today()
print(today) #YYYY-MM-DD
print(today.month) #MM
print(today.day) #DD


import os
print(os.getcwd()) #현재 위치한 디렉토리
print(os.listdir()) #현재 위치한 디렉토리에 존재하는 파일과 폴더들

