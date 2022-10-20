//                          Sujal Aggarwal
//                          ECE 
//                          21105036

/*           


Ques1 What is the difference between in-place and out-place sorting algorithms?
        An "In-Place" sorting algorithm is algorithm whose space 
        complexity lies between O(1) and O(logn) both included.
        Whereas an "Out-Place"  is an algorithm whose space 
        complexity is greater than O(logn). Therefore, we can 
        say that In-Place uses small extra space and changes 
        the input itself and Out-Place uses space to perform
        the algorithm.
*/



//Ques2 Implement Insertion sort in both (in-place and out-place) manner.

        //Insertion Sort Using In-Place Algorithm
        #include <iostream>
        using namespace std;

/*
Implementation of Insertion Sort in both in-pace and out-place manner 
*/

#include<bits/stdc++.h>
using namespace std;

// in-place ::

void insertion_sort_IP(int arr[],int n){ // taking the the size and the array as arguments for the function

    //Initialising variables i and j
    int i=0,j=i+1;

    while(j<=n-1){  // starting a loop to iterate over array elements 

        int temp=arr[j];  // temp variable to iterate 

        while(i>=0){   // condition on i , to avoid invalid cases

            if(arr[i]>temp){   // if arr[i]>temp means we need to shift the value to the right
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}  // executes only if i was 0 at the beginning of loop and entered the above if condition and became -1

            if(arr[i]<=temp){arr[i+1]=temp;break;}  //if arr[i]<=temp means we should update the value of arr[i+1] and fill it with the value in temp variable

        }
        // increament operations for loop 
        j++;  
        i=j-1;
    }
    // since , function type is void , we return nothing
    return;
}


// out-place 

// we will be using extra space in this algo  -- stack space of recursion

void insertion_sort_OP(int arr[],int si,int ei){  // taking the arguments for the function for suitable implementation
    //si=starting index
    //ei=ending index

    if(si==ei){return;} // we reached end of the array 

    // initializing temp variables to iterate over the array
	int j=si+1;
    int temp=arr[j];

    while(si>=0){ 

        if(arr[si]>temp){// if arr[i]>temp means we need to shift the value to the right
            arr[si+1]=arr[si];
            si--;
        }

        if(si==-1){arr[0]=temp;break;}  // executes only if si was 0 at the beginning of loop and entered the above if condition and became -1
        
        if(arr[si]<=temp){arr[si+1]=temp;break;}  //if arr[si]<=temp means we should update the value of arr[si+1] and fill it with the value in temp variable
    }
    // recursive call on the function after increasing the si
    insertion_sort_2(arr,si+1,ei);
}

// performing the functions :

        int main(){
            int n;  // size of the array
            cout<<"Enter the size of the array"<<endl;
            cin>>n;

            int arr[n];

            // taking input :
            cout<<"Kindly enter the values of the array"<<endl;
            for(int i=0;i<n;i++){cin>>arr[i];}

            int decide ; // deciding which algo to use
            cout<<"Kindly decide the algorithm using which you want to sort your array :"<<endl;
            cout<<"Enter 0 for in-place algorithm and 1 for out-place algorithm :"<<endl;
            cin>>decide;

            if(decide==0){
                // calling inplace function :
                insertion_sort_IP(arr,n);
                // now the array is sorted 
                cout<<"For in-place algorithm your sorted array is :"<<endl;
                // printing it :
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
            else if(decide==1){
                // calling outplace function:
                insertion_sort_OP(arr,0,n-1);  // since we want to sort the array from beginning to end i.e. si = 0 and ei = n-1
                // now the array is sorted
                cout<<"For out-place algorithm your sorted array is :"<<endl;
                //printing it :
                for(int i=0;i<n;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
            else {
                cout<<"Please enter valid input"<<endl;
            }
        }
/*

Ques3 Suggest some practical examples of using in-place and out-place techniques.
        In-place technique is better suited for solving problems that require 
        one to solve the problem without using extra space.
        for example :
            we are assigned the duty to sort the list of marks of students in ascending order
            now , if we implement changes in the original dataset itself as in the case of insertion
            sort this way, we dont have to create any new dataset , however it may be difficult to implement the algorithm
        Out-Place technique is better suited for solving problems , where we are not much concerned about 
        using extra space 
        for example :
                    used recursion to solve it then a stack of n space would also be used
                    we would have chosen out-place , in this case the implementation of the algorithm is comparatively easier
                    merge sort is one such algorithm that uses out-place technique and is widely used due to less time complexity however , its' space complexity is O(n) as expected
		
*/
