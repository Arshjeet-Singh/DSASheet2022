class Solution {
    private:
    	int findKRotation(vector<int>& arr, int n) {
	    int start=0;
	    int end=n-1;
	    if(arr[start]<=arr[end])
	    {
	        return 0;
	    }
	    while(start<=end)
	    {
	        int mid=start+(end-start)/2;
	        int next=(mid+1)%n;
	        int prev=(mid-1+n)%n;
	        if(arr[mid]<=arr[prev]&& arr[mid]<=arr[next])
	        {
	            return mid;
	        }
	        else if(arr[mid]<=arr[end])
	        {
	            end=mid-1;
	        }
	        else if(arr[start]<=arr[mid])
	        {
	            start=mid+1;
	        }
	    }
            return -1;
	    // code here
	}

public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int k=findKRotation(nums,n);
//         for bs1
        int s=0,e=k-1,ind=-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]==target)
            {
                ind=m;
                break;
            }
            else if(nums[m]<target)
            {
                s=m+1;
            }
            else
            {
                e=m-1;
            }
        }
        if(ind!=-1)
        {
            return ind;
        }
        s=k,e=n-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(nums[m]==target)
            {
                ind=m;
                break;
            }
            else if(nums[m]<target)
            {
                s=m+1;
            }
            else
            {
                e=m-1;
            }
        }
        // if(ind!=-1)
        // {
        //     ind=ind+k;
        // }
        return ind;
    }
};
