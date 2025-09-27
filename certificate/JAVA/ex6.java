package JAVA;

class A {
    public static void display() {
        System.out.print("A");
    }
}

class B extends A {
    public static void display() {
        System.out.print("B");
    }
}

class C extends B {
    public static void display() {
        System.out.print("C");
    }
}

public class ex6 {
    public static void main(String[] args){
        A obj1 = new A();
        A obj2 = new B();
        A obj3 = new C();

        obj1.display();
        obj2.display();
        obj3.display();
    }
}
