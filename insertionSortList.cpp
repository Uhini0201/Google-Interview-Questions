'''
/*

Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

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

void push(int data,ListNode *v){
    ListNode *slow=v,*fast=v->next;

    while(fast && fast->val<data){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=new ListNode(data);
    slow->next->next=fast;
} 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *sorted=new ListNode(INT_MIN);

    while(A!=NULL){
        push(A->val,sorted);
        A=A->next;
    }
    return sorted->next;
}
