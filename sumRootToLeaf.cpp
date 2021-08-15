'''
/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.

The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

*/
'''


CODE

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find(TreeNode *root,int z){
    z=(z*10+root->val)%1003;

    if(root->left==NULL && root->right==NULL){
        return z;
    }
    int l1=0,l2=0;
    if(root->left){
        l1=find(root->left,z);
    }
    if(root->right){
        l2=find(root->right,z);
    }
    return l1+l2;

    
}
int Solution::sumNumbers(TreeNode* A) {
    return find(A,0)%1003;
}
