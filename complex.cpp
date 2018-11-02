//Passing objects as an argument through a function and returning a object also ,write a program to add two complex number X and Y to produce a third complex number Z and display all the three Complex Number. Use friend function to implement the problem.

#include<iostream>
using namespace std;
class complex
{
float real,imag;
public:
complex()
{}
complex(float r,float im)
{
real=r;
imag=im;
}
friend complex sum(complex,complex);
void display()
{
cout<<"sum=" <<real<<"+i"<<imag<<endl;
}
};
complex sum(complex c1,complex c2)
{
complex c;
c.real=c1.real+c2.real;
c.imag=c1.imag+c2.imag;
return c;
}
int main()
{
float a,b,c,d;
complex c3;
cout<<"enter the first complex no.: "<<endl;
cin>>a>>b;
cout<<"enter the second complex no.: "<<endl;
cin>>c>>d;
complex c1(a,b);
complex c2(c,d);
c3=sum(c1,c2);
c3.display();
return 0;
}
