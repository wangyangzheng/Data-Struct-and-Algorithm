import java.util.Scanner;
public class hanluota2{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        func(n, "left", "right", "mid");
    }
    //将六个函数抽象为1个方法
    /* 1. 1 - n 在from
     * 2. 去to
     * 3. 另一个：other
     */
    public static void func(int n, String from, String to, String other) {
        if (n == 1) {
            System.out.println("move 1 from " + from + " to " + other);
            return ;
        } else {
            // from 去 other to
            func(n -1, from, other, to);
            System.out.println("move " + " " + n + " " + from + " to " + to);
            func(n - 1, other, to, from);
        }
    }
}
