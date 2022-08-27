#include<iostream>
using namespace std;
void heapSort(int input[], int n){
   // Build the heap in input array
   for(int i=1;i<n;i++){
         int childIndex=i;
      
        while(childIndex>0){
         int parentIndex=(childIndex-1)/2;
        if(input[childIndex]<input[parentIndex]){
            int temp=input[childIndex];
            input[childIndex]=input[parentIndex];
            input[parentIndex]=temp;
        }
        else
        break;
        childIndex=parentIndex;
        }
   }
   // remove element mean we have to do sort the heap
   int size=n;
   while(size>1){
   int temp=input[0];
   input[0]=input[size-1];
   input[size-1]=temp;
   size--;
        int parentIndex=0;
         int LCI=2*(parentIndex)+1;
         int RCI=2*(parentIndex)+2;
         while(LCI<size){

             int minIndex=parentIndex;
             if(input[LCI]<input[minIndex])
             minIndex=LCI;
           if(RCI<size&&input[RCI]<input[minIndex])
             minIndex=RCI;
         	if(minIndex == parentIndex) {
				break;
			}
          
            int temp=input[minIndex];
            input[minIndex]=input[parentIndex];
            input[parentIndex]=temp;
        
            parentIndex=minIndex;
            
         LCI=2*(parentIndex)+1;
          RCI=2*(parentIndex)+2;
         }
   }
}
int main()
{
     int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
  