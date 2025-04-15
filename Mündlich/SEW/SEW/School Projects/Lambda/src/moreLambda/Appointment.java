package moreLambda;

import java.sql.Time;
import java.time.LocalDateTime;
import java.util.*;

public class Appointment
{
    public String description;
    public String city;
    public LocalDateTime time;

    Appointment(String description, String city, LocalDateTime time)
    {
        this.description = description;
        this.city = city;
        this.time = time;
    }

    @Override
    public String toString()
    {
        return "Appointment{" +
                "description='" + description + '\'' +
                ", city='" + city + '\'' +
                ", time=" + time +
                '}';
    }

    public static void main(String[] args)
    {
        Appointment[] appointments = {
                new Appointment("Meow", "Nyatown", LocalDateTime.of(2023, 3, 3, 9, 20, 10)),
                new Appointment("Woof", "wooftown", LocalDateTime.of(2023, 3, 5, 9, 20, 10)),
                new Appointment("Yip", "foptown", LocalDateTime.of(2022, 1, 3, 9, 10, 10)),
                new Appointment("Rawr", "tigtown", LocalDateTime.of(2023, 3, 3, 15, 20, 10))
        };

        List<Appointment> appointmentList = Arrays.asList(appointments);

        appointmentList.sort(Comparator.comparing(o -> o.time));

        System.out.println(appointmentList);
    }
}
