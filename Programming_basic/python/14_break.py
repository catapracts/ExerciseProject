
count = 1

while count < 11:
    print(f"{count}바퀴째")
    count += 1
    if count == 11:
        break

print("달리기 완료")


count1 = 0

while True:
    count1 += 1
    if count1 == 18:
        print("take a rest")
        continue    # 해당 조건에서만 작동 안 시키게 방지
    print(f"{count1}바퀴째")
    if count == 20:
        break       # 코드 종료

print("달리기 완료")


for i in range(20):
    if i == 5:
        #break
        continue
    print(i)


