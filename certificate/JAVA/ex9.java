package JAVA;

import java.util.*;

public class ex9 {
    public static void main(String[] args) {
        LinkedList<Integer> ds = new LinkedList<Integer>();
        ds.addFirst(new Integer(10));
        ds.addFirst(new Integer(20));
        ds.addFirst(new Integer(30));
        while(!ds.isEmpty())
            System.out.print(ds.removeLast()+ " ");
        System.out.println();
    }
}
