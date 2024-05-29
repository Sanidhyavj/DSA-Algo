 void sub(int ind,vector<int> &arr,int n,vector<int> &v,int sum)
    {
        if(ind==n)
        {
            v.push_back(sum);
            return;
        }
        
        sub(ind+1,arr,n,v,sum+arr[ind]);
        sub(ind+1,arr,n,v,sum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> v;
        sub(0,arr,n,v,0);
        return v;
    }
