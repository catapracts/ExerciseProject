package Test2021;

public class Test2107 
{
	static String check(int num)
	{
		return (num>=0) ? "positive" : "negative"; // 매개변수 num이 0보다 크거나 같으면, positive를, 다르면 negative를 출력한다.
	}
	
	
	public static void main(String[] args) 
	{
		System.out.println(Test2107.check(1)); //Test2107 class에 있는 함수 check 실행, 결과 : positive
		
		Test2107 a1 = new Test2107(); // Test2107객체 생성
		ovr2 a2 = new ovr2(); //ovr2객체 생성
		System.out.println(a1.sun(3,2) + a2.sun(3,2)); // 결과 : 11(= 5 + 6)
	}
	
	int sun(int x, int y) // Test2107 class에 명시된 함수
	{
		return x+y;
	}
	
}

class ovr2 extends Test2107 // Test2107을 상속받은 ovr2 클래스
{
	int sun(int x, int y) //Test2107 class에 있는 함수를 그대로 물려받고 내용만 다르게 재사용 = Overloading
	{
		return x - y + super.sun(x,y); // x-y하고 상위 클래스에 있는 sun함수 연산 후 반환 값 받아서 호출한 곳에 되돌려 주기
	}
}