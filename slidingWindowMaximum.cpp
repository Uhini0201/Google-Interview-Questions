'''
/*

Given an array of integers A.  There is a sliding window of size B which 

is moving from the very left of the array to the very right. 

You can only see the w numbers in the window. Each time the sliding window moves 

rightwards by one position. You have to find the maximum for each window. 

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	Max
———————————-	————————-
[1  3  -1] -3  5  3  6  7	3
1 [3  -1  -3] 5  3  6  7	3
1  3 [-1  -3  5] 3  6  7	5
1  3  -1 [-3  5  3] 6  7	5
1  3  -1  -3 [5  3  6] 7	6
1  3  -1  -3  5 [3  6  7]	7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]
For Example

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]

*/
'''

CODE


vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int>v;
    deque<int>dq;
    int i;
    //insert the first B elements in the deque
    for(i=0;i<B;i++){
        //check whether the current element is greater than the one present
        //if not we keep removing unless we meet a larger element
        while(!dq.empty() && A[i]>A[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //we push the first element being the largest in the subarray
    v.push_back(A[dq.front()]);
    while(i<A.size()) {
        //we have to put a check whether we are taking the currebt window or not
        if(i-dq.front()>=B)
            dq.pop_front();
        //keep popping unless we meet an element greater element    
        while(!dq.empty() && A[dq.back()]<A[i])
            dq.pop_back();
        dq.push_back(i);
        //keep pushing the front after adding every new element.
        v.push_back(A[dq.front()]);
        i++;
    }
    return v;
}

