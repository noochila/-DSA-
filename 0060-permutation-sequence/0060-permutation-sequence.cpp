class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> number;

        // Calculate (n-1)! and fill the number vector with numbers 1 to n
        for (int i = 1; i < n; i++) {
            fact *= i;
            number.push_back(i);
        }
        number.push_back(n); // Include the number 'n' itself

        string ans = "";
        k = k - 1;

        while (true) {
            ans += to_string(number[k / fact]);
            number.erase(number.begin() + k / fact);

            if (number.size() == 0)
                break;

            k = k % fact;
            fact = fact / number.size();
        }
        return ans;
    }
};
