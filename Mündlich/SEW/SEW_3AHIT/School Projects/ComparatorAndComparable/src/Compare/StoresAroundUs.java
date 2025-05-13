package Compare;

import java.awt.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class StoresAroundUs
{
    public static List<Store> findStoresAround(Collection<Store> stores, Point center)
    {
        List<Store> storeList = new ArrayList<>();
        storeList.addAll(stores);
        storeList.sort(new StoreComparator(center));

        return storeList;
    }
}
