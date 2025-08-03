"""
만약 오늘 == 월요일:
    출근한다.
만약 오늘 == 일요일:
    더 잔다.

밑에 spaces:4 -> 들여쓰기 1번에 space 4번친 것과 동일 = 권장

비교연산자 : <, >, <=, >=, ==, !=
and, or, not

"""

today = "일요일"

if today == "월요일":
    print("출근")
elif today == "일요일":
    print("잘자")
else:
    print("오늘 무슨 요일이지?")


day = 30
if day < 30:
    print("아직 돈 안 들어왔다...ㅠㅠ")
elif day == 30:
    print("월급날이다!!!")
else:
    print("WTF?")

pizza = True # ""/0 = False, " "/숫자 = True
Hamburger = False

if pizza:
    print("피자 하나 가지고 올 수 있도록 해")
elif Hamburger:
    print("햄버거 하나 가지고 올 수 있도록 해")
else:
    print("함포로 거리를 다 날려버릴까")

if pizza and Hamburger:
    print("음...좋아...아주 좋아...!")
elif Hamburger:
    print("음...햄버거로구만")
else:
    print("음...엎드릴 수 있도록 해")

if pizza or Hamburger:
    print("음...좋아...아주 좋아...!")
elif Hamburger:
    print("음...햄버거로구만")
else:
    print("음...엎드릴 수 있도록 해")

if not pizza:
    print("음...피자가 아니로구만")
elif Hamburger:
    print("음...햄버거로구만")
else:
    print("음...엎드릴 수 있도록 해")





age = 28
confirm_adult = age > 19
print(confirm_adult)
if confirm_adult:
    print("성인인증완료")

height = 180
play_confirm = height <= 220 and height >= 100
print(play_confirm)
if play_confirm:
    print("놀이기구 탑승 가능")

current_time = 12
start_time = 17
end_time = 23
operate = current_time >= start_time and current_time <= end_time
print(operate)
if operate:
    print("현재 운영중")
else:
    print("현재 운영중X")


