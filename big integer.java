
package problem;

/**
 *
 * @author Mouhanad.Neymar
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Problem {
    public static long n ;

static BigInteger  fact (  long x )
{ 
    if(x == 1 ) return BigInteger.ONE;
 BigInteger val =  BigInteger.valueOf(x);
 
 BigInteger ans = new  BigInteger("1") ;
 BigInteger a = new  BigInteger("1") ;
 
 for ( int i =0 ; i < x ; i++)
 {
 ans = ans.multiply(val);
   val = val.subtract(a);
}
 
 return ans ;
}
 static BigInteger mult ( long x)
{
    BigInteger val =  BigInteger.valueOf(n);
 
 BigInteger ans = new  BigInteger("1") ;
 BigInteger a = new  BigInteger("1") ;
 
 for ( int i =0 ; i < x ; i++)
 {
 ans = ans.multiply(val);
   val = val.subtract(a);
}
 
 return ans ;
}
static BigInteger func ( long x)
{ BigInteger ans1 =  mult(x);
  BigInteger ans2 =  fact(x);

    return  ans1.divide(ans2) ;
}
    
    public static void main(String[] args) {
        
        
    FastScanner cin = new FastScanner(System.in);
        n = cin.nextLong();
     String S = cin.next();
     
     System.out.println(S);
        
        long x1 = 7;
        long x2 = 6 ;
        long x3 = 5 ;
        BigInteger big1 = func(x1);
        BigInteger big2 = func(x2);
        BigInteger big3 = func(x3);
        
      System.out.print(big1.add(big2.add(big3)));
        
    }
    
}

class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
bi = 	new BigInteger(s);	Create BigInteger with decimal value represented by decimal String s.
bi = 	BigInteger.ONE;	Predefined value 1.
bi = 	BigInteger.ZERO;	Predefined value 0.
bi = 	BigInteger.valueOf(lng);	Use this factory method to create BigIntegers from numeric expressions. An int parameter will be automatically promoted to long.
Arithmetic operations
bi1 = 	bi2.abs();	Returns BigInteger absolute value.
bi1 = 	bi2.add(bi3);	Returns sum of bi2 and bi3.
bi1 = 	bi2.divide(bi3);	Returns division of bi2 and bi3.
bia = 	bi2.divideAndRemainder(bi3);	Returns array of two BigIntegers representing the result of division and remainder of bi2 and bi3.
bi1 = 	bi2.gcd(bi3);	Returns greatest common divisor of bi2 and bi3.
bi1 = 	bi2.max(bi3);	Returns maximum of bi2 and bi3.
bi1 = 	bi2.min(bi3);	Returns minimum of bi2 and bi3
bi1 = 	bi2.mod(bi3);	Returns remainder after dividing bi2 by bi3
bi1 = 	bi2.multiply(bi3);	Returns product of bi2 and bi3.
bi1 = 	bi2.pow(bi3);	Returns bi2 to the bi3 power.
bi1 = 	bi2.remainder(bi3);	Returns remainder of dividing bi2 by bi3. May be negative.
i = 	bi.signum();	-1 for neg numbers, 0 for zero, and +1 for positive.
bi1 = 	bi2.subtract(bi3);	Returns bi2 - bi3.
Conversion to other values
d = 	bi.doubleValue();	Returns double value equivalent of bi.
f = 	bi.floatValue();	Returns float value equivalent of bi.
i = 	bi.intValue();	Returns int value equivalent of bi.
lng = 	bi.longValue();	Returns long value equivalent of bi.
s = 	bi.toString();	Returns decimal string representation of bi.
s = 	bi.toString(i);	Returns string representation of bi in radix i.
Other
b = 	bi1.compareTo(bi2);	Returns negative number if bi1<bi2, 0 if bi1==bi2, or positive number if bi1>bi2.