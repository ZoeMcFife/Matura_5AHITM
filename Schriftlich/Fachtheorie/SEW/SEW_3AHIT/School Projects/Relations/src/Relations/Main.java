package Relations;

public class Main
{
    public static void main(String[] args)
    {
        SimpleRelation<Integer> simpleRelation = new SimpleRelation<>(new Integer[] {1, 2, 3}, 1, 2, 3, 2, 1, 3);

        System.out.println(simpleRelation.isRelatedTo);

        System.out.println(simpleRelation.isRelated(1,3));
        System.out.println(simpleRelation.isRelated(3,1));

        System.out.println(simpleRelation.theElements());

        System.out.println(simpleRelation.isRelationReflexive());

        SimpleRelation<Integer> reflexive = new SimpleRelation<>(new Integer[] {0, 2, 3, 5}, 0, 0, 2,2,2,3,3,2,3,3,5,5);

        System.out.println(reflexive.isRelatedTo);

        System.out.println(reflexive.isRelationReflexive());
        System.out.println(simpleRelation.isRelationReflexive());
        System.out.println(reflexive.isRelationSymmetric());
        System.out.println(simpleRelation.isRelationSymmetric());
    }
}
