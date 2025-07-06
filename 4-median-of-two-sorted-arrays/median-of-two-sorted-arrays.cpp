class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int ind1=n/2-1;
        int ind2=n/2;

        int ele1=-1;
        int ele2=-1;

        int i=0;
        int j=0;
        int cnt=0;
        while(i<n1 && j<n2){
            if (nums1[i]<=nums2[j]){
                if (cnt==ind1) ele1=nums1[i];
                if (cnt==ind2) ele2=nums1[i];
                i++;
            }
            else {
                 if (cnt==ind1) ele1=nums2[j];
                if (cnt==ind2) ele2=nums2[j];
                j++;
            }
            cnt++;
        }

        while(i<n1){
            if (cnt==ind1) ele1=nums1[i];
            if (cnt==ind2) ele2=nums1[i];
            i++;
            cnt++;
        }

         while(j<n2){
             if (cnt==ind1) ele1=nums2[j];
            if (cnt==ind2) ele2=nums2[j];
                j++;
            cnt++;
        }
        
        if (n%2==0) return (double)(ele1+ele2)/2;
        return double(ele2);
           
    }
};