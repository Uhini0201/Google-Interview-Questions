'''
/*

Problem Description

Given an arbitrary unweighted rooted tree which consists of N nodes.

The goal of the problem is to find largest distance between two nodes in a tree.

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



Problem Constraints
1 <= N <= 40000



Input Format
First and only argument is an integer array A of size N.



Output Format
Return a single integer denoting the largest distance between two nodes in a tree.



Example Input
Input 1:

 A = [-1, 0, 0, 0, 3]


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4

 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.



*/
'''

CODE

int build_tree(const vector<int> &parents, vector<vector<int>> &tree) {
    int n = parents.size();
    tree.clear();
    tree.resize(n, vector<int>());
    int root_node = 0;

    for (int node = 0; node < n; node++) {
        if (parents[node] == -1) {
            root_node = node;
            continue;
        }

        tree[node].push_back(parents[node]);
        tree[parents[node]].push_back(node);
    }

    return root_node;
}

int bfs(const vector<vector<int>> &tree, int start, int &end) {
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    int cur_level = 0;
    int cur_node = start;
    q.push({cur_node, cur_level});
    while (!q.empty()) {
        cur_node = q.front().first;
        visited.insert(cur_node);
        cur_level = q.front().second;
        q.pop();

        for (auto neighbour : tree[cur_node]) {
            if (visited.count(neighbour) == 0) {
                q.push({neighbour, cur_level + 1});
            }
        }
    }

    end = cur_node;
    return cur_level;
}

// Time - O(N), Space - O(N)
int Solution::solve(vector<int> &A) {
    vector<int> &parents = A;

    vector<vector<int>> tree;
    //to build the adjacency list
    int root = build_tree(parents, tree);
    int path_start, path_end;
    //to find out the starteding node which will pass through the root
    bfs(tree, root, path_start);
    //to find out the max distance between two nodes
    int max_distance = bfs(tree, path_start, path_end);

    return max_distance;
}
