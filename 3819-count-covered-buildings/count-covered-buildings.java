class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer,TreeSet<Integer>>rowMap=new HashMap<>();
        Map<Integer,TreeSet<Integer>>colMap=new HashMap<>();

        for (int[] b:buildings){
            int x=b[0],y=b[1];

            if (!rowMap.containsKey(x)){
                rowMap.put(x,new TreeSet<>());
            }
            rowMap.get(x).add(y);
            if (!colMap.containsKey(y)){
                colMap.put(y,new TreeSet<>());
            }
            colMap.get(y).add(x);
        }
        int ans=0;

        for (int[] b:buildings){
            int x=b[0],y=b[1];

            TreeSet<Integer>row=rowMap.get(x);
            TreeSet<Integer>col=colMap.get(y);

            Integer left=row.lower(y);
            Integer right=row.higher(y);
            Integer up=col.lower(x);
            Integer down=col.higher(x);

            if (left!=null && right!=null && up!=null && down!=null) ans++;
        }
        return ans;
    }
}