package Test2021;

class Connection 
{
	private static Connection __inst = null; // 객체 변수만 생성(new 안 쓰고) = Stack영역에만 공간 확보
	private int count = 0; // 정수형 변수 count 선언 후 0으로 초기화
	public static Connection get() 
	{
		if(__inst == null) 
		{
			__inst = new Connection();
			return __inst;
		}
		
		return __inst;
	}
	
	public void count() { count++; }
	public int getCount() { return count; }
}

public class Test2110 
{

	public static void main(String[] args) 
	{
		Connection conn1 = Connection.get(); // Connection 클래스의 객체변수 conn1 선언 후 Connection class안의 get method를 이용한 결과 저장
		conn1.count(); // conn1에 있는 count함수 실행
		
		Connection conn2 = Connection.get(); // Connection 클래스의 객체변수 conn2 선언 후 Connection class안의 get method를 이용한 결과 저장
		conn2.count(); // conn2에 있는 count함수 실행
		
		Connection conn3 = Connection.get(); // Connection 클래스의 객체변수 conn3 선언 후 Connection class안의 get method를 이용한 결과 저장
		conn3.count(); // conn3에 있는 count함수 실행
		
		System.out.println(conn1.getCount());
		
		
		int w = 3, x = 4, y = 3, z = 5;
		if((w == 2 | w == y) & !(y>z) & (1 == x ^ y != z))
		{
			w = x + y;
			if(7 == x ^ y != w)
				System.out.println(w);
			else
				System.out.println(x);
		}
		
		else
		{
			w = y + z;
			if(7 == y ^ z != w)
				System.out.println(w);
			else
				System.out.println(z);
		}

	}

}
