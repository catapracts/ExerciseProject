package Java;

import java.util.Scanner;

public class Calculator {

    class Calculator_Funnction {
        int Add(int a, int b) {
            int z = a + b;
            System.out.println( a + " + " + b + " = " + z );
            return z;
        }

        int Subtract(int a, int b) {
            int z = a - b;
            System.out.println( a + " - " + b + " = " + z );
            return z;
        }

        double Product(double a, double b) {
            double z = a * b;
            System.out.println( a + " * " + b + " = " + z );
            return z;
        }

        double Divide(double a, double b) {
            double z = a / b;
            System.out.println( a + " / " + b + " = " + z );
            return z;
        }
    }

    public static void main(String args[]) {
        
        int a, b;
        double c, d;
        
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
        announcement.append("Input Type is not matched\n");
        announcement.append("Try again\n");

        while(true){
            System.out.println(announcement.toString());
            int num = sc.nextInt();
            if(num == 1) {
                System.out.println(" Add Function Begin");
                System.out.print(" Enter the Two input : ");
                a = sc.nextInt();
                b = sc.nextInt();
                

            }

        }
    }

};


