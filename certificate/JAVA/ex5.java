package JAVA;

class Person {
    String name;
    
    public Person(String n) { name = n;}
    
    public void whoRU() {
        System.out.println(name);
    }
}

class Student extends Person {
    String school;
    
    public Student(String n, String s) {
        super(n);
        school = s;
    }

    public void whoRU() {
        System.out.println(school+", "+name);
    }
}

public class ex5 {
 public static void main(String args[]) {
    Person obj = new Student("Lee", "Suji");
    obj.whoRU();
 }   
}
