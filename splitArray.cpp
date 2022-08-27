#include<iostream>
using namespace std;
bool helper(int* arr, int n, int s, int lsum, int rsum)
{
	if (s == n)
		return lsum == rsum;
	if (arr[s] % 5 == 0)
		lsum += arr[s];

	
	else if (arr[s] % 3 == 0)
		rsum += arr[s];

	else
		return helper(arr, n, s + 1, lsum + arr[s], rsum)|| helper(arr, n, s + 1, lsum, rsum + arr[s]);
	return helper(arr, n, s + 1, lsum, rsum);
}
bool splitArray(int* arr, int n)
{
	return helper(arr, n, 0, 0, 0);
}

// Driver code


// bool splitArray(int arr[] , int n){
//     int leftSum = 0;
//     for (int i = 0 ; i < n ; i++)
//         leftSum += arr[i];
//     int rightSum = 0;
//     for (int i=n-1; i >= 0; i--)
//     {
//         rightSum += arr[i];
//         leftSum -=  arr[i] ;
 
//         if (rightSum == leftSum)
//             return true;
//     }
//         return 
//         false;
// }
int main()
{
 int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
   
    return 0;
}