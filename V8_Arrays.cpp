#include<bits/stdc++.h>
using namespace std;
int largestValueInAnArray(vector<int> &vec,int n){
    int largest=vec[0]; // as we know one of the elements of the array has to be the largest so, take any one of it and just traverse the entire array comparing
    for(int i=0;i<n;i++){
        if(vec[i]>largest) largest=vec[i];
    }
    return largest;
}

int secondLargestValueInAnArrayBetter(vector<int> &vec,int n){
    int l1=vec[0];
    for(int i =0;i<n;i++){
        if(vec[i]>l1) l1=vec[i];
    }
    int l2=vec[0];
    for(int i =0;i<n;i++){
        if(vec[i]>l2 && vec[i]!=l1) l2=vec[i];
    }
    return l2;
}
int secondLargestValueInAnArrayOptimal(vector<int>vec, int n){
    // will make largest=arr[0] and secondLargest=INT_MIN(-1 if the numbers are not negative), 
    // We will Traverse the Array and if arr[i]>largest then secondLargest=largest and largest=arr[i].
    // The intutition 
    // Largest  = 1;
    // secondLargest = INT_MIN;
    // arr[i] = 2;
    // secondLargest = 1 ;
    // Largest = 2; / The largest becomes the second largest if it finds any element greater then it.
    int largest=vec[0],secondLargest=INT_MIN;
    for(int i=1;i<n;i++){
        if(vec[i]>largest){
            secondLargest=largest;
            largest=vec[i];
        }
        else if(vec[i]<largest && vec[i]>secondLargest){
            secondLargest=vec[i];
        }
        // we have ton do this for
        // [1,2,4,7,7,5], till 7 it will be good as
        // largest = 7
        // secondLargest = 5,
        // But as it goes ahead vec[i]= 5 but it si not greater then largest=7 so will have an else if that says that if
        // vec[i]<largest &&  vec[i]>secondLargest 
        // secondLargest=vec[i];
    } return secondLargest;
}

int secondSmallestValueInAnArrayOptimal(vector<int> &arr, int n){
    int smallest=arr[0],secondSmallest=INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            secondSmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]!=smallest && arr[i]<secondSmallest){
            secondSmallest=arr[i];
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
    }return secondSmallest;
}

bool checkIfTheArrayIsSorted(vector<int> &arr,int n){
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]) return false;
        } return true;
}

// use Set as it only stores unique elements
int removeDupicatesBrute(vector<int> &arr,int n){
    set<int> st;
    for(int i=0;i<n;i++){ // vec ={1,1,2,2,2,3,3}
        st.insert(arr[i]);
    } // inserting all the values of array inside st = {1,2,3}

    // as we have to return the index
    int ind=0;
    for(auto it:st){
        arr[ind++]=it; // arr[0] = 1, arr[1]=2,arr[2]=3 and as it is going
        //  ind++ ind value at this point will be 3, it is the index number and as we are following 0 based indexing it will be the size of the array. 
    }
    return ind;
    // 1.  insertion in set takes O(nlogn)
    // 2.  for inserting it again in the array it will be O(n)
    // TC =  O(n+nlogn)
    // SC = O(n), as we are taking a set data  structure and it might take n values
}

// Focus on, we have given a sorted array
int removeDuplicatesOptimal(vector<int> &arr,int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j]; // we are just putting the value of RHS to LHS
            i++; 
        }
    }return i+1; // TC = O(n), SC = O(1)
    // Before : {1,1,2,2,2,3,3,};
    // i = 0th index, j=1st index
    // i = 0th index, j=2nd index
    // as they are different putting 2nd index value in i+1(1st index) and then i++ so that i is poiting to 1st index now
    // After : {1,2,2,2,2,3,3}; 
    // i = 1st index, j=2nd index
}
void leftRotateTheArrayBy1Place(vector<int> &arr,int n){
    int temp = arr[0];  
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
} // TC = O(n), SC = O(1)
// So basically we are just putting the value of the 0th index inside the temp variable and traversing inside the array and putting arr[i-1]=arr[i] and at last position we are putting the value stored in the temp
// {1,2,3,4,5}
// temp = 1
// arr[0]=arr[1]...arr[3]=arr[4]
// arr[n-1]=temp

void moveZeroesToTheEndBrute(vector<int> &arr, int n){
    vector<int> temp;
    for(int i=0;i<n;i++){ // size is n so O(n)
        if(arr[i]!=0) temp.push_back(arr[i]);
    }
    for(int i=0;i<temp.size();i++){ // size is x so O(x)
        arr[i]=temp[i];
    }
    for(int i =temp.size();i<n;i++){ // size is n-x so O(n-x)
        arr[i]=0;
    } 
    // Total TC = O(n+x+n-x) => O(2n),
    // SC = O(x) i.e. the size of the temp array having 0s,
    // O(n) i.e. size of the temp array with no 0s(we copied the entire array into the temp array)
}
void leftRotateTheArrayByDPlaceBrute(vector<int> &arr,int n,int d){
    // checking how many rotation we have to do
    // if d = n then 0 rotation
    // if d = n+1 then only 1 rotaton
    // So,
    d=d%n;
    vector<int> temp;
    for(int i=0;i<d;i++){ // O(d)
        temp.push_back(arr[i]); // pushing back the value of the main array into a temp array, till the part we have to rotate
        
    }   
    for(int i=d;i<n;i++){ // O(n-d)
        arr[i-d]=arr[i]; // i-d => arr[d-d = 0]=arr[d = 3],
        // arr[d+1-d = 1]=arr[d+1 = 4];
    }
    // just remember this if u want to push the value from a point and also want it to increment with every loop just start from that point i=d, and if u want to convert the front number i-d=>d-d=>0, in the next loop it will become d+1-d=>1

    // int j=0;
    for(int i=n-d;i<n;i++){ // O(d)
        // arr[i]=temp[j];
        // j++; // lets start traversing temp from j=0 and 
        // j++ then, and putting the value inside arr after n-d

        // before rotating if we observe that as we know that the 0th value will go in the n-d place and the 1st value will go in the n-d+1 place so
        arr[i]=temp[i-(n-d)];
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
void leftRotateTheArrayByDPlaceOptimal(vector<int> &arr,int n,int d){
    // reverse upto d
    reverse(arr.begin(),arr.begin()+d); // O(d)
    // reverse from n-d to d
    reverse(arr.begin()+d,arr.end()); // O(n-d)
    // reverse from 0 to n 
    reverse(arr.begin(),arr.end()); // O(n)
} // TC = O(n+n-d+d) => O(2n), SC=O(1)

vector<int> moveZeroesToTheEndOptimal(vector<int> &arr,int n){
    // we will be doing to things, firstly will be checking if there arer any zeroes in the array and also it there are 0s then putting j on the index where 0 appears for the first time
    int j=-1;
    for(int i =0;i<n;i++){ // O(x), where the first 0 was found
            if(arr[i]==0){
                j=i;
                break;
            }
    }
    if(j==-1) return arr;
    for(int i=j+1;i<n;i++){ // O(n-x)
        if(arr[i]!=0){
            swap(arr[j],arr[i]);
             j++; // as we are moving along with the 0, j will always have that 0 value
        }
    } return arr;
    // {1,0,2,3,2,0,0,4,5,1}
    // j=1st ind
    // i=2nd index
    // swap, j++, i++
    // {1,2,0,3,2,0,0,4,5,1}
    // j=2nd ind
    // i=3rd index
    // TC = O(x+n-x)=>O(n), SC = O(1)
}
int main(){
    cout<<"Largest Element in an Array : "<<endl;
    vector<int> vec1={3,2,1,5,2};
    int n1=vec1.size();
    cout<<largestValueInAnArray(vec1,n1); // 5

    cout<<endl<<"Second Largest Element in an Array Better : "<<endl;
    vector<int> vec2={1,2,4,7,7,5};
    int n2=vec2.size();
    cout<<secondLargestValueInAnArrayBetter(vec2,n2); // 5

    cout<<endl<<"Second Largest Element in an Array Optimal : "<<endl;
    cout<<secondLargestValueInAnArrayOptimal(vec2,n2); // 5

    cout<<endl<<"Second Smallest Element in an Array Optimal : "<<endl;
    cout<<secondSmallestValueInAnArrayOptimal(vec2,n2); // 2

    vector<int> vec3={1,2,2,3,3,4};
    // vector<int> vec3={1,2,1,3,4};
    int n3=vec3.size();
    cout<<endl<<"Check if the Array is Sorted : "<<endl;
    cout<<checkIfTheArrayIsSorted(vec3,n3); 

    cout<<endl<<"Remove Duplicates in-place from sorted array, Brute : "<<endl;
    vector<int> vec4={1,1,2,2,2,3,3,4};
    int n4=vec4.size();
    // cout<<removeDupicatesBrute(vec4,n4); // 3 
    // have to comment this as we were calling the below function onn an already manu=iluated array

    cout<<endl<<"Remove Duplicates in-place from sorted array, Optimal : "<<endl;
    cout<<removeDuplicatesOptimal(vec4,n4); // 3

    cout<<endl<<"Left Rotate the Array by 1 Place, Optimal : "<<endl;
    vector<int> vec5={1,2,3,4,5};
    int n5=vec5.size();
    leftRotateTheArrayBy1Place(vec5,n5);
    for(auto it:vec5) cout<<it<<" "; // 2 3 4 5 1

    cout<<endl<<"Left Rotate the Array by D Place, Brute : "<<endl;
    vector<int> vec7={1,2,3,4,5,6,7};
    int n7=vec7.size();
    int d=3;
    // leftRotateTheArrayByDPlaceBrute(vec7,n7,d);
    // for(auto it:vec7) cout<<it<<" "; // 4 5 6 7 1 2 3

    cout<<endl<<"Left Rotate the Array by D Place, Optimal : "<<endl;
    leftRotateTheArrayByDPlaceOptimal(vec7,n7,d);
    for(auto it:vec7) cout<<it<<" "; // 4 5 6 7 1 2 3

    cout<<endl<<"Move Zeroes to the End, Brute : "<<endl;
    vector<int> vec6={1,0,2,3,0,4,0,1};
    int n6=vec6.size();
    // moveZeroesToTheEndBrute(vec6,n6);
    // for(auto it:vec6) cout<<it<<" "; // 1 2 3 4 1 0 0 0

    cout<<endl<<"Move Zeroes to the End, Optimal : "<<endl;
    moveZeroesToTheEndOptimal(vec6,n6);
    for(auto it:vec6) cout<<it<<" "; // 1 2 3 4 1 0 0 0


    return 0;
}