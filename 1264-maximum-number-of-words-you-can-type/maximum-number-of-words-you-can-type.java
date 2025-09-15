class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        int cnt=0;

        String[] words=text.split("\\s+");

        for (String word:words){
            boolean flag=true;
            for (int i=0;i<brokenLetters.length();i++){
                char ch=brokenLetters.charAt(i);

                if (word.contains(String.valueOf(ch))){
                    flag=false;
                    break;
                }
            }

            if (flag==true) cnt++;
        }
        return cnt;
    }
}