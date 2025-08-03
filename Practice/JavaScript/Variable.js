// Variabe = 변수 / Value저장(할당) & 참조를위해 사용
// Variabe = 위치(주소=address)를 기억하는 저장소
// Variabe = Memory Address에 접근하기 위해 사람이 이해할 수 있는 언어로 지정한 식별자(Identifier)
// 선언 형태 : '데이터타입 변수이름 = 값;'
// DataType = Programming Language에서 사용할 수 있는 값의 종류
// Literal = Source Code안에서 직접 만들어 낸 상수 값 자체 / 값을 구성하는 최소 단위
// Value = 프로그램에 의해 조작될 수 있는 대상

var str = 'Hello World'; // javascript에서 변수 선언 예시

// Literal 종류들
10.50, 1001 //숫자
'Hello',"World" //문자열
true, false //Boolean
null //null
undefined // undefined
{name : 'a'; age : 1} // Object
[1,2,3] // Array
/ab+c/ //정규표현식
function() {} //함수

// JavaScript - Data Type(7) = Primitive(6) + Object
// Primitive - number, String Boolean, null, undefined, symbol
// JavaScript = C 나 JAVA와 달리 데이터 타입 미리 지정하지 않고, 할당된 값의 타입에 따라 자동으로 변수의 타입이 결정됨 = 동적 타이핑
var num = 1001; //number - 정수, 실수, -정수, 2/8/16진수 / Infinity, -Infinity, NaN(산술연산불가) 라는 표현도 가능
var str = 'Halo'; //String - ''(보통 사용), "" / 한 번 생성시 변경 불가능(immutable) - index통해 접근 가능(유사 배열) but 새롭게 할당은 가능
var bool = true; //Boolean - True, False / Flow Control에서 자주 사용 / 빈 문자열, undefined, 0 = false 취급
var nulls = null; // null - 선언은 됐는데, 값 할당 안 한 경우 / 의도적으로 변수에 값 없음을 명시 = Memory Address의 참조 정보 제거 = Garbage Collection 수행 / null은 Data Type = Object로 나온다(설계오류) 그래서 ===으로 확인해야 된다.
var bbar; // undefined - 선언은 됐는데, 값 할당 안 한 경우 / JavaScript Engine에 의해 초기화된 값
var aaaaa = Symbol('key'); // Symbol - ES6에서 새롭게 추가된 type, 변경 불가능 / 주로 이름의 충돌이 없는 유일 객체 property key를 만들기 위해 사용 - 유일값
var obj = {name : 'A', age : 10};
var array = [1,2,3];
var func = function() {}

//타입 연산자 - typeof
var type = typeof 'HH';

// instance 생성 연산자 - new
var today = new Date();

// type 강제 변환 - 자동으로 인식해서 값 처리
var aa = 1+'10'; // 110
var bb = 1*'10'; // 10

// Statement = Program을 수행하는 명령, ;으로 구분, {}(code block)으로 그룹화 가능, 완전한 하나의 문장
// Expression = 1개의 값
5 // 결과 : 5
5*10 // 결과 : 50
5*10>10 // 결과 : true
(5*10>10)&&(5*10<100) // 결과 : true

// Object = Primitives Data Type을 제외한 모든 Type, ex-function, array, 정규표현식, etc... / data와 data에 관련한 동작(절차, 방법, 기능)을 모두 포함할 수 있는 개념적 존재 = property & method 포함할 수 있는 독립적 주체
// JavaScript의 Object = property(key + value)의 집합 / property의 value가 function인 경우 method라고 부른다. / pass-by-reference 방식으로 전달
var aaa = {
    name : 'aaaa',
    age : 10,
    rise : function() {
        console.log('Hello world' + this.name);
    }
};
console.log(typeof aaa);
console.log(aaa);
aaa.rise();

// Array = 1개의 변수에 N개 값 순차 저장시 사용 / JavaScript의 Object로 내장 메소드 포함한다.
var arr = [1,2,3,4,5];
console.log(arr[1]); //2

// Variable Hoisting - 인터프리터가 코드를 실행하기 전에 함수, 변수, 클래스 또는 임포트(import)의 선언문을 해당 범위의 맨 위로 끌어올리는 것처럼 보이는 현상
// 변수 생성 3단계 - 선언 -> 초기화 -> 할당
// 선언 단계 : 변수 객체에 변수 등록 / Scope의 참조 대상
// 초기화 단계 : 변수 객체에 등록된 변수를 메모리에 할당 / 변수 = undefined로 초기화됨
// 할당 단계 - undefined로 최기화된 변수에 실제값 할당
// Scope - Function-Level / Block-Level
// Function-Level Scope : 함수 내부 변수는 함수 내부에서만 유효
// Block-Level Scope : Code Block 내부 변수는 Code Block 내부에서만 유효

// var - ES5에서 사용했던 keyword
// 특징1. Function-Level Scope 특징2. 키워드 생략 허용 특징3. 중복 선언 허용 특징4. 변수 Hoisting
// Scope문제로 오류 일어날 가능성 높다. / 이를 보완하기 위해 let & const라응 keyword 사용
// let - Block-Level Scope / 변수 중복 선언 X  / var보다 상대적으로 제한된 범위에서 사용이 가능 = 다른 변수나 메소드가 함부로 접근 X
// const - 상수 / let과 특징 거의 동일 / 재할당 불가능, 선언과 동시에 할당해야함 / 가독성 & 유지보수의 편의를 위해 적극 사용 / const로 객체 만든 경우 객체 자체는 재할당 불가능하지만, 객체안에 property는 변경 가능
// *변수 선언 시점에는 재할당 필요할지 잘 모르는 경우 多, 객체는 재할당 하는 경우가 드물다.


