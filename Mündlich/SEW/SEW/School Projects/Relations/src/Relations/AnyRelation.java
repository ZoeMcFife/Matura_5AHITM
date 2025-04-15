package Relations;

import java.util.Set;

public abstract class AnyRelation<T>
{
    public abstract boolean isRelated(T a, T b);
    public abstract Set<T> theElements();
    public abstract boolean isRelationReflexive();
    public abstract boolean isRelationSymmetric();
}
