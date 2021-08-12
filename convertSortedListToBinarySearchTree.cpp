'''
/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3


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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int count(ListNode *a){
    ListNode *temp=a;int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

TreeNode* bst(ListNode **a,int n){
    if(n<=0){
        return NULL;
    }
    TreeNode *left=bst(a,n/2);
    TreeNode* head = new TreeNode((*a)->val);
    head->left = left;

    (*a)=(*a)->next;
    head->right=bst(a,n-n/2-1);
    return head;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=count(A);
    return bst(&A,n);
}
