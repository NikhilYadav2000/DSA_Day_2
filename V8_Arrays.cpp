#include <bits/stdc++.h>
using namespace std;
int largestValueInAnArray(vector<int> &vec, int n)
{
    int largest = vec[0]; // as we know one of the elements of the array has to be the largest so, take any one of it and just traverse the entire array comparing
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > largest)
            largest = vec[i];
    }
    return largest;
}

int secondLargestValueInAnArrayBetter(vector<int> &vec, int n)
{
    int l1 = vec[0];
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > l1)
            l1 = vec[i];
    }
    int l2 = vec[0];
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > l2 && vec[i] != l1)
            l2 = vec[i];
    }
    return l2;
}
int secondLargestValueInAnArrayOptimal(vector<int> vec, int n)
{
    // will make largest=arr[0] and secondLargest=INT_MIN(-1 if the numbers are not negative),
    // We will Traverse the Array and if arr[i]>largest then secondLargest=largest and largest=arr[i].
    // The intutition
    // Largest  = 1;
    // secondLargest = INT_MIN;
    // arr[i] = 2;
    // secondLargest = 1 ;
    // Largest = 2; / The largest becomes the second largest if it finds any element greater then it.
    int largest = vec[0], secondLargest = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (vec[i] > largest)
        {
            secondLargest = largest;
            largest = vec[i];
        }
        else if (vec[i] < largest && vec[i] > secondLargest)
        {
            secondLargest = vec[i];
        }
        // we have ton do this for
        // [1,2,4,7,7,5], till 7 it will be good as
        // largest = 7
        // secondLargest = 5,
        // But as it goes ahead vec[i]= 5 but it si not greater then largest=7 so will have an else if that says that if
        // vec[i]<largest &&  vec[i]>secondLargest
        // secondLargest=vec[i];
    }
    return secondLargest;
}

int secondSmallestValueInAnArrayOptimal(vector<int> &arr, int n)
{
    int smallest = arr[0], secondSmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
        // smallest=1;
        // secondSmallest=INT_MAX;
        // Traversing,
        //  if(arr[i]<smallest)
        //  2!<1 so wont go inside and so on
        //  else if(arr[i]!=smallest && arr[i]<secondSmallest)
        // 3 1 2
        // smallest = 1;
        // second smallest = 3;
        // we know that 2 is the ss but as it is greater then 1 it wont go inside the first if
        // so else if : 2!=1 && s<ss; ss=arr[i];
    }
    return secondSmallest;
}

bool checkIfTheArrayIsSorted(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}

// use Set as it only stores unique elements
int removeDupicatesBrute(vector<int> &arr, int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    { // vec ={1,1,2,2,2,3,3}
        st.insert(arr[i]);
    } // inserting all the values of array inside st = {1,2,3}

    // as we have to return the index
    int ind = 0;
    for (auto it : st)
    {
        arr[ind++] = it; // arr[0] = 1, arr[1]=2,arr[2]=3 and as it is going
        //  ind++ ind value at this point will be 3, it is the index number and as we are following 0 based indexing it will be the size of the array.
    }
    return ind;
    // 1.  insertion in set takes O(nlogn)
    // 2.  for inserting it again in the array it will be O(n)
    // TC =  O(n+nlogn)
    // SC = O(n), as we are taking a set data  structure and it might take n values
}

// Focus on, we have given a sorted array
int removeDuplicatesOptimal(vector<int> &arr, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j]; // we are just putting the value of RHS to LHS
            i++;
        }
    }
    return i + 1; // TC = O(n), SC = O(1)
    // Before : {1,1,2,2,2,3,3,};
    // i = 0th index, j=1st index
    // i = 0th index, j=2nd index
    // as they are different putting 2nd index value in i+1(1st index) and then i++ so that i is poiting to 1st index now
    // After : {1,2,2,2,2,3,3};
    // i = 1st index, j=2nd index
}
void leftRotateTheArrayBy1Place(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
} // TC = O(n), SC = O(1)
// So basically we are just putting the value of the 0th index inside the temp variable and traversing inside the array and putting arr[i-1]=arr[i] and at last position we are putting the value stored in the temp
// {1,2,3,4,5}
// temp = 1
// arr[0]=arr[1]...arr[3]=arr[4]
// arr[n-1]=temp

void moveZeroesToTheEndBrute(vector<int> &arr, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    { // size is n so O(n)
        if (arr[i] != 0)
            temp.push_back(arr[i]);
    }
    for (int i = 0; i < temp.size(); i++)
    { // size is x so O(x)
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < n; i++)
    { // size is n-x so O(n-x)
        arr[i] = 0;
    }
    // Total TC = O(n+x+n-x) => O(2n),
    // SC = O(x) i.e. the size of the temp array having 0s,
    // O(n) i.e. size of the temp array with no 0s(we copied the entire array into the temp array)
}
void leftRotateTheArrayByDPlaceBrute(vector<int> &arr, int n, int d)
{
    // checking how many rotation we have to do
    // if d = n then 0 rotation
    // if d = n+1 then only 1 rotaton
    // So,
    d = d % n;
    vector<int> temp;
    for (int i = 0; i < d; i++)
    {                           // O(d)
        temp.push_back(arr[i]); // pushing back the value of the main array into a temp array, till the part we have to rotate
    }
    for (int i = d; i < n; i++)
    {                        // O(n-d)
        arr[i - d] = arr[i]; // i-d => arr[d-d = 0]=arr[d = 3],
        // arr[d+1-d = 1]=arr[d+1 = 4];
    }
    // just remember this if u want to push the value from a point and also want it to increment with every loop just start from that point i=d, and if u want to convert the front number i-d=>d-d=>0, in the next loop it will become d+1-d=>1

    // int j=0;
    for (int i = n - d; i < n; i++)
    { // O(d)
        // arr[i]=temp[j];
        // j++; // lets start traversing temp from j=0 and
        // j++ then, and putting the value inside arr after n-d

        // before rotating if we observe that as we know that the 0th value will go in the n-d place and the 1st value will go in the n-d+1 place so
        arr[i] = temp[i - (n - d)];
    }
} // TC = O(d+n-d+d) => O(n+d), SC=O(d) for the temp array

/*
// Reverse Function
void Reverse(vector<int> arr, int s, int e){
    while(i<=j){
        int temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
        s++; e--;
    }
}
*/
void leftRotateTheArrayByDPlaceOptimal(vector<int> &arr, int n, int d)
{
    // reverse upto d
    reverse(arr.begin(), arr.begin() + d); // O(d)
    // reverse from n-d to d
    reverse(arr.begin() + d, arr.end()); // O(n-d)
    // reverse from 0 to n
    reverse(arr.begin(), arr.end()); // O(n)
} // TC = O(n+n-d+d) => O(2n), SC=O(1)

vector<int> moveZeroesToTheEndOptimal(vector<int> &arr, int n)
{
    // we will be doing to things, firstly will be checking if there arer any zeroes in the array and also it there are 0s then putting j on the index where 0 appears for the first time
    int j = -1;
    for (int i = 0; i < n; i++)
    { // O(x), where the first 0 was found
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return arr;
    for (int i = j + 1; i < n; i++)
    { // O(n-x)
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++; // as we are moving along with the 0, j will always have that 0 value
        }
    }
    return arr;
    // {1,0,2,3,2,0,0,4,5,1}
    // j=1st ind
    // i=2nd index
    // swap, j++, i++
    // {1,2,0,3,2,0,0,4,5,1}
    // j=2nd ind
    // i=3rd index
    // TC = O(x+n-x)=>O(n), SC = O(1)
}

vector<int> UnionOfTwoSortedArraysBrute(vector<int> &vec1, vector<int> &vec2, int n1, int n2) // use set only not unordered_set as it will desrupt the sortedness
{
    // set<int> s(vec1.begin(),vec1.end()); // on of the ways to insert inside set while declaring
    set<int> st;
    for (int i = 0; i < n1; i++)
    {
        st.insert(vec1[i]); // O(n1logn), n is the size of the set, as there are unique values the size of the set(n) will not be equal to size of the
        //  arr O(n1)
    }
    for (int i = 0; i < n2; i++)
    {
        st.insert(vec2[i]); // O(n2logn)
    }
    vector<int> res(st.begin(), st.end()); // O(n1+n2) if elements inside both the arrays were all unique.
    return res;

    // for(auto it : st) union[i++]=it; or union.push_back(it);

    // TC = O(n1logn + n2logn) + O(n1+n2)
    // SC = O(n1+n2)(set is every element is unique) +  O(n1+n2)(res array used for returning not for solving the problem)
}

vector<int> UnionOfTwoSortedArraysOptimal(vector<int> &vec1, vector<int> &vec2, int n1, int n2)
{
    // Focus on the Sorted Array Part
    // Two Pointer Approach
    vector<int> res;
    int i = 0, j = 0;
    while (i < n1 && j < n2) // traversing till array ends
    {
        if (vec1[i] < vec2[j]) // will oush the value of the smaller element as we have to make it a sorted array
        {
            if (res.size() == 0 || res.back() != vec1[i]) // if it is the first value(res.size()==0) or the last value is not the same as the incoming value
            {
                res.push_back(vec1[i]);
            }
            i++;
        }
        else
        {
            if (res.size() == 0 || res.back() != vec2[j])
            {
                res.push_back(vec2[j]);
            }
            j++;
        }
    }
    while (i < n1) // if one of the array ends the other has to check for the same thing and push inside the res
    {
        if (res.size() == 0 || res.back() != vec1[i])
        {
            res.push_back(vec1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (res.size() == 0 || res.back() != vec2[j])
        {
            res.push_back(vec2[j]);
        }
        j++;
    }
    return res;

    // TC =  O(n1+n2) as we are traversing through every element in both the array
    // SC = O(n1+n2), just for returning the array not using it for solving, not in my algorithm
}

vector<int> insertionOfTwoSortedArrayBrute(vector<int> &vec1, vector<int> &vec2, int n1, int n2)
{
    vector<int> res;
    int vis[n2] = {0}; // as we are comparing n1 with elements of n2 we are taking a visited array of the size n2
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (vec1[i] == vec2[j] && vis[j] == 0)
            {
                res.push_back(vec1[i]);
                vis[j] = 1;
                break;
            } // After the loop breaks j++ and i++ will happen
            if (vec1[i] < vec2[j])
                break;
        }
    }
    return res;
} // TC = O(n1*n2) for the worst case, SC = O(n2)(visited array)

// 0th loop for i and j start starts 1!=2 and 1<2 so the loop breaks
// 1st loop for i starts and j starts from the 0th loop and comapres everything from 0th till the time vec1[i]<vec2[j]

vector<int> insertionOfTwoSortedArrayOptimal(vector<int> &vec1, vector<int> &vec2, int n1, int n2)
{
    // Focus on the Sorted Array term
    // two pointer approach again
    int i = 0, j = 0;
    vector<int> res;
    while (i < n1 && j < n2)
    {
        if (vec1[i] < vec2[j])
            i++;
        if (vec1[i] > vec2[j])
            j++;
        else
            res.push_back(vec1[i]);
        i++;
        j++;
    }
    return res;
}
// and here also if one of the array ends and the other is left as there is no one to partner with(no intersection) no point adding them.
// TC = O(n1+n2) in the worst case, SC=O(n1+n2) for returning the answer else it is O(1)

int MissingNumberOptimal_1(vector<int> &arr,int size,int n){
    // Numbers are given from 1 to N(keep this in mind)
    int sum1=n*(n+1)/2;
    int sum2=0;
    for(int i=0;i<size;i++){ 
        sum2+=arr[i];
    }
    return sum1-sum2;
} // TC = O(n), SC = O(1)

// we use XOR bcoz the value if it is given 10^5 will become 10^10 and we have to use long long which is good but to avoid it we use bitwise XOR operator
int MissingNumberOptimal_2(vector<int> &arr,int size,int n){
    // Numbers are given from 1 to N(keep this in mind)
    // a^a=0, a^0=a
    // int xor1=0;
    // for(int i=1;i<=n;i++){
    //     xor1^=i;
    // }
    // int xor2=0;
    // for(int i=0;i<size;i++){
    //     // xor2^=arr[i];
    // }
    // return xor1^xor2;

    int resXor=0;
    // cout<<n<<endl; // 5 
    for(int i=0;i<size;i++){
        // cout<<i+1<<" "<<arr[i]<<" "; 1 1 2 2 3 4 4 5
        resXor^=arr[i]^(i+1); // focus on resXor ^=, earlier you were just using = and it was assigning the value to it instead of xoring it
        // (0)^(1^1)^(2^2)^(4^3)^(5^4)=>3^5;
        // cout<<resXor<<" ";
    }
    return resXor^n; // (3^5^5)=>3
}

int MaximumConsecutiveOnes(vector<int> &arr,int n){
    int res=0,curr=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
           curr+=1; 
           res=max(res,curr);
        } 
        else curr=0;
    } return res;
} // TC = O(n), SC = O(1)

int findNumberThatAppearsOnesBetter(vector<int> &arr,int n){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++; // nlogm (n=size of the array, m=size of the map)
    }
    // unordered_map<int,int> mp; // O(n) at the best case, O(n^2) at the worst case
    // for(int i=0;i<n;i++){
    //     mp[arr[i]]++; 
    // }   
    // for(int i=0;i<n;i++){ 
    //     if(mp[arr[i]]==1){
    //         return arr[i];
    //     }
    // }
    for(auto it:mp){ // O(n/2+1) , for the worst case
        if(it.second==1){
            return it.first;
        }
    }
    // map will only store n/2+1(it n=7 then n/2=3+1 =>4) values as all the number appears twice, we know that 5 appears ony ones but it will have its place own place
    // [1=>2, 2=>2, 3=>2, 4=>2, 5=>1]
} 
// TC = nlogm here m=n/2+1 so, TC=>nlog(n/2+1)+n/2+1 for using normal map, we can use unordered map
// SC = O(n/2+1) for map 

int findNumberThatAppearsOnesOptimal(vector<int> &arr,int n){
    int resXor=0;
    for(auto it:arr) resXor^=it;
    return resXor;
} // TC=O(n), SC=O(1)

/*
Subarray means a contiguous part of the array.
Subsequence means a sequence that appears in the same relative order, but not necessarily contiguous.
The Brute Force Approach will be easy just point i and j both
 to arr[i] and have two loops and generate all the subarrays

for(int i =0;i<n;i++){
    for(int j=i;j<n;j++){
        for(int k=i;k<j;k++){
            s+=a[k]
            if(s==k) len=max(len, j-i+1) // {1,2,3,1,1,1}
            // if j=3rd index(value=1) and j=5th index(val=1)
            // sum=3 so the length will be l-i(5-3=2) + 1=>3
        }
    }
} O(n^3)

// as we are moving ahead we are just adding the value of j to the sum so instead of using a 3rd loop just add j to it
for(int i =0;i<n;i++){
    for(int j=i;j<n;j++){
            s+=arr[j];
            if(s==k) len=max(len, j-i+1) // {1,2,3,1,1,1}
            // if j=3rd index(value=1) and j=5th index(val=1)
            // sum=3 so the length will be l-i(5-3=2) + 1=>3
    }
} O(n^2)

// Better
[_ _ _ _ _ _]
<----x---->
<-k->
    <-x-k->
if the sum of the subarray till 4th pos is x
we have to find sum of the elements k =7
if we iterate till x and we found that there is a value which is equal to x-k then the left portion will have a sum of k 
We found the subarray
Use Hashmap

{1,2,3,1,1,1,1,4,2,3}
<----------> 9
<----> 6
     <-----> 3
preSum=0
len=0

8,4
7,3
6,2
3,1
1,0

// This will work only if 0s are not present
*/

// This is for the Positives and 0s 
int longestSubarrayWithSumK(vector<int> &arr,int n,int k){
    // Using 2 pointer approach
    // Both pointers will be pointing to 0th index initially and when the sum goes beyond the k value given we will trim from the left
    int l=0,r=0;
    long long sum=arr[0];
    int maxLen=0;
    while(r<n){ // O(n) as it running from 0 to n
        while(l<=r && sum>k){ // O(n) as it not always running from o to n(it might run for 0(there might be multiple zeroes initially) ones or twice or thrice ).
            sum-=arr[l];
            l++;
        }
        if(sum==k) maxLen=max(maxLen,r-l+1);
        r++;
        sum+=arr[r];
    }return maxLen;
} // TC =O(2n), SC=O(1)
int main()
{
    cout << "Largest Element in an Array : " << endl;
    vector<int> vec1 = {3, 2, 1, 5, 2};
    int n1 = vec1.size();
    cout << largestValueInAnArray(vec1, n1); // 5

    cout << endl
         << "Second Largest Element in an Array Better : " << endl;
    vector<int> vec2 = {1, 2, 4, 7, 7, 5};
    int n2 = vec2.size();
    cout << secondLargestValueInAnArrayBetter(vec2, n2); // 5

    cout << endl
         << "Second Largest Element in an Array Optimal : " << endl;
    cout << secondLargestValueInAnArrayOptimal(vec2, n2); // 5

    cout << endl
         << "Second Smallest Element in an Array Optimal : " << endl;
    cout << secondSmallestValueInAnArrayOptimal(vec2, n2); // 2

    vector<int> vec3 = {1, 2, 2, 3, 3, 4};
    // vector<int> vec3={1,2,1,3,4};
    int n3 = vec3.size();
    cout << endl
         << "Check if the Array is Sorted : " << endl;
    cout << checkIfTheArrayIsSorted(vec3, n3);

    cout << endl
         << "Remove Duplicates in-place from sorted array, Brute : " << endl;
    vector<int> vec4 = {1, 1, 2, 2, 2, 3, 3, 4};
    int n4 = vec4.size();
    // cout<<removeDupicatesBrute(vec4,n4); // 3
    // have to comment this as we were calling the below function onn an already manu=iluated array

    cout << endl
         << "Remove Duplicates in-place from sorted array, Optimal : " << endl;
    cout << removeDuplicatesOptimal(vec4, n4); // 3

    cout << endl
         << "Left Rotate the Array by 1 Place, Optimal : " << endl;
    vector<int> vec5 = {1, 2, 3, 4, 5};
    int n5 = vec5.size();
    leftRotateTheArrayBy1Place(vec5, n5);
    for (auto it : vec5)
        cout << it << " "; // 2 3 4 5 1

    cout << endl
         << "Left Rotate the Array by D Place, Brute : " << endl;
    vector<int> vec7 = {1, 2, 3, 4, 5, 6, 7};
    int n7 = vec7.size();
    int d = 3;
    // leftRotateTheArrayByDPlaceBrute(vec7,n7,d);
    // for(auto it:vec7) cout<<it<<" "; // 4 5 6 7 1 2 3

    cout << endl
         << "Left Rotate the Array by D Place, Optimal : " << endl;
    leftRotateTheArrayByDPlaceOptimal(vec7, n7, d);
    for (auto it : vec7)
        cout << it << " "; // 4 5 6 7 1 2 3

    cout << endl
         << "Move Zeroes to the End, Brute : " << endl;
    vector<int> vec6 = {1, 0, 2, 3, 0, 4, 0, 1};
    int n6 = vec6.size();
    // moveZeroesToTheEndBrute(vec6,n6);
    // for(auto it:vec6) cout<<it<<" "; // 1 2 3 4 1 0 0 0

    cout << endl
         << "Move Zeroes to the End, Optimal : " << endl;
    moveZeroesToTheEndOptimal(vec6, n6);
    for (auto it : vec6)
        cout << it << " "; // 1 2 3 4 1 0 0 0

    cout << endl
         << "Union of two Sorted Array, Brute : " << endl;
    vector<int> vec8_1 = {1, 1, 2, 3, 4, 5};
    vector<int> vec8_2 = {2, 3, 4, 4, 5, 6};
    int n8_1 = vec8_1.size();
    int n8_2 = vec8_2.size();
    // vector<int> res = UnionOfTwoSortedArraysBrute(vec8_1, vec8_2, n8_1, n8_2);
    // for (auto it : res)
    //     cout << it << " "; // 1 2 3 4 5 6

    cout << endl
         << endl
         << "Union of two Sorted Array, Optimal : " << endl;
    vector<int> res = UnionOfTwoSortedArraysOptimal(vec8_1, vec8_2, n8_1, n8_2);
    for (auto it : res)
        cout << it << " "; // 1 2 3 4 5 6

    cout << endl
         << endl
         << "Intersecton of two Sorted Array, Brute : " << endl;
    vector<int> vec9_1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> vec9_2 = {2, 3, 3, 5, 6, 6, 7};
    int n9_1 = vec9_1.size();
    int n9_2 = vec9_2.size();
    // vector<int> res9 = insertionOfTwoSortedArrayBrute(vec9_1, vec9_2, n9_1, n9_2);
    // for (auto it : res9)
    //     cout << it << " "; // 2 3 3 5 6

    cout << endl
         << endl
         << "Intersecton of two Sorted Array, Optimal : " << endl;
    vector<int> res9 = insertionOfTwoSortedArrayOptimal(vec9_1, vec9_2, n9_1, n9_2);
    for (auto it : res9)
        cout << it << " "; // 2 3 3 5 6

    cout << endl
         << endl
         << "Missing Number, Optimal_1 : " << endl;    
    vector<int> vec10 = {1,2,4,5}; 
    int n10 = vec10.size();
    int sizeOfTheAcutalArrayIncludingTheMissingNumber=5;
    // cout << MissingNumberOptimal_1(vec10, n10,sizeOfTheAcutalArrayIncludingTheMissingNumber) << endl; // 3

    cout << endl
         << endl
         << "Missing Number, Optimal_2 : " << endl;  
    cout<<MissingNumberOptimal_2(vec10, n10,sizeOfTheAcutalArrayIncludingTheMissingNumber)<<endl;

    cout<<endl<<"Maximum Consecutive Ones : "<<endl;
    vector<int> vec11 = {1,1,0,1,1,1,0,1,1};
    int n11 = vec11.size();
    cout<<MaximumConsecutiveOnes(vec11,n11)<<endl; // 3


    cout<<endl<<"Find the Number that Appears Ones, Better : "<<endl;
    vector<int> vec12={1,1,2,2,3,3,4,4,5};
    int n12=vec12.size();
    cout<<findNumberThatAppearsOnesBetter(vec12,n12)<<endl; // 5

    cout<<endl<<"Find the Number that Appears Ones, Optimal : "<<endl;
    cout<<findNumberThatAppearsOnesOptimal(vec12,n12)<<endl;

    cout<<endl<<"Longest Subarray with sum equals to K, Optimal : "<<endl;
    vector<int> vec13={1,2,3,1,1,1,14,2,3};
    int n13=vec13.size();
    int k=6;
    cout<<longestSubarrayWithSumK(vec13,n13,k)<<endl;

    return 0;
}
