#include<bits/stdc++.h>
using namespace std;

// function implementing Bubble Sort Algorithm :
pair<int,int> bubble_sort(int *input , int size){  // tc of this code is O(n^2)
	int count_swaps = 0 ; // maintain the count of the number of swaps
	int count_comparisons = 0 ; // maintain the count of the number of comparisons
	for(int j=0;j<size-1;j++){
		for(int i=0;i<size-1-j;i++){
			if(input[i]>input[i+1]){
				int temp = input[i];
				input[i]=input[i+1];
				input[i+1]=temp;
				count_swaps++;
			}
			count_comparisons++;
		}
	}
	pair<int,int> ans;
	ans.first = count_swaps; // first member will store the number of swaps
	ans.second = count_comparisons; // second member will store the number of comparisons
	return ans;
}


// function to implement Selection Sort Algorithm :
pair<int,int> selection_sort(int *input , int size){
	int min_index ;
	int count_swaps = 0;
	int count_comparisons = 0;
	for(int i=0;i<size;i++){
		min_index = i;
		for(int j=i+1;j<size;j++){
			if(input[j]<input[min_index]){
				min_index=j;
				count_swaps++;
			}
			count_comparisons++;
		}
		int temp = input[i];
		input[i]=input[min_index];
		input[min_index]=temp;
	}
	pair<int,int> ans;
	ans.first = count_swaps;
	ans.second = count_comparisons;
	return ans;
}


int32_t main(){
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;

	int arr[n];
	cout<<"Enter the elements of the array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	pair<int,int> bubble = bubble_sort(arr,n);
	pair<int,int> selection = selection_sort(arr,n);

	cout<<"Comparison between Insertion and Bubble sort :"<<endl;

	cout<<"1. On the basis of number of comparisons : "<<" ";
	if(bubble.second >selection.second){
		cout<<"More Comparisons are required for bubble sort."<<endl;
	}
	else if (bubble.second < selection.second){
		cout<<"More Comparisons are required for selection sort."<<endl;
	}
	else {
		cout<<"Both require equal number of operations."<<endl;
	}


//  second comparison


	

	cout<<"2. On the basis of number of swaps : "<<" ";
	if(bubble.first >selection.first){
		cout<<"More swaps are required for bubble sort."<<endl;
	}
	else if (bubble.first < selection.first){
		cout<<"More swaps are required for selection sort."<<endl;
	}
	else {
		cout<<"Both require equal number of swaps."<<endl;
	}


	cout<<"3. As both Bubble Sort and Selection Sort are in-place algorithms, hence both of their In-place Algorithm have been written above."<<endl;
}


/*
// BONUS Question :
	TIME COMPLEXITY OF BUBBLE SORT
   From the above code of BUBBLE SORT we can see that there are two
   while loops which will we executed.First while loop will run n-1
   times and second while loop will run n-2 times and so on till 1 time.
   Time Complexity=(n-1)+(n-2)+(n-3)....+2+1=(n-1)(n)/2
                  =O(n^2)
	TIME COMPLEXITY OF SELECTION SORT
    In selection sort the main time consuming task is finding minimum 
    element from the array.We have to scan all the elements of the
    array to find the minimum element.
    With reference to the above code of SELECTION SORT,first we will 
    search for minimum element in array of size n,then in the same array of size n-1,and so on till array of size 1.
    Time Complexity=(n)+(n-1)+(n-2)...1=(n)(n+1)/2
                   =O(n^2)
*/
