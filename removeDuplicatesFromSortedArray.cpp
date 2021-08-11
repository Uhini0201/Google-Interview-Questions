'''
/*
Problem Description

Given a sorted array A consisting of duplicate elements.

 Your task is to remove all the duplicates and return a sorted array of distinct elements consisting of all distinct elements
present in A.

NOTE: The input format has been changed from previous versions.



Input Format
First and only argurment containing the integer array A.



Output Format
Return an array/vector from the function as per the question.



Example Input
Input 1:

A = [1, 1, 2]
Input 2:

A = [1, 2, 2, 3, 3]


Example Output
Output 1:

[1, 2]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

Updated Array: [1, 2] after removing the 2nd element.
Explanation 2:

Updated Array: [1, 2, 3] after removing the 3rd and 5th element.

*/
'''

CODE

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
   if(n==0 || n==1) return n;
   int j = 0;
   for(int i=0;i<n-1;i++){
       if(A[i]!=A[i+1]){
           A[j++] = A[i];
       }
   }
   A[j++] = A[n-1];
   return j;
}
