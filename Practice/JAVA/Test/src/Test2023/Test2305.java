package Test2023;

abstract class Vehicle
{
	String name;
	abstract public String getName(String val);
	public String getName() //Vehicle로 이동했으므로 main에서 obj가 호출한 getName메소드 작동 시작
	{
		return "Vehicle name : " + name; // Vehicle name :  Vehicle에 저장된 name(= Spark = 아까 child에서 할당)
	}
}

class Car extends Vehicle // Car class는 Vehicle의 하위 클래스
{
	private String name;
	
	public Car(String val) // Car class의 시작
	{
		name = super.name = val; // 상위 class인 Vehicle과 자신이 가진 name 변수에 매개변수 val(= Spark)을 할당 -> super 예약어를 사용했으므로 Vehicle로 이동
	}
	
	public String getName(String val)
	{
		return "Car name : " + val;
	}
	
	public String getName(byte[] val)
	{
		return "Car name : "+ val;
	}
}


class Static
{
	public int a = 20;
	static int b = 0;
}


public class Test2305 
{

	public static void main(String[] args) 
	{
		int a = 10;
		Static.b = a;
		Static st = new Static();
		System.out.println(Static.b++); // 결과 : 10 / Static.b = 10 출력 후 -> 11로 변화
		System.out.println(st.b); // 결과 : 11 / Static.b = 11
		System.out.println(a); // 결과 : 10 / 여기서 a = main에 있는 a
		System.out.println(st.a); // 결과 : 20 / 여기서 a는 Class Static에 있는 a
		
		System.out.println("\n===============================\n");
		
		Vehicle obj = new Car("Spark"); // Vehicle type의 객체 변수 obj를 생성하고 인수로 "Spark"를 가진 Car type 객체 형태로 초기화 = Car, Vehicle 둘 다 사용 가능
		System.out.println(obj.getName()); // 결과 : Vehicle name : Spark
		
		System.out.println("\n===============================\n");
		
		Child c = new Child();
		System.out.println(c.getX()); // 결과 : 5000
	}

}

class Parent
{
	int x = 1000;
	
	Parent()
	{
		this(3000);
	}
	
	Parent(int x)
	{
		this.x = x;
	}
}

class Child extends Parent // Parent의 하위 클래스 이므로 super()라는 생성자가 생략되어 있다. = child로 들어오면 Parent에도 한 번은 올라간다.
{
	int x = 4000; // Child의 x = 4000
	
	Child() // Child의 기본 생성자
	{
		this(5000); // Child의 x를 4000 -> 5000으로 변경
	}
	
	Child(int x) // Child에 int형 매개변수가 들어온 경우 실행되는 함수 - Overloading
	{
		this.x = x; // 현재 Child의 x의 값에 매개변수로 들어온 x의 값을 대신 넣는다. = x = 4000 -> 들어온 x
	}
	
	int getX() // Child의 함수 
	{
		return this.x; // 현재 Child가 가진 x의 값을 반환한다. = 아까 4000 -> 5000으로 바뀌었으니 5000을 return
	}
}