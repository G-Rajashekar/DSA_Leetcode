class Solution {
    public String helper(String str){
        char[] ch=str.toCharArray();
        Arrays.sort(ch);
        return new String(ch);
    }
    public List<String> removeAnagrams(String[] words) {
        List<String>res=new ArrayList<>();
        res.add(words[0]);
        int prev=0;
        int cur=1;

        while(cur<words.length){
            if (!helper(words[prev]).equals(helper(words[cur]))){
                res.add(words[cur]);
                prev=cur;
            }
            cur++;
        }
        return res;
    }
}