class Solution {
  public:

    bool isValid(string s) {

        int cnt = 0;

        for(char c : s) {

            if(c == '(')
                cnt++;

            else if(c == ')') {

                cnt--;

                if(cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }

    vector<string> validParenthesis(string &s) {

        vector<string> res;

        unordered_set<string> vis;
        unordered_set<string> validSet;

        queue<string> q;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                string cur = q.front();
                q.pop();

                if(isValid(cur)) {

                    if(!validSet.count(cur)) {
                        res.push_back(cur);
                        validSet.insert(cur);
                    }

                    found = true;
                }

                if(found)
                    continue;

                for(int i = 0; i < cur.size(); i++) {

                    if(cur[i] != '(' && cur[i] != ')')
                        continue;

                    string nxt =
                        cur.substr(0, i) +
                        cur.substr(i + 1);

                    if(!vis.count(nxt)) {

                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }

            if(found)
                break;
        }

        if(res.empty())
            return {""};

        return res;
    }
};