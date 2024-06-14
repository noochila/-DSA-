class Solution {
public:
    bool isValid(string s) {

      

    stack<char> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(!st.empty()){
          if ((s[i] == ')' && st.top() == '(') ||
              (st.top() == '{' && s[i] == '}') ||
              (st.top() == '[' && s[i] == ']'))
            {st.pop();
            continue;}
            
        }
        st.push(s[i]);
        
    }
    return st.empty();

        
    }
};