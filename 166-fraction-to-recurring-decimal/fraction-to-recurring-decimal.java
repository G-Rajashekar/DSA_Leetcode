class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        StringBuilder sb=new StringBuilder();
        long num=Math.abs((long)numerator);
        long d=Math.abs((long)denominator);
        if ((numerator < 0) ^ (denominator < 0)) sb.append("-");
        sb.append(num/d);
        num=num%d;
        if(num==0) return sb.toString();
        sb.append(".");
        HashMap<Long,Integer>map=new HashMap<>();
        while(num!=0){
            if(map.containsKey(num)){
                int index = map.get(num);
                sb.insert(index, '(');                
                sb.append(')');
                break;
            }
            map.put(num, sb.length());
            num *= 10;
            sb.append(num / d);
            num %= d;
        }
        return sb.toString();
    }
}