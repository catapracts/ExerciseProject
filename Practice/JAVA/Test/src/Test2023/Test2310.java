package Test2023;

class P
{
	public int calc(int n)
	{
		if(n <= 1)	return n;
		return calc(n - 1) + calc(n - 2);
	}
}

class C extends P
{
	public int calc(int n)
	{
		if(n <= 1)	return n;
		return calc(n - 1) + calc(n - 3);
	}
}



class SuperObject
{
	public void draw()
	{
		System.out.print("A");
		draw();
	}
	
	public void paint()
	{
		System.out.print('B');
		draw();
	}
}

class SubObject extends SuperObject
{
	public void paint()
	{
		super.paint();
		System.out.print('C');
		draw();
	}
	
	public void draw()
	{
		System.out.print('D');
	}
}


public class Test2310 
{

	public static void main(String[] args) 
	{
		SuperObject a = new SubObject();
		a.paint();
		a.draw();
		
		System.out.println("\n====================");
		
		Person obj = new Person("Kim");
		obj.print();
		
		System.out.println("====================");
		
		P obj1 = new C();
		System.out.println(obj1.calc(7));

	}

}

class Person
{
	private String name;
	
	public Person(String val)
	{
		name = val;
	}
	
	/*
	public static String get()
	{
		return name;
	}
	*/
	
	public void print()
	{
		System.out.println(name);
	}
}



