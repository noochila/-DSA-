class Solution {
public:
    int minLength(string s) {

        // while (true) {
        //     if (s.find("AB") != string::npos) {
        //         s.erase(s.find("AB"), 2);
        //     }

        //     if (s.find("CD") != string::npos) {
        //         s.erase(s.find("CD"), 2);
        //     }

        

        //     if (s.find("AB") == string::npos && s.find("CD") == string::npos )
        //         break;
        // }

        // return s.size();


        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
             char ch=s[i];

             if(st.empty())
             {
                st.push(ch);
                continue;
             }

             if(!st.empty()  &&  st.top()=='A' && s[i]=='B')
             {
                st.pop();
             }

            else if(!st.empty() && st.top()=='C' && s[i]=='D')
             st.pop();
             else
             st.push(ch);


        }

        return st.size();
    }
};