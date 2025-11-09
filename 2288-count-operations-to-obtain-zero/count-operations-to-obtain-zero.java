class Solution {
    public int countOperations(int num1, int num2) {
        int op=0;
        while(num1!=0 && num2!=0){
            if (num1>=num2){
                int q=num1/num2;
                op+=q;
                num1-=(q*num2);
            }
            else{
                int q=num2/num1;
                op+=q;
                num2-=(q*num1);
            }
        }
        return op;
    }
}