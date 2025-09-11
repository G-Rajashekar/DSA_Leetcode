class Solution {
    public boolean isVowel(char c){
        c=Character.toLowerCase(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' );
          
    }
    public String sortVowels(String s) {
        List<Character>vowels=new ArrayList<>();

        for (char c:s.toCharArray()){
            if (isVowel(c)) vowels.add(c);
        }

        Collections.sort(vowels);
        int ind=0;
        StringBuilder result=new StringBuilder();

        for (char c:s.toCharArray()){
            if (isVowel(c)) result.append(vowels.get(ind++));
            else result.append(c);
        }
        return result.toString();
    }
}