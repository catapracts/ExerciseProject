"""
Function : 특정 작업 수행 / 전자레인지
input : 입력 데이터 / 전자레인지에 음식 넣기
process : 데이터 처리 / 전자레인지 동작
output : 처리 결과 / 전자레인지에서 꺼내기

Function type
1. only process : 정해진 일만 수행 / 입력 없어도 수행 / 매일 반복되는 루틴 처리에 적합 / 이자카야 오픈 준비
2. input & process : input을 받고 process but return이 없음 / 시스템 상태 변경 or 외부와 상호작용 시 사용 / 이자카야 주문 접수
3. input & process & return : input을 받고 process 후 return / 데이터 분석, 수학적 계산, 문자열 처리 등 다양한 상황에서 사용 가능 / 이자카야 계산대

1번 만들면 계속 사용가능

"""
def add(a, b):
    # return이 이 위치에 있을 경우 이후 코드는 전부 실행 안 됨 = 코드 종료
    print(f"{a}와 {b}를 입력받았습니다.")
    print(f"{a} + {b} = {a+b} 입니다.")
    return a+b

#add(5,6)
a = print("Hi")         # 행동만 하는 함수
b = input("input : ") # 만들어내는 함수
print(a)
print(b)

temp = add(5,10)
print(temp) # none이 return 됨 / def 안에 return이 들어가 있으면 그 값 출력


def adult_confirm(age):
    if age >= 20:
        print("성인인증 완료")
    else:
        print("미성년자")

age1 = 25
adult_confirm(age1)
age2 = 18
adult_confirm(age2)
age3 = 20
adult_confirm(age3)


def adult_confirm(age):
    if age >= 20:
        print("성인인증 완료")
    else:
        print("미성년자")
