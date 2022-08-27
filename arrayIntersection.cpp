#include<iostream>
using namespace std;
void swap(int a[],int i , int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void merge(int input[] ,int s,int e){
   
  int output[e-s+1];
    int i=s,mid=(s+e)/2,j=mid+1;
    int k=0;
    while(i<=mid && j<=e){
        if(input[i]<input[j]){
            output[k++]=input[i];
            i++;
        }
        else{
            output[k++]=input[j];
            j++;
        }
    }
    while(i<=mid){
        output[k++]=input[i];
            i++;
    }
    while(j<=e){
        output[k++]=input[j];
            j++;
    }
    for(int i=0;i<e-s+1;i++){
        input[s+i]=output[i];
    }

}
void m_sort(int a[] , int s , int e){
    if(s>=e){
        return;
    }
    int m=(s+e)/2;
    m_sort(a,s,m);
    m_sort(a,m+1,e);
  merge(a,s,e);
}
void mergeSort(int a[] , int n){
    if(n==0||n==1){
        return;
    }
   m_sort( a , 0,n-1);

    
}
 void intersection(int a1[], int a2[] , int n1 , int n2){
    mergeSort(a1,n1);
    mergeSort(a2,n2);
     int b[20];
    int count=0;
     for(int i=0;i<n1;i++){
         for(int j=0;j<n2;j++){
             if(a1[i]==a2[j]){
                 b[count++]=a2[j];
             }
         }
     }
     for(int i=0;i<count;i++){
         cout<<b[i]<<" ";
     }

 }
// void intersection(int a1[], int a2[] , int n1 , int n2){
//     int b[20];
//     int count=0;
//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n2;j++){
//             if(a1[i]==a2[j]){
//                 b[count++]=a2[j];
//             }
//         }
//     }
//     for(int i=0;i<count;i++){
//         cout<<b[i]<<" ";
//     }
// }
int main()
{
    
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
    return 0;
}