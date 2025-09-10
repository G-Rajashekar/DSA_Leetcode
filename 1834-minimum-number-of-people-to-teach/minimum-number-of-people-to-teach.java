class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer>sadUsers=new HashSet<>();

        for (int [] friend:friendships){
            int u=friend[0]-1;
            int v=friend[1]-1;

            Set<Integer>lang=new HashSet<>();

            for (int l:languages[u]){
                lang.add(l);
            }

            boolean canTalk=false;

            for (int l:languages[v]){
                if (lang.contains(l)){
                    canTalk=true;
                    break;
                }
            }
            if (canTalk==false){
                sadUsers.add(u);
                sadUsers.add(v);
            }
        }

        int maxKnown=0;

        int[] freq=new int[n+1];

        for(int user:sadUsers){
            for (int l:languages[user]){
                freq[l]++;
                maxKnown=Math.max(maxKnown,freq[l]);
            }
        }
        return sadUsers.size()-maxKnown;
    }
}