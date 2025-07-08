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
    unordered_map<Node*,Node*>mp;
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        return dfs(node);
    }

    Node *dfs(Node *node){
        Node* copy=new Node(node->val);
        mp[node]=copy;
        for (auto nei:node->neighbors){
            if (mp.find(nei)!=mp.end()) copy->neighbors.push_back(mp[nei]);
            else copy->neighbors.push_back(dfs(nei));
        }

        return copy;
    }
};