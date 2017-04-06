import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int exponent = sc.nextInt();

		BigInteger two = new BigInteger("2");
		BigInteger res = two.pow(exponent*2);

		res = res.subtract(new BigInteger("1"));
		System.out.println(res.toString(8));
	}
}