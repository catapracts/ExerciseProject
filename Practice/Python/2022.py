"""
22.05
매개변수 2개를 사용하는 함수 생성(num1, num2), num2변수는 값이 고정
num1과 num2 값 출력
func(20) -> num1 = 20, num2 = 2
"""
def func(num1, num2 = 2):
    print('a =', num1, 'b =', num2)
func(20)

"""
22.07
a 변수에 문자열 "REMEMBER NOVEMBER" 저장
b 변수에 a의 0~2번째와 12~15번째 문자열을 출력 = REM + EMBE = REMEMBE
c 변수에 "R AND %s"를 저장한다 / %s = 서식 문자열, % 뒤의 문자열(STR)을 출력하면 된다. = "R AND STR"
b와 c를 이어서 출력한다. = REMEMBER AND STR 
"""
a = "REMEMBER NOVEMBER"
b = a[0:3] + a[12:16]
c = "R AND %s" % "STR"
print(b+c)


"""
22.10
a라는 배열을 선언하고 [1, 2, 3, 4, 5]로 초기화
list안에 element들을 차례대로 확인하는데, 각 요소에 +100씩 한 후 저장한다.
그 결과를 출력한다.
"""
a = [1, 2, 3, 4, 5]
a = list(map(lambda num : num + 100, a))
print(a)