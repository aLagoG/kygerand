
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
public class ten {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        String out = input.replaceAll("(?i)\\b[a-z][0-9]{2}\\b", "***");
        System.out.println(out);
    }
}
