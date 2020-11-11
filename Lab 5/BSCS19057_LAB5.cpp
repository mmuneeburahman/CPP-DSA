#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//Finding Maximum in Array
void findMax(int* arr, int size, int& max) {
	max = arr[size-1];
	int i = size-2; 
	while(i>0){
		if(arr[i]>max)
			max = arr[i];
		--i;
	}
}
//For Printing Array
void printArray(int* arr, int size){
	for(int i =0; i<size; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}
//Return Array with Cumulative Sum
int* cumulativeSum(int* arr, int size, int max,int newSize) {
    
	int* newArray = new int[newSize];
	//Initializing Array with 0s.
	fill(newArray, newArray+newSize, 0);
    
   	 //Finding the Frequency Of each Element
	for(int i = 0; i<size; ++i)
		++newArray[arr[i]];
	
	//Allocating Cumulative Sum in Array 
	int sum = newArray[0];
	for(int i = 1; i<newSize; i++){
	    sum+=newArray[i];
	    newArray[i] = sum;
	}
	return newArray;
}
//Sort Array on the Basis of Cumulative Sum
int* countSort(int*arr, int size, int max){
    
	int newSize = max+1;
	int *cumArray = cumulativeSum(arr, size, max, newSize);
	
	//Getting Sorted Array After Using
	int *sortedArray = new int[size];
	for(int i =0; i<size; i++) {
		sortedArray[cumArray[arr[i]]-1] = arr[i];
	    --cumArray[arr[i]];
	}
	return sortedArray;
}

int main(){
	int max = 0;
	size_t size_1 = 7;
	cout<<"Array 1 is : ";
	int arr[size_1] = {4, 2, 2, 8, 3, 3, 1};
	printArray(arr, size_1);
	findMax(arr, size_1, max);
	int *sortedArray_1 = countSort(arr, size_1, max);
	cout<<"Sorted Array 1 is : ";
	printArray(sortedArray_1, size_1);
	
	
	int size_2 = 5;
	int arr_2[size_2]= {5, 5, 6, 1, 2};
	cout<<"Array 2 is : ";
	printArray(arr_2, size_2);
	findMax(arr_2, size_2, max);
	int *sortedArray_2 = countSort(arr_2, size_2, max);
	cout<<"Sorted Array 2 is : ";
	printArray(sortedArray_2, size_2);
	
	int size_3 = 10;
	cout<<"Array 3 is : ";
	int arr_3[size_3]= {5, 5, 6, 1, 2,1,1,5,5,4};
	printArray(arr_3, size_3);
	findMax(arr_3, size_3, max);
	int *sortedArray_3 = countSort(arr_3, size_3, max);
	cout<<"Sorted Array 3 is : ";
	printArray(sortedArray_3, size_3);
	return 0;
}