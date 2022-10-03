class Solution {
public:
    vector<string> findMissingRanges(vector<int>& v, int lower, int upper) {
        if(v.size()==0)
        {
            if(lower==upper)
                return {to_string(lower)};
            return {to_string(lower)+"->"+to_string(upper)};
        }
        v.push_back(lower);
        v.push_back(upper);
        long long n=v.size();
        long long i=0;long long j=n-1;
        sort(v.begin(),v.end());
        while(v[i]!=lower)
            i++;
        while(v[j]!=upper)
            j--;
        vector<long long> vec;
        for(;i<=j;i++)
            vec.push_back(v[i]);
        vector<string> ans;
        if(vec[1]-vec[0]>1)
                ans.push_back(to_string(lower)+"->"+to_string(vec[1]-1));
        else if(vec[1]-vec[0]==1)
            ans.push_back(to_string(lower));
        for(long long i=1;i<vec.size()-2;i++)
        {
            if(vec[i+1]-vec[i]>2)
                ans.push_back(to_string(vec[i]+1)+"->"+to_string(vec[i+1]-1));
            else if(vec[i+1]-vec[i]==2)
                ans.push_back(to_string(vec[i]+1));
        }
        if(upper-vec[vec.size()-2]>1)
                ans.push_back(to_string(vec[vec.size()-2]+1)+"->"+to_string(upper));
        else if(upper-vec[vec.size()-2]==1)
            ans.push_back(to_string(upper));
        return ans;
    }
};
