"""
23.05
asia라는 set 생성 후 '한국', '중국', '일본'이라는 element로 초기화
asia set에 '베트남' element 추가
asia set에 '일본' element 삭제
asia set에 '한국', '홍콩', '태국'이라는 element 갱신(없는 element는 추가하고, 있는 element는 추가 X)
결과 : {'한국', '중국', '베트남', '홍콩', '태국'}
"""
asia = {'한국', '중국', '일본'}
asia.add('베트남')
asia.remove('일본')
asia.update({'한국', '홍콩', '태국'})
print(asia)

"""
23.07
a = "engineer information programming"라는 문자열 생성
0                               31
engineer information programming
b에 a의 0번째부터 2번째까지의 글자 저장 -> eng
C에 a의 4번째부터 5번째까지의 글자 저장 -> ne
d에 a의 29번째부터 끝까지의 글자 저장 -> ing
e에 b, c, d를 한꺼번에 이어서 저장 -> eng + ne + ing
e 출력 -> 결과 : engneing -> engneing
"""
a = "engineer information programming"
b = a[:3]
c = a[4:6]
d = a[29:]
e = b + c + d
print(e)

"""
23.10
2개 변수에 대한 입력 받기 -> split함수를 이용해서 2개 변수의 입력을 어떤 걸로 구분할 것인지 설정 가능 -> 여기서는 공백(' ')으로 구분함 -> 입력할 때도 1칸 띄고 입력
첫 번째 입력에 대한 결과 
두 번째 입력에 대한 결과
"""
x, y = input("x, y의 값을 공백으로 구분하여 입력 : ").split(' ')
print("x의 값 :", x)
print("y의 값 :", y)