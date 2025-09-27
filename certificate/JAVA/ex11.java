package JAVA;

public class ex11 {

    int size, top;
    int buf[];

    public void StackInt(int s) {
        buf = new int[s];
        size = s;
        top = -1;
    }

    public void push(int x) {
        buf[++top] = x;
    }

    public int pop() {
        return buf[top--];
    }

}
