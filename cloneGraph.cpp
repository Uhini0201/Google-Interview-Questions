'''
/*

Problem Description

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

Note: The test cases are generated in the following format (use the following format to use See Expected Output option):

First integer N is the number of nodes.

Then, N intgers follow denoting the label (or hash) of the N nodes.

Then, N2 integers following denoting the adjacency matrix of a graph, where Adj[i][j] = 1 denotes presence of an undirected edge between the ith and jth node, O otherwise.



Problem Constraints
1 <= Number of nodes <= 105



Input Format
First and only argument is a node A denoting the root of the undirected graph.



Output Format
Return the node denoting the root of the new clone graph.



Example Input
Input 1:

      1
    / | \
   3  2  4
        / \
       5   6
Input 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Output
Output 1:

 Output will the same graph but with new pointers:
      1
    / | \
   3  2  4
        / \
       5   6
Output 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Explanation
Explanation 1:

 We need to return the same graph, but the pointers to the node should be different.

*/
'''

CODE


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*,UndirectedGraphNode*>m;
    queue<UndirectedGraphNode*>q;
    //pushing to the queue the root for bfs traversal
    q.push(node);
    UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
    //the key will be the initial graph and the values will be the clones
    m[node] = root;

    while(!q.empty()){
        UndirectedGraphNode *temp=q.front();
        q.pop();
        //taking its neighbors for the clones adjacency matrix
        vector<UndirectedGraphNode *>v=temp->neighbors;
        for(int i=0;i<v.size();i++){
            //if not created we will create a new and push it
            if(m[v[i]]==NULL){
                UndirectedGraphNode *root=new UndirectedGraphNode(v[i]->label);

                m[v[i]]=root;
                q.push(v[i]);
            }
            //then push its neighbors
            m[temp]->neighbors.push_back(m[v[i]]);
        }
    }
    //return root
    return m[node];
}

