import java.math.BigInteger;
import java.io.*;
import java.util.*;

public class J10007{

    public static BigInteger factorial(int n){
        BigInteger fact = BigInteger.ONE;
        for(int i = 0 ; i  < n ; ++i){;
            fact = fact.multiply(new BigInteger(Integer.toString(i)));
        }
        return fact;
    }

    public static BigInteger catalan(int n){
        BigInteger c  = factorial(2*n).divide((factorial(n+1).multiply(factorial(n))));
        return c;
    }

    public static BigInteger solve(int n){
        return catalan(n).multiply(factorial(n));
    }


    public static void main(String args[])throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            
        
        int n = Integer.parseInt(br.readLine().trim());
        if( n == 0)break;
        System.out.println(solve(n).toString());
        }
    }
}
