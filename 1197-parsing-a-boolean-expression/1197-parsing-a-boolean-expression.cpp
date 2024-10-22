class Solution {
public:
    char solve(vector<char> temp, char chr) {
        if (chr == '!') {
            return (temp[0] == 'f') ? 't' : 'f';
        }

        if (chr == '|') {
            for (auto it : temp)
                if (it == 't')
                    return 't';
            return 'f';
        }

        if (chr == '&') {
            for (auto it : temp)
                if (it == 'f')
                    return 'f';
            return 't';
        }
        
        return ' ';
    }

    bool parseBoolExpr(string exp) {
        stack<char> s;
        for (char it : exp) {
            if (it == ',')
                continue;

            if (it == ')') {
                vector<char> temp;
                while (!s.empty() && s.top() != '(') {
                    temp.push_back(s.top());
                    s.pop();
                }
                
                // Pop the opening parenthesis '('
                if (!s.empty()) s.pop();

                // Get the operator before '('
                if (!s.empty()) {
                    char ch = s.top();
                    s.pop();
                    char val = solve(temp, ch);
                    s.push(val);
                }
            } else {
                // Push characters to the stack
                s.push(it);
            }
        }

        return s.top() == 't';
    }
};
