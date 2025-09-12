class Solution {
    public boolean isVowel(char ch){
        return (ch=='a' || ch=='e' ||  ch=='i' || ch=='o' || ch=='u');
    }
    public boolean doesAliceWin(String s) {
        int total=0;

        for (int i=0;i<s.length();i++){
            if (isVowel(s.charAt(i))==true) total++;
        }
        if (total%2==0 && total!=0) return true;
        if (total%2==1 && total!=1) return true;
        if (total==1) return true;
        return false;
    }
}