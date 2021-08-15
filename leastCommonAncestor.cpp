'''
/*

Find the lowest common ancestor in an unordered binary tree given two values in the tree.

Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

LCA = Lowest common ancestor

Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

*/
'''

CODE

TreeNode *search(TreeNode *A, int x)
{
    if(!A)
    return NULL;
    
    if(A->val == x)
        return A;
    
    TreeNode *lft = search(A->left, x);
    TreeNode *rgt = search(A->right, x);
    
    return (lft) ? lft : rgt;
    
}
 
TreeNode* lowestCommonAncestor(TreeNode* A, TreeNode* p, TreeNode* q) 
{
    if(!A)
        return A;
    
    if(A == p || A == q)
        return A;

    TreeNode *lft, *rgt;
    lft = lowestCommonAncestor(A->left, p, q);
    rgt = lowestCommonAncestor(A->right, p, q);

    if(lft && rgt)
        return A;

    else
        return (lft ? lft : rgt);
}
int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    TreeNode *p = search(A, val1), *q = search(A, val2);
    
    if(!p || !q)
        return -1;
    
    return lowestCommonAncestor(A, p, q)->val;
        
}
