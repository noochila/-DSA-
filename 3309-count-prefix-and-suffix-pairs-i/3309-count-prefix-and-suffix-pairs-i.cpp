class Solution {
public:
    
 #include <string>

bool check(const std::string& a, const std::string& b) {
    // Handle empty strings gracefully
    if (a.empty() || b.empty()) {
        return false;
    }

    // Use std::equal for efficient substring comparison
    size_t a_len = a.size();

    bool is_beginning_substring = std::equal(b.begin(), b.begin() + a_len, a.begin());
    bool is_ending_substring = std::equal(b.end() - a_len, b.end(), a.begin());

    return is_beginning_substring && is_ending_substring;
}

    int countPrefixSuffixPairs(vector<string>& words) {
        
        
        int n=words.size();
        int count=0;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(words[i],words[j]))
                    count++;
            }
        }
        
        return count;
    }
};