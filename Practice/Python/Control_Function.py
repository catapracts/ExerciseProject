"""
제어문 - if/else/elif while
- 들여쓰기(indentation) 잘못하면 error발생한다. -> tab or space bar로 통일시키기
- :붙여서 구분
- 참.거짓 판단 - 안에 값이 있는가 없는가
참 ex : 0이 아닌 모든 수, "문자열", [List], (Tuple), {Dictionary}
거짓 ex : 0, "", [], (), {}
- 사용 가능한 비교 연산자들 : <, <=, >, >=, ==, != / and, or not
- 값 in 변수, 값 not in 변수 : 변수에 값이 있는가?/없는가? 확인 -> True or False반환
- if/elif,else
- while, for
"""
a="aaaa"

if a=="aaaa":
    print("aaaa")
else:
    print("??????")

b=1
c=2
print(b<c) #True
print(b>c) #False
print(b!=c) #True
print(b==c) #False

print('d' in ['d','e,'f'']) #True
print('a' in ['d','e,'f'']) #False

d = ['aaaa', 'bbbb', 'cccc']
if 'aaaa' in d:
    print("Exist")
else:
    print("Empty")

e = 100
f = 0
if e and f:
    print("&") #e랑 f를 AND연산해서 참인 경우 출력
elif e==0:
    print("e=0") #e=0인 경우 출력
elif f==100:
    print("f=100") #f=100인 경우 출력
elif not e:
    print("NOT") #e를 NOT연산한 것이 True인 경우 출력
else:
    print("OR") #나머지 경우 OR연산


"""
-while : 조건의 결과값이 false가 되면 반복 종료
while 조건:
    내용
    break

break안 걸면 무한loop진행되고, ctrl+C 함께 눌러서 빠져나오기
무한loop예시
while True:
    print("1")
"""
#단순 반복문
a1 = 0
while a1<4:
    a1 = a1+1
    print("%d번째 loop" %a1)
    if a1==3:
        print("loop 종료")
        break

#입력한 값 나오기 전까지 반복하는 while문 - 숫자 4입력하면 종료
select = """
1.s1
2.s2
3.s3
4.s4
숫자입력 : """

s_num=0
while s_num != 4:
    print(select)
    s_num = int(input())


"""
for : 반복문 / tuple이나 list사용시 while문보다 간결하게 code작성 가능

"""

#List 이용한 예제
List = ['a', 'b', 'c', 'd']
for i in List:
    print(i)

#Tuple이용한 예제
Tuple = [(1,2), (3,4), (5,6)]
for (f,l) in Tuple:
    print(f+l)

#range함수
b1 = 0
for a in range(1,5):
    b1 = b1+a
    print(b1)

#구구단
for a in range(2,10):
    for b in range(1,10):
        print(a,"X",b,"=",a*b)
        if(b==9):
            print("\n")




"""
함수 
- 하나의 특정한 목적의 작업을 수행하기 위해 독립적으로 구성된 프로그램 코드의 집합
- 함수 구조(in python) - 매개변수 없어도 정의 가능
def 함수이름(매개변수):
    실행문들
- I/O함수, 파일관련 I/O함수
"""

#더하기 함수
def sum(a, b):
    return a+b
a=1
b=2
c=sum(a,b)
print(c) # 결과 : 3

#매개변수 없는 함수
def a():
    return "a"
x=a()
print(x) # 결과 : a

#곱하기 예제
def multi(a,b):
    print("%d X %d = %d" % (a,b,a*b))

multi(2,4) # 결과 : 2 X 4 = 8

#총합 예제
def sumMany(*args): #*args = 어떤 매개변수든 다 받는다
    sum=0
    for i in args:
        sum=sum+i
    return sum

a = sumMany(1,2,3,4,5,6,7,8,9,10)
print(a) # 결과 : 55

#I/O함수
tmp = input("문자열 입력 : ")
print(tmp) # 결과 : 입력한 문자 출력됨

#print() 특성
print("가""나""다""라") # 결과 : 가나다라
print("가"+"나"+"다"+"라") # 결과 : 가나다라
print("가","나","다","라") # 결과 : 가 나 다 라
print("가 나 다 라") # 결과 : 가 나 다 라

#파일 만들고 수정
PATH = "C:/Users/hi/Desktop/a.txt"
file = open(PATH, 'w')
for i in range(1,6):
    line = "%d번째 줄\n" %i
    file.write(line) #결과 : a.txt파일에 1,2,3,4,5번째 줄이 생긴다.
file.close() #사용한 객체 닫아주는 역할

file = open(PATH, 'r')
line=file.readlines()
for i in line:
    print(i)
file.close()
"""
파일 읽을 때 사용하는 함수
1. readline() : 파일의 모든 line을 읽고 각각의 line을 list로 반환
2. readlines()
3. read()
"""

#파일에 새로운 내용 추가
file = open(PATH, 'a')
for i in range(6,11):
    line = "%d번째 줄\n" %i
    file.write(line) #결과 : 아까 a.txt파일에 1,2,3,4,5번째 줄이 생긴곳에 이어서 6,7,8,9,10번째 줄이 추가된다.
file.close()

