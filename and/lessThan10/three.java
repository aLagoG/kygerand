
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class three {
    public static void main(String[] args) {
        String[] dt = {"","Sunday","Monday","Tuesday","Wednesday","Tursday","Friday","Saturday"};
        Calendar c = Calendar.getInstance();
        Scanner in = new Scanner(System.in);
        Date d = new Date(in.nextLine());
        c.setTime(d);
        System.out.println(dt[c.get(Calendar.DAY_OF_WEEK)]);
    }
}
