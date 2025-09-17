import java.util.*;
class FoodRatings {
    Map<String,Integer>foodToRating=new HashMap<>();
    Map<String,TreeSet<Map.Entry<Integer,String>>>cuisine_rating_food=new HashMap<>();
    Map<String,String>food_cuisine=new HashMap<>();
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        int n=foods.length;

        for (int i=0;i<n;i++){
            foodToRating.put(foods[i],ratings[i]);
            food_cuisine.put(foods[i],cuisines[i]);
            if (!cuisine_rating_food.containsKey(cuisines[i])){
                cuisine_rating_food.put(cuisines[i],new TreeSet<>((a,b)->{
                    int compareByRating=Integer.compare(b.getKey(),a.getKey());
                    if (compareByRating==0){
                        return a.getValue().compareTo(b.getValue());
                    }
                    return compareByRating;
                }));
            }

           cuisine_rating_food.get(cuisines[i])
                    .add(new AbstractMap.SimpleEntry<>(ratings[i], foods[i]));
        }
    }
    
    public void changeRating(String food, int newRating) {
        String cuisine=food_cuisine.get(food);
        TreeSet<Map.Entry<Integer,String>>cuisineSet=cuisine_rating_food.get(cuisine);

        Map.Entry<Integer,String>oldOne=new AbstractMap.SimpleEntry<>(foodToRating.get(food),food);
        cuisineSet.remove(oldOne);
        Map.Entry<Integer,String>newOne=new AbstractMap.SimpleEntry<>(newRating,food);
        cuisineSet.add(newOne);
        foodToRating.put(food,newRating);

    }
    
    public String highestRated(String cuisine) {
        return cuisine_rating_food.get(cuisine).first().getValue();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */