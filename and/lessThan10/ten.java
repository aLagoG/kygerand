
import java.util.Scanner;

public class ten {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        String out = input.replaceAll("(?i)\\b[a-z][0-9]{2}\\b", "***");
        System.out.println(out);
    }
}
