package JAVA;

class Grand {
    int a = 10;
}

class Parents extends Grand {
    int a = 20;
}

class Child extends Parents {
    int a = 30;
}

public class ex7 {
    public static void main(String[] args) {
        Grand a1 = new Grand();
        System.out.print(a1.a + ",");

        Grand a2 = new Parents();
        System.out.print(a2.a + ",");

        Grand a3 = new Child();
        System.out.print(a3.a);
    }
}
