import java.*;
import java.util.Scanner;

public class Main{
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        leftToRight(n);
    }
    public static void leftToRight(int n) {
        if (n == 1) {
            System.out.println("move 1 from left to right");
            return;
        }
        //从1到n - 1左到中
        leftToMid(n - 1);
        //第n 个圆盘左边到右边
        System.out.println("move " + n + " from left to right");
        //然后让1到 n - 1中间到右边
        midToRight(n - 1);
    }
    public static void leftToMid(int n) {
        if (n == 1) {
            System.out.println("move 1 from left to mid");
            return;
        }
        //从1到n - 1左到右边
        leftToRight(n - 1);
        //第n 个圆盘左边到中边
        System.out.println("move " + n + " from left to Mid");
        //然后让1到 n - 1右边到中间
        rightToMid(n - 1);
    }
    public static void midToRight(int n) {
        if (n == 1) {
            System.out.println("move 1 from mid to right");
        }
        //从1到n - 1中间到左边
        midToLeft(n - 1);
        // 第n 个圆盘中间边到右边
        System.out.println("move " + n + " from mid to right");
        //从1到n - 1左边间到右边
        leftToRight(n - 1);
    }
    public static void midToLeft(int n) {
        if (n == 1) {
            System.out.println("move 1 from mid to left");
            return ;
        }
        midToRight(n - 1);
        System.out.println("move " + n + " from mid to left");
        rightToLeft(n - 1);
    }
    public static void rightToMid(int n){
        if (n == 1) {
            System.out.println("move 1 from right to mid");
            return ;
        }
        rightToLeft(n - 1);
        System.out.println("move " + n + " right to mid");
        leftToMid(n - 1);
    }
    public static void rightToLeft(int n){
        if (n == 1) {
            System.out.println("move 1 from right to left");
            return ;
        }
        rightToMid(n - 1);
        System.out.println("move " + n + " from right to left");
        midToRight(n - 1);
    }
}
