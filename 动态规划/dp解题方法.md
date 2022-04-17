# 动态规划

## 暴力递归
- 暴力递归就是尝试
1. 把问题转化为规模缩小
2. 有明确的不需要继续进行递归的条件
3. 有当的得到了子问题的结果之后的决策过程
4. 不记录每个子问题的解

### 汉罗塔问题

![汉罗塔.jpg](https://pic.dogimg.com/2022/04/17/625bdf321d3b2.jpg)
- 条件：
1. 小压大
2. 从一根杆子上，移到右端

- 做法
1. 1 ~ n - 1圆盘从左移到中
2. 第n 个圆盘从左移到右
3. 1 ~ n - 1圆盘从左移到中
```Java
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

```
- 非递归

```java
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
```

