import java.util.Scanner;
import java.math.BigInteger;

public class Main{
    public static void main(String[] args){
	BigInteger sum = BigInteger.valueOf(0);
	Scanner cin = new Scanner(System.in);
	while(cin.hasNext()){
	    BigInteger n = cin.nextBigInteger();
	    sum.add(n);
	}
	System.out.println(sum);
    }
}
