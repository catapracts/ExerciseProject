#2021 정보처리기사 실기

"""
21.04
CharClass라는 이름으로 class를 생성하고 class내용으로 a라는 배열을 선언해서 초기화하고 사용
myVar라는 변수를 charClass타입으로 생성
str01이라는 공백 1개 있는 문자 생성
i라는 변수로 반복문을 돌릴건데 그 대상은 myVar라는 클래스에 있는 a배열이다.
str01에 str01값과 a배열의 각 element의 첫 번째 요소를 +한다.(이어붙인다.) - Seoul의 S, Kyeongi의 K, Incheon의 I ... 가 각 element의 1st값
str01출력 - SKIDDP
"""
class CharClass:
    a = ['Seoul', 'Kyeongi', 'Incheon', 'Daejeon', 'Daegu', 'Pusan'];
myVar = CharClass()
str01 = ' '
for i in myVar.a:
    str01 = str01 + i[0]
print(str01)


"""
21.07
a=100, result = 0이라는 변수 선언 및 초기화
for i in range(1,3): -> 1이상부터 3미만까지 반복(총 2번 반복)
result = a >> i -> result의 값 = a를 i만큼 왼쪽으로 이동한 것(bit가 i칸씩 왼쪽으로 이동한 것 = 2진수)
result = result + 1 -> 그렇게 옮기고 난 뒤 + 1하기

a = 100 = 1100100
-> 1칸 이동(i = 1) : 0110010(32+16+2 = 50) -> + 1 = 51
-> 2칸 이동(i = 2) : 0011001(16+8+1 = 25) -> + 1 = 26

result 출력 : 26
"""
a = 100
result = 0
for i in range(1,3):
    result = a >> i
    result = result + 1
print(result)

"""
21.10
x = 100, y = 200이라는 변수 선언 및 초기화
print(x==y) : x와 y가 같은지 비교 후 결과를 출력
-> 100이랑 200은 다른 값이므로 false출력
"""
x, y = 100, 200
print(x==y)

