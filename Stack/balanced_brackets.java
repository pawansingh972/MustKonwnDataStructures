import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static String isBalanced(String s) {
        // Complete this functionStack/Waiter_hackerRank.js
        Stack<Character> stack = new Stack<Character>();
        char brackets[] = s.toCharArray();
        boolean flag = true;
        for (int i = 0; i < brackets.length; i++) {
            if (brackets[i] == '{' || brackets[i] == '[' || brackets[i] == '(') {
                stack.push(brackets[i]);   
            } else if (brackets[i] == '}' || brackets[i] == ']' || brackets[i] == ')') {
                if (stack.size() > 0) {
                    switch (brackets[i]) {
                        case '}':
                            if (stack.pop() != '{') {
                                flag = false;    
                            }                        
                            break;
                        case ']':
                            if (stack.pop() != '[') {
                                flag = false;
                            }
                            break;
                        case ')':
                            if (stack.pop() != '(') {
                                flag = false;
                            }
                            break;
                    }                    
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (stack.size() == 0 && flag) {
            return "YES";
        } else {
            return "NO";    
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            String s = in.next();
            String result = isBalanced(s);
            System.out.println(result);
        }
        in.close();
    }
}
