# alt+z 줄 정렬
name = "F-22A"
type = "Fighter"
age = 1992

print("이 기체는 "+ name + "이다." + "종류는 "+type+"이다."+"첫 배치년도는 "+age+"이다.")  #Err - 숫자는 문자처리 안 됨 
print("이 기체는 "+ name + "이다." + "종류는 "+type+"이다."+"첫 배치년도는 "+str(age)+"이다.")

print(type("100"))
print(type(int("100")))

# 이 3가지 형태 다 알아두는게 좋다.
print("이 기체는 %s이다. 종류는 %s이다. 첫 배치년도는 %s이다." %(name, type, age))
print("이 기체는 {0}이다. 종류는 {1}}이다. 첫 배치년도는 {2}}이다." .format(name, type, age))
print(f"이 기체는 {name}이다. 종류는 {type}이다. 첫 배치년도는 {age}이다.") # 이거 많이 사용할 예정
