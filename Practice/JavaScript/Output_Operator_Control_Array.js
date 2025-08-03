/*
JavaScript
- 결과를 HTML에 출력
- 출력 방식 : window.alert(), innnerHTML(property), document.write(), console.log()

1. window.alert()
- 가장 간단하게 출력 / 대화상자 이용해서 데이터 전달
(ex)
<script>
function alertDialogBox() {
    alert("출력방식 1");
}
</script>


2. innnerHTML(property)
- 실제 JavaScript code에서 출력을 위해 가장 많이 사용
- document객체의 method(getElementByID(), getElementsByTagName() 등)를 사용해서 HTML element 선택
- HTML element의 content or attribute 등을 쉽게 변경 가능
(ex)
<script>
    var str = document.getElementById("text");
    str.innerHTML = "text 대신 다른 값을 넣을 수 있다.";
</script>


3. document.write()
- Web Page loading중 실행 시, 가장 먼저 data 출력
- Web Page loading 이후 실행 시, 먼저 load된 data를 지우고 자기 data를 출력
- 보통 test or debug시 사용
(ex)
<script>
    document.write(4 * 5);
</script>


4. console.log()
- Web Browser의 console을 통해 data를 출력
- (Google Chrome기준) F12누르고 console이라는 tab을 누르면 확인이 가능하다
(ex)
<script>
    console.log(4 * 5);
</script>

*개발자마다 회사마다 상황마다 주로 쓰는 문법이 다르거나 다 사용할 수 있기 때문에, 상황에 따라 또는 편한대로 사용하는 게 좋다.
*/


/*
JavaScript Operator
*/

// 산수 Operator : +, -, *, / ,%
var x = 2, y = 1;
document.write(x + y + "<br>"); // 3
document.write(x - y + "<br>"); // 1
document.write(x * y + "<br>"); // 2
document.write(x / y + "<br>"); // 2
document.write(x % y);          // 0


// 대입 Operator : =, +=, -=, *=, /=, %=
var a = 4, b = 4, c = 4, d=4, e=4;
a-=2; // 결과 : a=2, a = a - 2;랑 동일한 표현
b+=2; // 결과 : b=6, b = b + 2;랑 동일한 표현
c*=2; // 결과 : c=8, c = c * 2;랑 동일한 표현
d/=2; // 결과 : d=2, d = d / 2;랑 동일한 표현
e%=2; // 결과 : e=0, e = e % 2;랑 동일한 표현


// 증감 Operator : ++, --
var x = 5, y = 5;
document.write((++x - 3) + "<br>"); // x+1 -> x=6 -> x-3 -> x=3
document.write(x + "<br>");         // 3
document.write((y++ - 3) + "<br>"); // y=5 -> y+1 -> y-3 -> y=3
document.write(y);                  // 3

// 비교 Operator : ==, ===, !=, !==, >, >=, <, <=
var x = 3, y = 5;
var a = "abc", b = "def";
document.write((x > y) + "<br>");  // 결과 : False
document.write((a <= b) + "<br>"); // 결과 : True -> 알파벳 순서상 'a'가 'b'보다 먼저 나오므로 'a'가 'b'보다 작음.

var x = 3, y = '3', z = 3;
document.write((x == y) + "<br>");  // 결과 : True -> == : 값만 같으면 형태가 달라도 강제 형변환 시켜준 뒤 비교 후 결과 반환
document.write((x === y) + "<br>"); // 결과 : False -> === : 값 + 형태 둘 다 같아야 True반환
document.write(x === z);            // 결과 : True 
document.write((x != y) + "<br>");  // 결과 : False -> != : 값만 같으면 형태가 달라도 강제 형변환 시켜준 뒤 비교 후 결과 반환
document.write((x !== y) + "<br>"); // 결과 : True -> !== : 값 + 형태 둘 다 달라야 True 반환


// 논리 Operator : &&, ||, !
var x = true, y = false;
document.write((x && y) + "<br>"); // 결과 : False
document.write((x || y) + "<br>"); // 결과 : True 
document.write(!x);                // 결과 : False


// 비트 Operator : &, |, ^, ~, >>, <<, >>>
var x = 15, y = 8, z = 15;
document.write((x << 1) + "<br>"); // 결과 : 30 = 1111(15) -> 11110(30)
document.write((y >> 1) + "<br>"); // 결과 : 4 = 1000(8) -> 0100(4)
document.write(~z);                // 결과 : -16 = 01111(15)->10000(16) 앞은 부호 비트 


//  기타 Operator : 3항(ternary), delete, typeof, instanceof, void

// Ternary Operator
var x = 3, y = 5;
var result = (x > y) ? x : y   // x>y -> True : return x, False : return y
document.write("둘 중에 더 큰 수는 " + result + "입니다."); // 결과 : 둘 중에 더 큰 수는 5입니다.


// Delete Operator : object, object의 property or Array의 element 등을 삭제 / 삭제 성공 = True, 삭제 실패 = False
var arr = [1, 2, 3];
delete arr[2]; // Array의 element 중 index=2(value : 3)인 element를 삭제
document.write(arr + "<br>"); // [1, 2, ] 
document.write(arr[2] + "<br>"); // Array에 빈자리 생성 : value = undefined
document.write(arr.length); // 결과 : 3 = Array의 길이 ↓X, Array의 element 삭제O


// typeof Operator : value에 대한 data type 반환
typeof "문자열"   // 결과 : string
typeof 10         // 결과 : number
typeof NaN        // 결과 : number
typeof false      // 결과 : boolean
typeof undefined  // 결과 : undefined
typeof new Date() // 결과 : object
typeof null       // 결과 : object


// instanceof Operator : object가 특정 object의 instance인지 판단 후 결과 반횐
var str = new String("이것은 문자열입니다.");
str instanceof Object;  // true
str instanceof String;  // true
str instanceof Array;   // false
str instanceof Number;  // false
str instanceof Boolean; // false


// void Operator : 항상 undefined만 반환
/*
<a href="javascript:void(0)">이 링크는 동작하지 않습니다.</a>
<a href="javascript:void(document.body.style.backgroundColor='yellow')">
    이 링크도 동작하지 않지만, HTML 문서의 배경색을 바꿔줍니다.
</a>
*/


/*
JavaScript Control Flow Statements
- 순차적인 흐름제어시 사용
- 조건문(Conditional - if, else if, else, switch), 반복문(Iteration - for, for in, for of, while, do while), 기타(label, continue, break)


- if - else if - else 형식 -> 3항연산자로 간단하게 표시 가능

if (표현식1) 
{
    표현식1 = 참일 때, 실행문;
}

else if (표현식2) 
{
    표현식2 = 참일 때, 실행문;
}
else 
{
    실행문;
}


- switch 형식

switch (조건 값) 
{
    case 값1:
        조건 값 = 값1일 때, 실행문;
        break;

    case 값2:
        조건 값 = 값2일 때, 실행문;
        break;
    ...
    default:
         실행문;
        break;
}

- while 형식
while (표현식) 
{
 실행문;
}


- do-while형식
do 
{
 실행문;
} while (표현식);


- for 형식
for (초기식; 표현식; 증감식) 
{
 실행문;
}


- for in 형식 : 해당 객체가 가진 모든 property return X, 열거 가능한 property만 return
for (변수 in 객체) 
{
 실행문;
}


- for of 형식 : 반복가능 객체들(ex - Array, Map, Set, Arguments 등)만 반복
for (변수 of 객체) 
{
 실행문;
}


- label 형식 : 프로그램 내의 특정 영역을 식별할 수 있도록 해주는 식별자 - continue랑 break 같이 사용
label:
식별하고자 하는 특정 영역

- continue 형식 : 루프 내에서 사용하여 해당 루프의 나머지 부분을 건너뛰고, 바로 다음 표현식의 판단으로 넘어가 / 반복문 내에서 특정 조건에 대한 처리를 제외하고자 할 때 자주 사용
continue; or continue 라벨이름;

- break 형식 : 루프 내에서 표현식의 판단 결과에 상관없이 반복문을 완전히 빠져나가고 싶을 때 사용
break; or break 라벨이름;

*/

//조건문(Conditional - if, else if, else, switch)

var x = 10, y = 20;
if (x == y) 
{
    document.write("x==y");
}
else if (x < y) 
{
    document.write("x<y");
}
else document.write("x>y"); // 실행문 = 한 줄 -> 중괄호({})를 생략가능

var x = 10;


switch (typeof x) // brreak 없으면 case 전부 실행된다.
{
    case "number":
        document.write("type = Number");
        break;

    case "string":
        document.write("type = String");
        break;

    case "object":
        document.write("type = Object");
        break;

    default:
        document.write("type = ?");
        break;
}


var day = new Date().getDay(); // 오늘의 요일을 반환

switch (day) //Switch case 축약형 - 여러 조건 한 번에 표시
{

    case 1: // 월요일
    case 2: // 화요일
    case 3: // 수요일
    case 4: // 목요일

    default: // 0부터 6까지의 값이 아닌 경우
        document.write("평일");
        break;

    case 5: // 금요일
        document.write("금요일");
        break;

    case 6: // 토요일
    case 0: // 일요일
        document.write("주말");
        break;
}


// 반복문(Iteration - for, for in, for of, while, do while)

var i = 1;
while (i < 10) 
{ // 변수 i가 10보다 작을 때만 while 문을 반복함.
    document.write(i + "<br>");
    i++; // 반복할 때마다 변수 i를 1씩 증가시켜 변수 i가 10보다 커지면 반복문을 종료함.
}

var i = 1, j = 1;
while (i > 3) 
{ // 변수 i의 초깃값은 1이기 때문에 이 while 문은 한 번도 실행되지 않음.
    document.write("i : " + (i++) + "<br>");
}

do 
{ // 변수 j의 초깃값은 1이기 때문에 이 do / while 문은 단 한 번만 실행됨.
    document.write("j : " + (j++) + "<br>");
} while (j > 3);


for (var i = 1; i < 10; i++) document.write(i + "<br>"); // 실행문 = 한 줄 -> 중괄호({})를 생략가능



// for of 이용해서 Array의 element에 접근
var arr = [3, 4, 5];
for (var i = 0; i < arr.length; i++)  //배열 arr의 모든 요소의 인덱스(index)를 출력함.
{
    document.write(i + " ");
}

// 위와 같은 동작

for (var i in arr) 
{
    document.write(i + " ");
}

// for in 이용해서 object의 property에 접근
var obj = { name : "aaa", age : 20 };
for (var i in obj) 
{
    document.write(i + "<br>");
}


// for of 이용해서 Array의 element에 접근
var arr = [3, 4, 5];
for (var i = 0; i < arr.length; i++) 
{
    document.write(arr[i] + " ");
}

// 위와 같은 동작

for (var value of arr) 
{
    document.write(value + " ");
}


// for of 이용해서 Set object의 property에 접근
var arr = new Set([1, 1, 2, 2, 3, 3]);
for (var value of arr) 
{
    document.write(value + " ");
}


// 기타 - label, continue, break
arrIndex: //arrIndex라는 Labe을 생성
for (var i in arr) // i라는 var변수 선언 label 中 arr이후부터 반복문 시작
{
   document.write(i); // i에 반복한 결과 저장 후 출력 -> 결과 : Index
}


//1부터 100까지의 정수 中 3의 배수를 제외하고 출력
var exceptNum = 3; // var변수 exceptNum선언 3으로 초기화
for (var i = 0; i <= 100; i++) // var변수 i선언 0~100까지 +1씩 증가 하면서 반복
{
    if (i % exceptNum == 0) continue; // 변수 i랑 exceptNum이랑 나누기 연산 후 나머지가 0이면 다음 실행문 실행 = 3의 배수 저장 안하고 넘기기
    document.write(i + " ");
}

// Label이용해서 9X9단 中 값이 홀수인 것만 출력
gugudan: //gugudan이라는 Label을 생성
for (var i = 2; i <= 9; i++) // var변수 i선언 2~9까지 +1씩 증가 하면서 반복
{
    dan: //dan이라는 Labe을 생성
    for (var j = 1; j <= 9; j++) // var변수 j선언 1~9까지 +1씩 증가 하면서 반복
    {
        if ((i*j) % 2 == 0) continue dan; // 변수 i랑 j랑 곱한 후 2로 나눴을 때, 나머지가 0이면, dan label로 이동 = 짝수 저장 안하고 넘기기
        document.write(i + " * " + j + " = " + (i*j) + "<br>");
    }
}


// Array에서 특정값을 가진 index 출력
var language = ["html", "css", "JS", "php"]; // var변수 language Array로 선언 후 초기화
var topic = "JS"; // var변수 topic으로 선언 후 초기화
for (var i = 0; i < language.length; i++) // var변수 i선언 0~language의 크기(4)까지 +1씩 증가 하면서 반복
{
    if (lectures[i] == topic) //language의 i번째 변수의 값이 topic변수의 값과 같다면
    {
        document.write(topic + " 과목은 " + (i + 1) + "번째 과목입니다."); // 출력
        break; // 원하는 값을 찾은 후에는 더 이상 for 문을 반복하지 않고 빠져나가기
    }
}


// Label이용해서 9X9단 中 3단까지만 출력
gugudan: //gugudan이라는 Label을 생성
for (var i = 2; i <= 9; i++) // var변수 i선언 2~9까지 +1씩 증가 하면서 반복
{
    dan:
    for (var j = 1; j <= 9; j++) // var변수 j선언 1~9까지 +1씩 증가 하면서 반복
    {
        if (i > 3)  break gugudan; // i가 3보다 크면 break, 그 전까지는 gugudan label로 돌아가기
        document.write(i + " * " + j + " = " + (i*j) + "<br>"); // 출력
    }
}


/*
배열(Array)
- 자바스크립트에서 배열(array) = 이름과 인덱스로 참조되는 정렬된 값의 집합 /  Array 객체로 다뤄진다.
- 배열 요소(element) = 배열을 구성하는 각각의 값 / 인덱스(index) = 배열에서의 위치를 가리키는 숫자
- 자바스크립트 배열의 특징 - 1.배열 요소끼리의 타입이 서로 다를 수도 있다 2.인덱스가 연속적이지 않아도 되며, 따라서 특정 배열 요소가 비어 있을 수도 있다 3. 자바스크립트에서 배열 = Array 객체
- 자바스크립트 - 배열 요소의 개수 = 배열의 길이, length 프로퍼티에 자동으로 갱신, 배열의 길이를 넘는 인덱스에 요소를 저장하는 것을 허용
- 인덱스 = 언제나 0부터 시작, 음이 아닌 정수를 반환하는 임의의 표현식도 사용가능, 인덱스에 대응하는 배열 요소가 없는 부분 = 배열의 홀(hole) =  undefined 값을 가지는 요소처럼 취급
- 배열 생성
1. var arr = [배열요소1, 배열요소2,...];          // 배열 리터럴을 이용하는 방법
2. var arr = Array(배열요소1, 배열요소2,...);     // Array 객체의 생성자를 이용하는 방법
3. var arr = new Array(배열요소1, 배열요소2,...); // new 연산자를 이용한 Array 객체 생성 방법


배열 요소의 추가
1. arr.push(추가할 요소);         // push() 메소드를 이용하는 방법
2. arr[arr.length] = 추가할 요소; // length 프로퍼티를 이용하는 방법
3. arr[특정인덱스] = 추가할 요소; // 특정 인덱스를 지정하여 추가하는 방법
- push(), length  = 모두 배열의 제일 끝에 새로운 요소를 추가


배열의 순회(iteration) - 배열의 모든 요소에 차례대로 접근하고 싶을 때는 for 문과 같은 반복문을 사용하여 접근


배열의 활용
1. 희소 배열 = 배열에 속한 요소의 위치가 연속적이지 않은 배열 = length > 배열 요소의 개수
2. 다차원 배열 = 배열 요소가 또 다른 배열인 배열 / 2차원 배열의 배열 요소는 [] 연산자를 두 번 사용하여 참조
3. 연관 배열(associative array) = 숫자로 된 인덱스 대신에 문자열로 된 키(key)를 사용하는 배열 / 자바스크립트 내부적으로 Array 객체에서 기본 객체로 재선언 = 기존에 사용할 수 있었던 모든 Array 메소드와 프로퍼티가 정확하지 않은 결괏값을 반환 가능성 有 / 정확히 말하면 배열X
*대부분의 프로그래밍 언어가 지원하는 연관 배열을 자바스크립트는 별도로 제공X / 대신에 인덱스로 문자열을 사용하여 연관 배열처럼 사용할 수 있는 객체(object)를 만드는 것이 가능
*ECMAScript 6부터는 이러한 불편함을 해결하기 위해 새로운 데이터 구조인 Map 객체를 별도로 제공


문자열을 배열처럼 접근하기
- 자바스크립트에서 문자열 = 변하지 않는 값 = 읽기 전용 배열 취급 가능
-  [] 연산자를 사용하여 문자열을 구성하는 각 문자에 바로 접근가능
- 문자열의 각 문자는 String 객체에서 제공하는 charAt() 메소드를 사용해도 접근가능
- Array 객체가 제공하는 모든 범용 메소드도 사용가능
- 인터넷 익스플로러 7과 그 이전 버전에서는 동작X, 문자열을 배열처럼 착각 -> 문자열을 바로 배열처럼 사용하지 말고, split() 메소드 등을 이용해 먼저 배열로 변환한 후 사용 권장


자바스크립트에서 배열 여부 확인
- 자바스크립트에서는 배열이라는 타입(type)을 별도로 제공X
- 확인 방법
1. Array.isArray() 메소드 - ECMAScript 5-> 구형 버전의 브라우저는 ECMAScript 5를 지원X
2. instanceof 연산자 - 주로 사용
3. constructor 프로퍼티 - function Array() {[native code]}



*/
var arrLit = [1, true, "JavaScript"];
var arrObj = Array(1, true, "JavaScript"); 
var arrNewObj = new Array(1, true, "JavaScript"); // new 연산자를 이용한 Array 객체 생성 방법
document.write(arrLit + "<br>");  // 1,true,JavaScript
document.write(arrObj + "<br>");  // 1,true,JavaScript 
document.write(arrNewObj);  // 1,true,JavaScript

var arr = ["JavaScript"]; // 요소가 하나뿐인 배열을 생성함.
var element = arr[0];     // 배열의 첫 번째 요소를 읽어서 대입함.
arr[1] = 10;      // 배열의 두 번째 요소에 숫자 10을 대입함. 배열의 길이는 1에서 2로 늘어남.
arr[2] = element; // 배열의 세 번째 요소에 변수 element의 값을 대입함. 배열의 길이는 2에서 3으로 늘어남.
document.write("배열 arr의 요소에는 [" + arr + "]가 있습니다.<br>"); // 배열의 요소를 모두 출력함.
document.write("배열 arr의 길이는 " + arr.length + "입니다.<br>");   // 배열의 길이를 출력함.
delete arr[2];    // 배열의 세 번째 요소를 삭제함. 하지만 배열의 길이는 변하지 않음.
document.write("배열 arr의 요소에는 [" + arr + "]가 있습니다.<br>"); // 배열의 요소를 모두 출력함.
document.write("배열 arr의 길이는 " + arr.length + "입니다.");       // 배열의 길이를 출력함.

var arr = [1, true, "Java"];
arr.push("Script");           // push() 메소드를 이용하는 방법
document.write(arr + "<br>"); // 1,true,Java,Script
arr[arr.length] = 100;        // length 프로퍼티를 이용하는 방법
document.write(arr + "<br>"); // 1,true,Java,Script,100
arr[10] = "자바스크립트";     // 특정 인덱스를 지정하여 추가하는 방법
document.write(arr + "<br>"); // 1,true,Java,Script,100,,,,,,자바스크립트
document.write(arr[7]);       // undefined

var arr = [1, true, "JavaScript"];
var result = "<table><tr>";
for (var idx in arr) 
{
    result += "<td>" + arr[idx] + "</td>";
}
result += "</tr></table>";
document.write(result);

var arr = new Array(10, "문자열", false);
document.write((typeof arr) + "<br>");    // object
document.write((typeof arr[0]) + "<br>"); // number
document.write((typeof arr[1]) + "<br>"); // string
document.write(typeof arr[2]);            // boolean


var arr = new Array(); // 빈 배열 객체를 생성함.
arr[99] = "JavaScript" // 배열 arr의 100번째 위치에 문자열을 삽입함.
// 100번째 요소를 삽입했기 때문에 배열의 길이는 100으로 늘어남.
document.write("배열의 길이는 " + arr.length + "입니다.");


var arr = new Array(3);      // 3개의 요소를 가지는 배열을 생성함.
for (var row = 0; row < 3; row++) 
{
    arr[row] = new Array(4); // 각각의 요소마다 또다시 4개의 요소를 가지는 배열을 생성함.

    for (var column = 0; column < 4; column++) 
    {
        arr[row][column] = "[" + row + "," + column + "]"; // 각각의 배열 요소를 생성함.
        document.write(arr[row][column] + " ");            // 각 배열 요소에 접근함.
    }
}


var arr = [];     // 비어있는 배열을 생성함.
arr["하나"] = 1;  // 숫자 인덱스 대신에 문자열을 인덱스로 배열 요소를 추가함.
arr["참"] = true;
arr["자바스크립트"] = "JavaScript";
document.write(arr["참"]);  // 문자열을 인덱스로 배열 요소에 접근할 수 있음.
document.write(arr.length); // 연관 배열은 Array 객체가 아니므로 length 프로퍼티의 값이 0임.
document.write(arr[0]);     // undefined


var str = "안녕하세요!";       // 문자열 생성
document.write(str.charAt(2)); // 하
document.write(str[2]);        // 하


var arr = [1, true, "JavaScript"]; // 배열 생성
document.write(typeof arr);        // object
document.write(Array.isArray(arr));      // true
document.write(Array.isArray("문자열")); // false
document.write(arr instanceof Array); // true
document.write(123 instanceof Array); // false


function isArray(a) 
{
    return a.constructor.toString().indexOf("Array") > -1;
}


var arr = [1, true, "JavaScript"];          // 배열 생성
document.write(arr.constructor);            // constructor 프로퍼티의 값 출력
document.write(arr.constructor.toString()); // function Array() {[native code]},  toString() 메소드를 사용하여 constructor 프로퍼티의 값을 문자열로 변환
document.write(arr.constructor.toString().indexOf("Array")); // 10, indexOf() 메소드는 인수로 전달받은 문자열을 해당 문자열에서 찾지 못하면, 언제나 -1을 반환
document.write(isArray(arr))                // true - 변수 arr가 배열이라면 "Array"라는 부분 문자열을 언제나 포함 = 결과는 언제나 true

