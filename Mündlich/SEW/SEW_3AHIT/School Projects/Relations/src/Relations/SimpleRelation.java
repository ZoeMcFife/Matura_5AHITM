package Relations;

import java.util.*;

public class SimpleRelation<T> extends AnyRelation<T>
{
    Map<T, Set<T>> isRelatedTo = new HashMap<>();
    Set<T> valueSet;

    SimpleRelation(T[] set,  T... relations)
    {
        if (relations.length % 2 != 0)
            throw new IllegalArgumentException();

        for (T a : set)
        {
            if (!Arrays.stream(relations).toList().contains(a))
                throw new IllegalArgumentException();
        }

        for (int i = 0; i < relations.length; i+=2)
        {
            T a = relations[i];
            T b = relations[i + 1];

            if (!isRelatedTo.containsKey(a))
            {
                isRelatedTo.put(a, new HashSet<T>());
            }

            isRelatedTo.get(a).add(b);
        }

        this.valueSet = new HashSet<T>(List.of(set));
    }

    @Override
    public boolean isRelated(T a, T b)
    {
        if (isRelatedTo.containsKey(a))
        {
            return isRelatedTo.get(a).contains(b);
        }

        return false;
    }

    @Override
    public Set<T> theElements()
    {
        return valueSet;
    }

    @Override
    public boolean isRelationReflexive()
    {
        for (T a : valueSet)
        {
            if (!isRelatedTo.get(a).contains(a))
            {
                return false;
            }
        }

        return true;
    }

    @Override
    public boolean isRelationSymmetric()
    {
        for (T a : isRelatedTo.keySet())
        {
            for (T b : isRelatedTo.get(a))
            {
                if (!(isRelated(a, b) == isRelated(b, a)))
                    return false;
            }
        }
        return true;
    }
}
