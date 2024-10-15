class Solution {
public:
using ll = long long;
    struct window
    {
        ll sum = 0,x;
        unordered_map<int,ll> ct;
        set<pair<ll,int>> top_x, rest;
        window(int _x) : x{_x}
        {}

        void remove(int key)
        {
            int prev = ct[key];
            if(top_x.find({prev, key})!= top_x.end())
            {
                sum-=(ll)prev*key;
                top_x.erase({prev,key});
                while(rest.size() > 0 && top_x.size()<x)
                {
                    int count = (*(rest.rbegin())).first, k  = (*(rest.rbegin())).second ;
                    sum+= (ll)count*k;
                    top_x.insert({count,k});
                    rest.erase({count,k});
                }
            }
            else if(rest.find({prev, key})!= rest.end())
            {
                rest.erase({prev,key});
            }


        }
        void add(int key)
        {
            int prev = ct[key];
            top_x.insert({prev, key});
            sum+= (ll) prev*key;

            while(top_x.size() > x)
            {
                int count = (*(top_x.begin())).first, k  = (*(top_x.begin())).second ;
                sum-= (ll)count*k;
                top_x.erase({count,k});
                rest.insert({count,k});
            
            }
        }
        void print()
        {
            for(auto y: top_x)
            {
                cout<<"{"<<y.first<<" "<<y.second<<"},";
            }
            cout<<endl;
            for(auto y: rest)
            {
                cout<<"{"<<y.first<<" "<<y.second<<"},";
            }
            cout<<endl;
            cout<<sum<<endl;
        }
        void increment(int key)
        {
            remove(key);
            ct[key]++;
            add(key);
        }
        void decrement(int key)
        {
            remove(key);
            if(ct[key]==1) ct.erase(key);
            else
            {
                ct[key]--;
                add(key);
            }
        }
    };
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        window w(x);
        for(int i=0;i<k;i++)
        {
            w.increment(nums[i]);
        }
        vector<ll> ans;
        ans.push_back(w.sum);
        // w.print();

        for(int i=k;i<nums.size();i++)
        {
            w.decrement(nums[i-k]);
            w.increment(nums[i]);
            // w.print();
            ans.push_back(w.sum);
        }
        return ans;
    }
};