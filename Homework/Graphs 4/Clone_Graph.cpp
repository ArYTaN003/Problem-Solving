class Solution {
    Node* helper(Node* node,unordered_map<Node*,Node*>& mp){
        if(mp.find(node)!=mp.end()) return mp[node];
        mp[node] = new Node(node->val);
        for(Node* u:node->neighbors){
            mp[node]->neighbors.push_back(helper(u,mp));
        }
        return mp[node];
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> mp;
        
        return helper(node,mp);
    }
};