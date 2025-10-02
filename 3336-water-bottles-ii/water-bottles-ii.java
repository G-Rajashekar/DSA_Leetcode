class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        int empty=0;
        while(numBottles>0){
            ans+=numBottles;
            empty=empty+numBottles;
            numBottles=0;
            while(empty>=numExchange){
                empty-=numExchange;
                numBottles+=1;
                numExchange++;
            }
        }
        return ans;
    }
}