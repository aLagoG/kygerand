
import java.util.Calendar;
import java.util.Date;
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
