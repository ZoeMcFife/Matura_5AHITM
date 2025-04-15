package gay.fox.plftest;

import java.util.HashMap;

public class FoxModel
{
    private final HashMap<String, Fox> foxMap = new HashMap<>();

    public void addFox(Fox fox)
    {
        foxMap.put(fox.getName(), fox);
        System.out.println("added fox \n" + fox);
    }

    public Fox getFox(String name)
    {
        return foxMap.get(name);
    }

    public boolean doesFoxExist(String name)
    {
        return this.foxMap.containsKey(name);
    }
}
