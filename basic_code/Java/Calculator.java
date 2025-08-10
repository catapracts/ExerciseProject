package Java;

import java.util.Scanner;

public class Calculator {

    public static int Add(int a, int b) {
        int z = a + b;
        System.out.println( a + " + " + b + " = " + z );
        return z;
    }

    public static int Subtract(int a, int b) {
        int z = a - b;
        System.out.println( a + " - " + b + " = " + z );
        return z;
    }

    public static double Product(double a, double b) {
        double z = a * b;
        System.out.println( a + " * " + b + " = " + z );
        return z;
    }

    public static double Divide(double a, double b) {
        double z = a / b;
        System.out.println( a + " / " + b + " = " + z );
        return z;
    }

    public static boolean isInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e){
            return false;
        }
    }

    public static boolean isDouble(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (NumberFormatException e){
            return false;
        }
    }

    public static void announcement () {
        StringBuilder announcement = new StringBuilder();
        announcement.append("Calculator System Activated\n");
        announcement.append("Choose menu\n");
        announcement.append("============================\n");
        announcement.append("1. Add\n");
        announcement.append("2. Subtract\n");
        announcement.append("3. Product\n");
        announcement.append("4. Divide\n");
        announcement.append("5. Terminate\n");
        announcement.append("============================\n");
        announcement.append("input : ");
        System.out.println(announcement);        
    }


    public static void main(String args[]) {
        
        int a, b, result;
        double c, d, result1;
        String input1, input2;
        
        Scanner sc = new Scanner(System.in);
        StringBuilder announcement = new StringBuilder();
        announcement.append("Calculator System Activated\n");
        announcement.append("Choose menu\n");
        announcement.append("============================\n");
        announcement.append("1. Add\n");
        announcement.append("2. Subtract\n");
        announcement.append("3. Product\n");
        announcement.append("4. Divide\n");
        announcement.append("5. Terminate\n");
        announcement.append("============================\n");
        announcement.append("input : ");

        StringBuilder announcement1 = new StringBuilder();
        announcement1.append("Input Type is not matched\n");
        announcement1.append("Try again\n");

        while(true){
            System.out.println(announcement.toString());
            int num = sc.nextInt();
            if(num == 1) {
                System.out.println("Add Function Begin");
                System.out.print("Enter the Two input : ");
                input1 = sc.next();
                input2 = sc.next();
                if(isInteger(input1) && isInteger(input2)){
                    a = Integer.parseInt(input1);
                    b = Integer.parseInt(input2);
                    result = Add(a, b);
                } else {
                    System.out.println(announcement1);
                    sc.nextLine();
                }
            }

            if(num == 2) {
                System.out.println("Subtract Function Begin");
                System.out.print("Enter the Two input : ");
                input1 = sc.next();
                input2 = sc.next();
                if(isInteger(input1) && isInteger(input2)){
                    a = Integer.parseInt(input1);
                    b = Integer.parseInt(input2);
                    result = Subtract(a, b);
                } else {
                    System.out.println(announcement1);
                    sc.nextLine();
                }
            }

            if(num == 3) {
                System.out.println("Product Function Begin");
                System.out.print("Enter the Two input : ");
                input1 = sc.next();
                input2 = sc.next();
                if(isDouble(input1) && isDouble(input2)){
                    c = Double.parseDouble(input1);
                    d = Double.parseDouble(input2);
                    result1 = Product(c, d);
                } else {
                    System.out.println(announcement1);
                    sc.nextLine();
                }
            }

            if(num == 4) {
                System.out.println("Divide Function Begin");
                System.out.print("Enter the Two input : ");
                input1 = sc.next();
                input2 = sc.next();
                if(isDouble(input1) && isDouble(input2)){
                    c = Double.parseDouble(input1);
                    d = Double.parseDouble(input2);
                    if(d == 0){
                        System.out.println("It can't be calculated");
                        System.out.println("Zero base makes Infinity");
                    }
                    else {
                        result1 = Divide(c, d);
                    }
                } else {
                    System.out.println(announcement1);
                    sc.nextLine();
                }
            }

            if(num == 5) {
                System.out.println("Calculator Quit");
                sc.close();
                break;
            }
        }
    }
};

/*
method = function
public: 접근 제어자 (다른 클래스에서도 사용 가능)
static: 클래스 메서드 (객체를 만들지 않고 호출 가능)
void: 반환값이 없다는 의미
int, String: 반환값 또는 매개변수 타입

- 자바에서 객체의 데이터 타입(클래스)을 확인하려면 instanceof / Object로 받아서 instanceof 사용
- 자바에서 입력은 보통 String 형태로 받기 때문에, 입력한 문자열이 정수로 바뀔 수 있는지 확인하는 작업 필요
- 자바는 동적 타입 언어가 아니기 때문에, 파이썬처럼 type() 같은 걸로 바로 타입을 알 수 없음 그래서 예외 처리를 통해 판단하는 방식이 일반적

1. Scanner로 받은 입력 = String
-> 먼저 정수로 파싱하거나 타입 변환을 해야 정수형인지 확인 가능

2. 사용자의 입력 자체가 이미 int형으로 넘어오는 경우는 거의 없고, 
보통 String → 변환 → 타입 체크의 순서

sc.next()는 공백 기준으로 한 단어 입력 받을 때 사용.
- next()는 공백 단위로 끊어서 입력 받음 / (ex) Hello World를 한 줄로 입력하면, next()가 두 번 호출되면서 각각 Hello, World를 받게 됨
- 단어, 정수 하나 입력시 사용

sc.nextLine()은 엔터(\n)를 누를 때까지 입력 전체를 문자열로 취급
- 문장 전체, 공백 포함된 입력시 사용

*숫자나 단어를 next(), nextInt() 등으로 입력받은 다음에 nextLine()을 쓸 경우,
중간에 sc.nextLine()을 한 번 더 호출해서 버퍼 비우기:
(ex)
int number = sc.nextInt();
sc.nextLine(); // 버퍼 비우기
String str = sc.nextLine(); // 제대로 읽힘

- System.in을 사용하는 Scanner는 닫으면 다시 사용할 수 없음 그래서 프로그램 종료 직전이 아니라면 System.in 기반 Scanner는 가능하면 닫지 않음
- File, Socket, InputStream 등으로 만든 Scanner 파일/네트워크 리소스 해제 필요하므로 close 필요
- 콘솔 입력용 Scanner sc = new Scanner(System.in);는 보통 main()이 끝나기 직전에 한 번만 닫기 (아니면 그냥 열어둠)
- 파일이나 외부 입력을 다룰 때는 반드시 close() 또는 try-with-resources 사용
(ex)
try (Scanner fileScanner = new Scanner(new File("input.txt"))) {
    while (fileScanner.hasNextLine()) {
        System.out.println(fileScanner.nextLine());
    }
} // 여기서 자동으로 fileScanner.close() 호출됨

*/
