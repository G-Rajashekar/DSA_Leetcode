class Solution {
    public boolean isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    public int maxFreqSum(String s) {
        int[] freq=new int[26];

        for (char ch:s.toCharArray()) freq[ch-'a']++;

        //String vowels="aeiou";

        int maxVowel=0;
        int maxCons=0;

        for (int i=0;i<26;i++){
            char ch=(char)(i+'a');
            if (isVowel(ch)){
                maxVowel=Math.max(maxVowel,freq[i]);
            }
            else{
                maxCons=Math.max(maxCons,freq[i]);
            }
        }
        return maxVowel+maxCons;
    }
}