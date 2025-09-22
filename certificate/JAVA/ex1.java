package JAVA;

class Parent {
    public void set_name(String param_n) {
        System.out.print("A");
    }

    public void set_age(int param_i) {
        System.out.print("B");
    }
}

class Child extends Parent {
    public void set_name(String param_n) {
        System.out.print("C");
    }

    public void set_height(int param_h) {
        System.out.print("D");
    }
}

public class ex1 {
    public static void main(String[] args) {
        Child c = new Child();
        c.set_name("James");
        c.set_age(95);
        c.set_height(188); 
    }    
}
