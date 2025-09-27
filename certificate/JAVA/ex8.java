package JAVA;

import java.util.*;

public class ex8 {
    public static void main(String[] args) {
        LinkedList<Integer> ds = new LinkedList<Integer>();
        ds.addLast(new Integer(10));
        ds.addLast(new Integer(30));
        ds.addLast(new Integer(20));
        while(!ds.isEmpty())
            System.out.print(ds.removeLast()+ " ");
        System.out.println();
    }
}
