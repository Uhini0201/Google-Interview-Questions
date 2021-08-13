'''
/*

Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

*/
'''


CODE

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeSort(ListNode *left,ListNode *right){
    if(left==NULL)
        return right;
    if(right==NULL)
        return left;
    ListNode *ans=NULL;
    if(left->val<right->val){
        ans=left;
        left=left->next;
    }
    if(right->val<left->val){
        ans=right;
        right=right->next;
    }
    ListNode *f=ans;
    while(left!=NULL && right!=NULL){
        if(left->val<right->val){
            f->next=left;
            left=left->next;
        }
        else{
            f->next=right;
            right=right->next;
        }
        f=f->next;
    }
    if(right){
        f->next=right;
    }
    if(left){
        f->next=left;
    }
    return ans;
}

ListNode* Solution::sortList(ListNode* A) {
    if(A==NULL || A->next==NULL){
        return A;
    }
    ListNode *fast=A->next,*slow=A;
    while(fast && fast->next){
        //start=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    slow->next=NULL;
    ListNode *left=sortList(A);
    ListNode *right=sortList(fast);
    return mergeSort(left,right);
}
