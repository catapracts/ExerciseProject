package Test2022;

class A
{
	int a;
	int b;
}


public class Test2205 
{
	static void func1(A m)
	{
		m.a *= 10;
	}
	
	static void func2(A m)
	{
		m.a += m.b;
	}

	public static void main(String[] args) 
	{
		A m = new A();
		m.a = 100;
		func1(m); // m.a = 100 * 10 = 1000
		m.b = m.a; // m.b = m.a = 1000
		func2(m); // m.a = 1000 + 1000 = 2000
		System.out.printf("%d\n", m.a);
		
		Thread t1 = new Thread(new Car());
		t1.start();

	}
}

class Car implements Runnable
{
	int a;
	public void run()
	{
		try
		{
			while(++a < 100) // a가 1~99까지 반복
			{
				System.out.println("miles traveled : " + a);
				Thread.sleep(100);
			}
		} catch(Exception E) {}
	}
}
