#include<iostream>
using namespace std;
template <typename T,typename V>
class Pair{
  T x;
  V y;
  public:
  void setX(T x){
      this->x=x;
  }
   void setY(V y){
      this->y=y;
  }
  T getX(){
      return x;
  }
  V getY(){
      return y;
  }
};
int main()
{
   /* pair<int> p1;  
    p1.setX(10);
    p1.setY(20);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;
    pair<double> p2;
    p2.setX(100.34);
    p2.setY(34.21);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
    pair<char> p3;*/
    Pair<int,double> p1;
    p1.setX(100.34);
    p1.setY(100.34);
 cout<<p1.getX()<<" "<<p1.getY()<<endl;
    Pair<Pair<int,int>,int> p2;  // triplet
    p2.setY(10);
    Pair<int,int>p4;
    p4.setX(15);
    p4.setY(16);
    p2.setX(p4);
    cout<<p2.getY()<<" "<<p2.getX().getX()<<" "<<p2.getX().getY();
    return 0;
}