/**
 * Created by kevin on 2/28/2017.
 */

import java.util.GregorianCalendar;
import java.util.Scanner;
import java.util.Calendar;

public class three {

    public static void main(String[] args) {
        String[] weekdays={"","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the day");
        int day=sc.nextInt();
        System.out.println("Enter the month in numbers");
        int month=sc.nextInt();
        System.out.println("Enter the year");
        int year=sc.nextInt();
        Calendar cal=new GregorianCalendar(year,month-1,day);
        System.out.println(weekdays[cal.get(Calendar.DAY_OF_WEEK)]);
    }
}
