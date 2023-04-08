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
    // node *newGraph;
    map<Node*, Node*>check; 
    queue<Node*>bfs;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL; 
        Node *head = new Node(node->val, {});
        check[node] = head;
        bfs.push(node);
        // //Dfs
        // for(int i = 0; i )
        // newGraph.neighbours.push_back();
        
        //bfs
        while(!bfs.empty()){
            Node* cur = bfs.front();
            bfs.pop();
            for(auto neighbor: cur->neighbors){
                if(check.find(neighbor)==check.end()){
                    check[neighbor] = new Node(neighbor->val, {});
                    bfs.push(neighbor);
                }
                check[cur]->neighbors.push_back(check[neighbor]);
            }
        }
        
        
        return head;
    }
};