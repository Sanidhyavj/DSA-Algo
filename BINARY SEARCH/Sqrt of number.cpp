class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
         long long int l = 1;
         long long int r = x;
         long long int ans = 0;
         while(l<=r)
         {
             long long int mid = l + (r-l)/2;
             
             if(mid*mid <= x)
             l = mid+1;
             else
             r = mid-1;
         }
         return r;
    }
};
