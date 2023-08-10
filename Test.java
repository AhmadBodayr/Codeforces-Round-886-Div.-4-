import java.util.*;
import java.io.*;

public class Test {
    static long cost[] = {1, 10, 100, 1000, 10000};
    static long memo[][][] = new long[2000005][5][2];
    static long t;
    static String s;
    static long inf = 1000000000000000005l;

    public static long solve(int index, int maxi, int used) {
        if(index < 0) return 0;
        int c =  (int) s.charAt(index) - 'A';
        long out = memo[index][maxi][used];
        if(out != -1) return out;
        if(used == 1) {
            if(c >= maxi) {
                out = cost[c] + solve(index - 1, c, 1);
            } else {
                out = -cost[c] + solve(index - 1, maxi, 1);
            }
        } else {
            for(int curr = 0; curr < 5; curr++) {
                if(curr >= maxi) {
                    if(c == curr) {
                        long eval = cost[curr] + solve(index - 1, curr, 0);
                        out = Long.max(out, eval);
                    } else {
                        long eval = cost[curr] + solve(index - 1, curr, 1);
                        out = Long.max(out, eval);	
                    }
                } else {
                    if(c == curr) {
                        long eval = -cost[curr] + solve(index - 1, maxi, 0);
                        out = Long.max(out, eval);
                    } else {
                        long eval = -cost[curr] + solve(index - 1, maxi, 1);
                        out = Long.max(out, eval);
                    }
                }
            }
        }
        return memo[index][maxi][used] = out;
    }
    public static void main(String[]args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextLong();
        for(; t >= 0; t--) {
            s = sc.next();
            for(int i = 0; i < s.length(); i++) {
                for(int j = 0; j < 5; j++) {
                    for(int k = 0; k < 2; k++) {
                        memo[i][j][k] = -1;
                    }
                }
            }
            int maxi = (int) s.charAt(s.length() - 1) - (int) 'A';
            long out = solve(s.length() - 1, 0, 0);
            System.out.println(out);
        }
    } // end main
} // end class