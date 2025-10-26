class Bank {
    long[] b;
    public Bank(long[] balance) {
        b=balance;
    }
    
    public boolean validate(int account){
        return account>=1 && account<=b.length;
    }
    public boolean transfer(int account1, int account2, long money) {
        if (!validate(account1) || !validate(account2)) return false;
         account1-=1;
         account2-=1;

         if (b[account1]>=money){
            b[account1]-=money;
            b[account2]+=money;
            return true;
         }
         return false;
    }
    
    public boolean deposit(int account, long money) {
        if (!validate(account)) return false;
         account-=1;
         b[account]+=money;
         return true;
    }
    
    public boolean withdraw(int account, long money) {

        if (!validate(account)) return false;
        account-=1;
        if (b[account]>=money){
            b[account]-=money;
            return true;
        }
        return false;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */