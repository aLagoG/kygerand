
import java.math.BigInteger;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Lago
 */
public class nine {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int rad = in.nextInt();
        int orad = in.nextInt();
        BigInteger n = in.nextBigInteger(rad);
        System.out.println(n.toString(orad));
    }
}
