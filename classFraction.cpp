#include<iostream>
using namespace std;
class fraction{
    private:
    int numerator;
    int denominator;
    public:
    fraction(int numerator , int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
    void add(fraction f2){
      int lcm=this->denominator*f2.denominator;
      int n=f2.denominator*this->numerator+this->denominator*f2.numerator;
     numerator=n;
     denominator=lcm;
    }
};
int main()
{
    fraction f1(10,2);
    f1.print();
    fraction f2(10,2);
    f2.print();
    f1.add(f2);
    f1.print();
    return 0;
}