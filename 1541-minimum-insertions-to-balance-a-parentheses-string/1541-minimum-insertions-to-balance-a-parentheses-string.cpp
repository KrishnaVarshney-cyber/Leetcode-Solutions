class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(i<s.size()-1 && s[i+1]==')'){
                    if(st.empty()){
                        ans++;
                    }
                    else{
                        st.pop();
                    }
                    i++;
                }

                else{
                    if(st.empty()){
                        ans += 2;
                    }
                    else{
                        st.pop();
                        ans++;
                    }
                }
            }
        }

        while(!st.empty()){
            ans+=2;
            st.pop();
        }

        return ans;
    }
};