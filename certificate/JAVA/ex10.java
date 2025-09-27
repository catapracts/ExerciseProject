package JAVA;

import java.util.*;

public class ex10 {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<Integer>();
        s.push(1); s.push(2); s.pop();
        s.push(3); s.push(4); s.pop();
        s.push(5);
        while(!s.empty()) {
            System.out.print(s.pop() + " ");
        }
    }
}
