package JAVA;

class A {
    public void display() {
        System.out.print("A");
    }
}

class B extends A {
    public void display() {
        System.out.print("B");
        super.display();
        System.out.print("C");
    }
}

class C extends B {
    public void display(int a) {
        System.out.print("D");
    }
}

public class ex2 {
    public static void main(String args[]) {
        A obj = new C();
        obj.display();
    }    
}
