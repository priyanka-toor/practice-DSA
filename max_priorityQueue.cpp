#include<iostream>
using namespace std;
#include<vector>
class PriorityQueue{
    vector<int> pq;
    public:
    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    // return no. of elements in priority queue
    int getSize(){
        return pq.size();
    }
    int getMax(){
        if(isEmpty()){
            return 0; // repersenting priority queue is empty
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childIndex=pq.size()-1;
      
        while(childIndex>0){
         int parentIndex=(childIndex-1)/2;
        if(pq[childIndex]>pq[parentIndex]){
            int temp=pq[childIndex];
            pq[childIndex]=pq[parentIndex];
            pq[parentIndex]=temp;
        }
        else
        break;
        childIndex=parentIndex;
        }
    }
     int removeMax(){
       if(isEmpty()){
            return 0; 
        }
         int ans=pq[0];
         pq[0]=pq[pq.size()-1];
         int n=getSize();
         pq.pop_back();
         int parentIndex=0;
         int LCI=2*(parentIndex)+1;
         int RCI=2*(parentIndex)+2;
         while(LCI<pq.size()){

             int maxIndex=parentIndex;;
             if(pq[LCI]>pq[maxIndex])
             maxIndex=LCI;
           if(RCI<pq.size()&&pq[RCI]>pq[maxIndex])
             maxIndex=RCI;
         	if(maxIndex == parentIndex) {
				break;
			}
          
            int temp=pq[parentIndex];
            pq[parentIndex]=pq[maxIndex];
            pq[maxIndex]=temp;
        
            parentIndex=maxIndex;
            
         LCI=2*(parentIndex)+1;
          RCI=2*(parentIndex)+2;
         }
         return ans;
     }
};
int main()
{
   /* PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }*/
    	PriorityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout << p.getSize() << endl;
	cout << p.getMax() << endl;

	while(!p.isEmpty()) {
		cout << p.removeMax() << " " ;

	}
	cout << endl;

   
    return 0;
}