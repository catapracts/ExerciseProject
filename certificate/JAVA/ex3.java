package JAVA;

class X {
    X() {
        System.out.printf("%d ", 5);
    }
}

class Y extends X {
    Y() {
        System.out.printf("%d ", 15);
    }

    Y(int a) {
        this();
        System.out.printf("%d ", a);
    }
}

class Z extends Y {
    Z() {
        super(25);
        System.out.printf("%d ", 35);
    }
}

public class ex3 {
    public static void main(String[] args) {
        X obj1 = new Y();
        System.out.println();
        X obj2 = new Z();
        System.out.println();
        Z obj3 = new Z();
    }
}
