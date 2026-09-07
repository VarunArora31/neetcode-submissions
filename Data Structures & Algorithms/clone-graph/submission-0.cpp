/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
     }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<int, Node*> &mp, unordered_set<int> &st) {
        st.insert(node->val);
        for (auto v: node->neighbors) {
            if (mp.count(v->val) == 0) {
                mp[v->val] = new Node(v->val);
            }
            if (!st.count(v->val)) {
                dfs(v, mp, st);
            }
            mp[node->val]->neighbors.push_back(mp[v->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> mp;
        unordered_set<int> vis;
        mp[node->val] = new Node(node->val);
        dfs(node, mp, vis);
        return mp[node->val];
    }
};