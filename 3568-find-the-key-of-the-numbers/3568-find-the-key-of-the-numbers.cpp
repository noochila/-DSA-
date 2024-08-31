class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        // Convert numbers to strings and pad them to 4 digits with leading zeros
        std::string s1 = padToFourDigits(num1);
        std::string s2 = padToFourDigits(num2);
        std::string s3 = padToFourDigits(num3);

        // Generate the key by taking the minimum digit at each position
        std::string key = "";
        for (int i = 0; i < 4; ++i) {
            char minDigit = std::min({s1[i], s2[i], s3[i]});
            key += minDigit;
        }

        // Convert the key string to an integer to remove leading zeros
        return std::stoi(key);
    }

private:
    // Helper function to pad a number to 4 digits with leading zeros
    std::string padToFourDigits(int num) {
        std::string str = std::to_string(num);
        while (str.size() < 4) {
            str = '0' + str;
        }
        return str;
    }

};
