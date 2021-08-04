'''
  Given an array of integers A of size N and an integer B.

College library has N bags,the ith book has A[i] number of pages.

You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return that minimum possible number
Constraints

1 <= N <= 10^5
1 <= A[i] <= 10^5
For Example

Input 1:
    A = [12, 34, 67, 90]
    B = 2
Output 1:
    113
Explanation 1:
    There are 2 number of students. Books can be distributed in following fashion : 
        1) [12] and [34, 67, 90]
        Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
        2) [12, 34] and [67, 90]
        Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
        3) [12, 34, 67] and [90]
        Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

        Of the 3 cases, Option 3 has the minimum pages = 113.

Input 2:
    A = [5, 17, 100, 11]
    B = 4
Output 2:
    100
  
 '''
      
      
 # Code
      
      bool found(vector<int>v,int val,int sum){
    int s=0,book=1;
    for(int i=0;i<v.size();i++){
        //if the current book is greater than the threshold, we have to move to the right
        if(v[i]>sum){
            return false;
        }
        // students required to distribute the current pages
        if(s+v[i]>sum){
            book+=1;
            s=v[i];
            //if students/books added is more than the given students
            if(book>val){
                return false;
            }
        }
        //update the current sum
        else{
            s+=v[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if(B>A.size()){
        return -1;
    }
    int sum=0,mini=999999;
    //binary search on the number of pages to find the minimum
    for(int i=0;i<A.size();i++){
        sum+=A[i];
    }
    int l=0,r=sum;
    while(l<=r){
        int mid=l+(r-l)/2;
        //since we are finding the minimum, we will take the
        //mid as the threshold and check to its left, if true
        //we will move to left
        if(found(A,B,mid)){
            mini=mid;
            r=mid-1;
        }
        //if more than the threshold we will move to the right
        else{
            l=mid+1;
        }
    }
    //return the minimum the number of pages
    return mini;
}
