class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string code = "";
        for (auto str: strs) {
            int curr = str.size();
            string len = to_string(curr);
            code += to_string(len.size());
            code += len;
            code += str;
        }
        // cout << code << endl;
        return code;
    }

    vector<string> decode(string s) {
        int i = 0, n = s.size();
        vector<string> res;
        while (i < n) {
            int sizeLen = s[i] - '0';
            i++;
            string temp = s.substr(i, sizeLen);
            i += temp.size();
            int currSize = stoi(temp);
            string str = s.substr(i, currSize);
            res.push_back(str);
            i += currSize;
            // cout << sizeLen << " " << currSize << endl;
            // cout << temp << endl;
        }
        return res;
    }
};
