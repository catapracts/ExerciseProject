"""
Python
- 1989년 귀도 반 로썸(Guido van Rossum)에 의해 개발된 고급 프로그래밍 언어
- 다양한 플랫폼에서 사용
- 라이브러리(모듈)가 풍부 = 손쉬운 사용과 빠른 개발속도가 큰 장점
- 인터프리터(Interpreter) 언어 : 인터프리터(해석기) 위에서 실행되는 언어 = 프로그램의 코드가 한 라인씩 순서대로 해석되고 실행되기를 반복
- 들여쓰기(Indentation) : 들여쓰기가 달라지면 다른 블록으로 인식
- 멀티 패러다임 :  절차지향(ex - C), 객체지향(ex - JAVA), 함수형(ex - LISP) 패러다임 모두 구현
"""
print("Hello World")
"""
주석 - #, """""", ''''''
변수 
- 자료형 존재 but 문법으로 정해서 사용하도록 하지는 않음
- 변수 이름만 선언해서 사용
- = : 값 저장, == : 같은지 다른지 확인
- 정수, 실수, 16진법 / 산술연산자(+, -, *, /, %, //, **)
*정수 실수 연산시 항상 실수형으로 결과 반환
** / : python - 항상 값 반환, 다른 언어 - 자료형에 따라 몫 or 값 반환
- 문자열 - 연산(+(이어 붙이기),*(반복)) / "''"(O), '""'(X), "'"'(X)
- 1변수 : 1값
"""
print(3+7) #10
a=1+2
print(a) #3
b=1.1+2.2
print(b) #3.3000000000000003
c=0x16+0x15
print(c) #43
print("I am a Programmer")
d = "dddd"
e = "eeee"
f = "ffff"
print(d) #dddd
print(e+"dddd") #eeeedddd
print(f*3) #ffffffffffff
print("===========================================")
"""
tuple, Dictionary, List, 집합 = 1 : N값

tuple
- 제일 단순한 자료형
- (,)
- 0개 이상의 원소 저장 / 자료형 달라도 되고, 다른 tuple들도 가능
- 한 번 생성하면 내부 원소 삭제/수정 불가능 = 상수값들 넣어서 사용하는 게 좋다.
- index로 구분 = 실제 데이터에 접근할 때 [,]사용하는데 [,]에서 사용하는 숫자, 0부터 시작
"""
tup1 = (1,"aaaaa")
tup2 = (2,3.33)
tup3 = tup1 + tup2
tup4 = tup1*3
tup5 = tup3[1]
print(tup1) #(1, 'aaaaa')
print(tup2) #(2, 3.33)
print(tup3) #(1, 'aaaaa', 2, 3.33)
print(tup4) #(1, 'aaaaa', 1, 'aaaaa', 1, 'aaaaa')
print(tup5) #aaaaa
print("===========================================")
"""
Dictionary
- key : value(1:1)
- key = 변화X, value = 변화O / key-value쌍 자체 수정or삭제 가능
- 내부함수 존재 
 - dic.keys() :  해당 사전형 데이터에 저장된 key값들을 list의 형태로 반환 / 해당 사전형에 무슨 key값들 포함되어 있는지 모를 때 사용 / in keyword 사용시 해당 list에 특정 값이 포함되어 있는지 여부를 알 수 있다. - true(존재O), false(존재X)반환
 - dic.values() :  해당 사전형 데이터에 저장된 모든 value 값들을 리스트의 형태로 반환
 - dic.items() : 해당 사전형 데이터에 저장된 모든 key-value 쌍을 리스트의 형태로 반환
"""
dic = {1:"aa", 2:"bb", 3:"cc", 4:"dd"}
print(dic[1]) #aa
print(dic[2]) #bb
print(dic[3]) #cc
print(dic[4]) #dd
print(dic.keys()) #dict_keys([1, 2, 3, 4])
print(0 in dic.keys()) #False
print(dic.values()) #dict_values(['aa', 'bb', 'cc', 'dd'])
print(dic.items()) #dict_items([(1, 'aa'), (2, 'bb'), (3, 'cc'), (4, 'dd')])
print("====================================================================")
"""
List
- 원소들이 연속적으로 저장되는 형태의 자료형 / 자료형 다 달라도 된다.
- [,] / 0개 이상의 원소 저장 / 원소로 또 다른 리스트 저장 가능(n차원 list라고 부른다)
- 내부함수 존재
 - sort : 해당 list에 저장된 원소들을 오름차순으로 정렬 / 같은 타입끼리 있는 경우는 정렬에 문제 없지만, 다른 타입들 있을 경우 잘 안 될 수 있다.
 - reverse : 해당 리스트에 저장된 원소들의 순서를 정반대로 정렬
 - append : 해당 리스트의 맨 뒤에 데이터를 추가
 - del : Python 내부함수, 변수 삭제
"""
list1 = [1,2,3,4]
list2 = [5,6,7,8]
print(list1) #[1, 2, 3, 4]
print(list2) #[5, 6, 7, 8]
list3 = [22,11,44,33]
list4 = [55,66,77,88]
list3.sort()
list4.reverse()
del list3[0]
list3.append(99)
print(list3) #[22, 33, 44, 99]
print(list4) #[88, 77, 66, 55]
list5 = [111,222,333,444]
list6 = ["aaa","bbb","ccc","ddd"]
list7 =[list5, list6]
print(list7) #[[111, 222, 333, 444], ['aaa', 'bbb', 'ccc', 'ddd']]
print("===========================================================")
"""
집합(set)
- 중복되는 원소 없이 순서에 상관없는 데이터들의 묶음 = 데이터 중복 허용X + 순서 존재 X(index이용 불가능)
- {, } / list or 문자열 사용해서 생성 / 중복값 들어가면 나중에 출력할 때, 1개만 출력한다.
*교집합 : &, 합집합 : |, 차집합 : - 으로 표현, 여집합 존재X
"""
list8 = [100,200,300,400]
set1 = set(list8)
print(set1) #{200, 100, 400, 300}
set2 = {"a","b","c"}
set3 = {'a','b','b'}
print(set2, set3, set2-set3) #{'b', 'c', 'a'} {'b', 'a'} {'c'}
