package Compare;

import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class StoresInNeighbourhood
{
    public static void storesInNeighbourhood()
    {
        Store foodStore = new Store(new Point(4, 4), "Food Store");
        Store appleStore = new Store(new Point(3, 3), "Apple Store");
        Store carStore = new Store(new Point(2, 2), "Car Store");
        Store planeStore = new Store(new Point(1, 1), "Plane Store");

        List<Store> list = new ArrayList<>();
        list.add(foodStore);
        list.add(appleStore);
        list.add(carStore);
        list.add(planeStore);

        List<Store> around = StoresAroundUs.findStoresAround(list, new Point(5, 5));

        System.out.println(around);
    }
}
