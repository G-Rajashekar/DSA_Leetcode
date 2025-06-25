#define ll long long
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll low=-1e10;
        ll high=1e10;
        ll ans=-1;
        while(low<=high){
            ll mid=(low+high)/2;

            ll cnt=helper(nums1,nums2,k,mid);
           
           if (cnt>=k) {
               ans=mid;
               high=mid-1;
           }
           else{
            low=mid+1;
           }
        }

        return ans;
    }

    ll helper(vector<int>&nums1,vector<int>&nums2,int k,ll m){

        ll cnt=0;

        for (auto x:nums1){
            if (x==0){
                if (m>=0) cnt+=nums2.size();
            }
            else if(x>0){
                cnt+=findPosCnt(nums2,x,m);
            }
            else{
                cnt+=findNegCnt(nums2,x,m);
            }
        }
        return cnt;
    }

    ll findPosCnt(vector<int>&nums,ll x,ll m){
        ll low=0;
        ll high=nums.size()-1;
        ll ans=-1;

        while(low<=high){
            ll mid=(low+high)/2;

            if (x*nums[mid]<=m){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans+1;
    }


    ll findNegCnt(vector<int>&nums,ll x,ll m){
          int n = nums.size();
        ll l = -1, r = n;
        while(l+1<r){
            ll j = (l+r)/2;
            if(x*nums[j] > m){
                l = j;
            }
            else{
                r = j;
            }
        }
        return n-r;
    }
};