// https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1#
// class Solution{
// 	 void reverse(int arr[],int i,int j)
// 	 {  
// 	     while(i<j)
// 	     {
// 	         swap(arr[i++],arr[j--]);
// 	     }
// 	 }
	
// 	public:
// 	void leftRotate(int arr[], int k, int n) 
// 	{ 
// 	   int d= k%n;  // <----imp
// 	   reverse(arr,0,d-1);
// 	   reverse(arr,d,n-1);
// 	   reverse(arr,0,n-1);
// 	} 
		 

// };
// note : if rotate array left 
// steps :-
// 1.rotate array from 0 k-1
// 2.rotae array from k till n-1;
// 3. rotate array from 0 ,n-1;

// note : if rotate array right
// steps :-
// 1.rotate array from n-k, n-1
// 2.rotae array from 0 till n-k-1;
// 3. rotate array from 0 ,n-1;


