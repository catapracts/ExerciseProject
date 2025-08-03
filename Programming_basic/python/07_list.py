"""
list = 여러 개의 값을 순서대로 저장하는 자료구조 / 서랍
index = 순서 / n번째 서랍
element = 배열의 값 / 서랍 안에 있는 내용물

["~","~","~"]
[1,2,3,4]
["~",1,1.1]

"""


fighter = ["F-22", "F-35", "F-16", "F-15", "F-14", "F-18", 100, ["su-57", "su-47"]]  #list
print(type(fighter))
print(type(fighter[0]))
print(len(fighter))
print(fighter[0])
print(fighter[-1])
print(fighter[0:2])
print(fighter[5])
print(fighter[6])
print(fighter[6][0])

fighter1 = ["Mig-29", "Mig-31"]

print(fighter+fighter1)

fighter2 = fighter + fighter1

print(fighter2)

fighter3 = fighter * 3

print(fighter3)

fighter4 = ["Rafale", "EuroFighterTyphoon"]
fighter4.append("J35J") #~.append = method / 값 추가
print(fighter4)
fighter4.insert(1, "MIR-2000") #특정 위치에 값 추가
print(fighter4)
fighter4.remove("MIR-2000") # 같은 값이 여러개 있으면, 맨 처음 나오는 하나만 지움
print(fighter4)
fighter4.count("MIR-2000") # 해당하는 값이 몇개나 있는가?
print(fighter4)
fighter4.index("J35J") # 해당 값이 몇 번째 index에 있는가? 같은 값이 여러개 있으면, 맨 처음 나오는 하나의 index 반환
print(fighter4)
fighter4.sort() # 순서대로 정렬 - 알파벳, 숫자 등 맨 처음부터
print(fighter4)
fighter4.sort(reverse=True) # 역순서대로 정렬 - 알파벳, 숫자 등 맨 마지막부터
print(fighter4)
print(fighter4[0])
fighter4[0] = "JAS39"
print(fighter4[0])



메뉴판 = ["어묵", "디저트", "사시미", "초밥", "피자", "짬뽕", "삼겹살"]
