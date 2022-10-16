/* Name - Sujal Aggarwal
   SID - 21105036
   Branch - ECE
*/

#include<bits/stdc++.h>
using namespace std;

// LINEAR SEARCH 

/* in case of linear search , the element must be present in the array
or we might end up in infinite loop (otherwise , the function can also return a garbage value)
however, in case of linked list , this is not the case , since we will terminate the loop with the (temp->next == NULL) condition */


// function to implement the linear search

int linear_search(int* arr , int z){ 
	int j=0;  // considering zero-based indexing 
	while(true){
		if(arr[j]==z){
			return j;
		}
		j++;
	}
}

// BINARY SEARCH

/* bianry search works only on sorted array ( whether increasing or decreasing ) */
/* In the given problem , since the size is unknown , we cant know the right(max_index) value for the search 
In order to solve this problem, we will use a modified binary search 

Firstly , we will find an index i such that k < A[i] and then do binary search from 0 to i
Now, since A[i] > k and all elements above i will be greater than or equal to A[i] hence there is zero possibility that k will be founded there

To implement this , initially we will set left = 0 and right = 1
now if k > A[right]  // means we need to go further than right index to find greater values (and potentially k)
right = right*2 // double the search range 
and now we can do normal binary search on arr[left] to arr[right] to find element k*/


// code for normal binary search :

int binary_search_normal ( int arr[] , int z , int left , int right){
	
	int mid = (left+right)/2; 

	while(left<=right){
		if(arr[mid] > z)  // this means z lies to the left of mid
		{
			right = mid - 1;  // reducing our search space
			mid = (left + right)/2;  
		}

		else if(arr[mid] < z)
		{
			left = mid + 1;  //reducing search space
			mid = (left + right)/2; 
		}
		else
		{
			return mid;  // this means that the value has been found so we simply return it
		}
	}
}
int binary_search(int arr[] , int z){
	int left = 0;
	int right = 1;

	while(arr[right] < z)  // z lies to right side of our current right pointer
	{
		left = right ;  // updating left pointer since , z will lie above it for the given condition
		right = right * 2;  // doubles the range of our search 
	}
	// now we have desired / optimal values for left and right 

	return binary_search_normal(arr , z , left , right ) ; // calling normal binary search on the required part of the array
}

int main(){

	int *arr = new int[1000000] ; // dynamically creating the array with large size as we don't know the input size
	int size ;
	cout<<"Enter the number of elements in the array : "<<endl;
	cin>>size;

	cout<<"Enter the elements of the array : "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}

	int z ; // the element which we will be searching
	cout<< "Enter the element you want to search : "<<endl;
	cin>>z;

	char decide ; // to decide whether to do linear or binary search 

	cout<<" Choose the type of search you want to do (linear(L) or binary(B) ) : " <<endl;
	cin>>decide;

	/* Firstly , finding whether the element is present in array or not ( garbage or inf loops will return different values in linear and binary search) */
	int index_linear = linear_search(arr,z);
	int index_binary = binary_search(arr,z);
    if(decide=='L'){
            cout<<" Index of "<< z << " in the given array is : "<<index_linear<<endl;
    }
    else if (decide=='B'){
            cout<<" Index of "<<z<< " in the given array is : "<<index_binary<<endl;
    }
    else {
        cout<<" Please enter valid options :"<<endl;
        cout<< " L for lineary search"<<endl;
        cout<< " B for binary search"<<endl;
	}
	delete[] arr;
}
