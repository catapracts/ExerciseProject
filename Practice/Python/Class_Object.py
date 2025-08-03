"""
Class ≒ 설계도
- class = 속성(Attribute) + 동작(Operation)
- 속성(Attribute) = class가 가지는 variable들
- 동작(Operation) = class가 할 수 있는 동작들

* 객체 지향 프로그래밍(Object Oriented Programming)세상에 이미 존재하거나 우리가 만들 무언가에 대해 속성과 동작을 분리해서 분석하는 사고방식으로 프로그래밍을 설계

*객체지향의 개념
1. Abstraction(추상화) - 만들고자 하는 것들의 공통적인 것을 바탕으로 하나로 묶는 것
2. Encapsulation(캡슐화) - 맡은 역할의 수행을 위해 최소한의 외부 접근만을 허용하는 것
3. Polymorphism(다형성) - 자료형에 구애 받지 않고 프로그래밍 하는 것
4. Inheritance(상속) - 하위 개념이 상위 개념의 속성 및 동작 등을 물려받는 것

Object ≒ 설계도로 만든 제품
- 완전 독립적(유일)
"""

"""
Class선언 형태 : class 이름(대문자로 시작):

Constructor
- class를 기반으로 object를 만들어주는 역할
- 항상 이름은 고정(변경 불가능) : __init__
- 첫 번째 매개변수는 항상 self로 선언
- self = 함수를 호출한 객체를 가리키는 변수

private
- keyword
- python : __변수이름
- 외부에서 접근 불가능, 객체 안에서만 사용가능

public
- keyword
- python : __변수이름__
- 어디에서든 접근 가능

instance화
- 생성자를 호출하여 object를 만드는 과정
- class 이름을 호출해서 객체  생성

class변수
- 독립적인 객체들끼리 서로 정보 공유 가능
 
"""
class Horse:
    def __init__(self, age, height, color, xpos, ypos):
        self.age = age
        self.height = height
        self.color = color
        self.xposition = xpos
        self.yposition = ypos
        self.velocity = 0

if __name__ == '__main__':
    danbi = Horse(3, 180, 'Black', 0, 0)


class Alphabets:
    __str = ""

    def __init__(self, text):
        self.text = text
        Alphabets.__str += text #결과 : python

    def print_class_variable(self):
        print(Alphabets.__str) #결과 : python


if __name__ == '__main__':
    o1 = Alphabets('p')
    o2 = Alphabets('y')
    o3 = Alphabets('t')
    o4 = Alphabets('h')
    o5 = Alphabets('o')
    o6 = Alphabets('n')
    o1.print_class_variable()
    o5.print_class_variable()

"""
부모(parent, super) class - 자식(child, sub) class
Inheritance(상속) : 물려받는 것
Overriding : 부모 클래스로부터 상속받은 특성을 자식 클래스에서 재정의하는 것
Dynamic Binding : 프로그램의 실행 시간(runtime)에 그 성격이 결정되는 것
Multiplex Inheritance(다중 상속) : 여러 개의 부모 클래스로부터 동시에 특성을 물려받는 것(일반적인 Programming Language에서는 허용X - C++, JAVA, etc...), Python은 허용 / 괄호 안에 특성을 물려받고 싶은 부모 클래스들을 콤마(,)를 사용하여 나열
class WolfDog(Wolf, Dog):
"""
import math


class Animal:
    def __init__(self, age, height, color, xpos, ypos):
        self.age = age
        self.height = height
        self.color = color
        self.xposition = xpos
        self.yposition = ypos
        self.velocity = 0
    def sound(self):
        pass

class Horse(Animal):
    def __init__(self, age, height, color, xpos, ypos):
        Animal.__init__(self, age, height, color, xpos, ypos)
    def sound(self):
        print('Neigh')
    def run(self, xdistance, ydistance, time):
        self.xposition += xdistance
        self.yposition += ydistance
        total_distance = math.sqrt((xdistance + xdistance) * (ydistance + ydistance))
        self.velocity = total_distance / time


class Dog(Animal):
    def __init__(self, age, height, color, xpos, ypos):
        Animal.__init__(self, age, height, color, xpos, ypos)
    def sound(self):
        print('Bow-Wow')

if __name__ == '__main__':
    danbi = Horse(5, 160, 'brown', 0, 0)
    choco = Dog(10, 100, 'black', 50, 30)
    danbi.sound() #결과 : Neigh
    choco.sound() #결과 : Bow-Wow

"""
Module : 1개의 Python file(Programming Language마다 정의가 다르다.)
Package : N개의 Module이 모인 file
간단 사용, 배포 가능

사용법 : import
import Module이름 : Module이름에 저장된 변수나 함수를 사용하겠다.
from Module이름 import* : Module이름에 저장된 변수나 함수를 전부 사용하겠다. 
from Module이름 import function명(Class명) : Module이름에 저장된 function명(Class명)을 사용하겠다.

ex - math, turtle
math Module - 수학관련 다양한 함수들과 상수들 정의 / Python에서 제공하는 기본 Module - 설치 필요X

turtle Module - code에 다라 그림 그려주는 Module / Python에서 제공하는 기본 Module - 설치 필요X
"""

import math

print(math.pi) #3.141592653589793 / 원주율
print(math.e) #2.718281828459045 / 오일러 상수

#중심이 (0,0)이고 반지름이 5인 원의 넓이와 θ=60˚일 때의 x와 y값
radius = 5.0
area = (radius ** 2) * math.pi
theta = math.radians(60)
x = radius * math.cos(theta)
y = radius * math.sin(theta)

print("area : " + str(area)) #area : 78.53981633974483
print("x : " + str(x)) #x : 2.5000000000000004
print("y : " + str(y)) #y : 4.330127018922193

"""
#사각형 그리는 예제
from turtle import *
forward(100)
right(90)
forward(100)
right(90)
forward(100)
right(90)
forward(100)
mainloop()
"""

#기하학적 도형 그리는 예제
from turtle import *
for i in range(20):
    forward(100)
    right(90)
    forward(100)
    right(90)
    forward(100)
    right(90)
    forward(100)
    right(72)
mainloop()
