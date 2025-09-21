import java.util.*;

class MovieRentingSystem {
    private Map<Integer, TreeSet<int[]>> available; // movie -> available shops (price, shop)
    private TreeSet<int[]> rented; // all rented (price, shop, movie)
    private Map<String, Integer> priceMap; // (shop,movie) -> price
    
    public MovieRentingSystem(int n, int[][] entries) {
        available = new HashMap<>();
        rented = new TreeSet<>((a,b) -> 
            a[0]!=b[0] ? a[0]-b[0] : (a[1]!=b[1] ? a[1]-b[1] : a[2]-b[2])
        );
        priceMap = new HashMap<>();
        
        for (int[] e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap.put(shop + "," + movie, price);
            available.computeIfAbsent(movie, k -> new TreeSet<>(
                (a,b) -> a[0]!=b[0] ? a[0]-b[0] : a[1]-b[1]
            ));
            available.get(movie).add(new int[]{price, shop});
        }
    }
    
    public List<Integer> search(int movie) {
        List<Integer> res = new ArrayList<>();
        if (!available.containsKey(movie)) return res;
        Iterator<int[]> it = available.get(movie).iterator();
        int count = 0;
        while (it.hasNext() && count < 5) {
            res.add(it.next()[1]);
            count++;
        }
        return res;
    }
    
    public void rent(int shop, int movie) {
        int price = priceMap.get(shop + "," + movie);
        available.get(movie).remove(new int[]{price, shop});
        rented.add(new int[]{price, shop, movie});
    }
    
    public void drop(int shop, int movie) {
        int price = priceMap.get(shop + "," + movie);
        rented.remove(new int[]{price, shop, movie});
        available.get(movie).add(new int[]{price, shop});
    }
    
    public List<List<Integer>> report() {
        List<List<Integer>> res = new ArrayList<>();
        Iterator<int[]> it = rented.iterator();
        int count = 0;
        while (it.hasNext() && count < 5) {
            int[] cur = it.next();
            res.add(Arrays.asList(cur[1], cur[2]));
            count++;
        }
        return res;
    }
}
