import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int t = in.nextInt();
	BigInteger a, b;
	while(t > 0){
	    t--;
	    a = in.nextBigInteger();
	    b = in.nextBigInteger();
	    System.out.println(a.divide(b));
	}
    }
}
