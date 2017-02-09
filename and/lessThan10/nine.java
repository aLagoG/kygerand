
import java.math.BigInteger;
import java.util.Scanner;

public class nine {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int rad = in.nextInt();
        int orad = in.nextInt();
        BigInteger n = in.nextBigInteger(rad);
        System.out.println(n.toString(orad));
    }
}
