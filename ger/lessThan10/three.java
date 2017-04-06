import java.util.Scanner;
import java.util.Date;
import java.util.Calendar;

public class three{
    public static void main(String[] args) {
        String[] days = {"","Sunday","Monday","Tuesday","Wednesday","Tursday","Friday","Saturday"};
        Scanner in = new Scanner(System.in);
        Calendar calendar = Calendar.getInstance();

        calendar.setTime(new Date(in.nextLine()));
        System.out.println(days[calendar.get(Calendar.DAY_OF_WEEK)]);
    }
}
