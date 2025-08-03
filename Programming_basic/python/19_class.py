"""
class = 무언가를 만들어 내는 틀
object = class로 만들어 낸 결과물
__init__ = Object를 만들면 자동으로 실행되는 method, init에 있는 매개변수 사용해야함
Python의 모든 것은 객체다 - 정수, 문자열 등 전부 다 객체

"""

class User:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def hello(self):
        print(f"Hello I'm a {self.name}")


user1 = User("F-22", "1992")
user1.hello()
print(user1.name)
print(user1.age)

user2 = User("F-15", "1974")
user2.hello()
print(user2.name)
print(user2.age)

temp = [1,2,3,4,5]
print(type(temp)) # <class 'list'>
print(type(user1)) # <class '__main__.User'>