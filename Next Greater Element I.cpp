class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //optimised soln
        vector<int> v;
        stack<int> s;
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++)
        {
            while(s.size() && s.top()<nums2[i])
            {
                mp[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(mp[nums1[i]]>0)
            {
                v.push_back(mp[nums1[i]]);
            }
            else
            {
                v.push_back(-1);
            }
        }
        return v;
        // stack<int> s1,s2;
        // vector<int> v;
        // for(int i=0;i<nums2.size();i++)
        // {
        //     s1.push(nums2[i]);
        // }
        // int top=-1;
        // stack<int> s3;
        // for(int i=0;i<nums1.size();i++)
        // {
        //     s3=s1;
        //    while(!s2.empty())
        //    {
        //        s2.pop();
        //    }
        //     while(!s1.empty() && s1.top()!=nums1[i])
        //     {
        //         s2.push(s1.top());
        //         s1.pop();
        //     }
        //     int f=0;
        //     while(!s2.empty())
        //     {
        //         if(s2.top()>nums1[i])
        //         {
        //             // cout<<s2.top()<<endl;
        //             f=1;
        //             v.push_back(s2.top());
        //             break;
        //         }
        //         else
        //         {
        //             s2.pop();
        //         }
        //     }
        //     if(f==0)
        //     {
        //         v.push_back(-1);
        //     }
        //     s1=s3;
        // }
        // return v;
    }
};
