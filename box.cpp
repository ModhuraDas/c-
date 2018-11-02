/*.Create a class Box containing Len, Br and Ht as data members. Use constructors for taking input and overload the following operators :
(i)“++” to increment all data
(ii) “+” to add corresponding data members of two Box class objects.
Use display () method to display the appropriate outputs.*/

#include<iostream>
using namespace std;
class Box
{
	int l,b,h;
	public:
	Box()
	{}
	Box(int x,int y,int z)
	{	l=x;
		b=y;
		h=z;}
	void operator++()
	{	l++;
		b++;
		h++;}

		//cout<<l<<b<<h;}
	Box operator+(Box m)
	{	l=l+m.l;
		b=b+m.b;
		h=h+m.h;
		return Box(l,b,h);}
	void display()
	{	cout<<"\n\nLenth of box : "<<l;
		cout<<"\nBreadth of box : "<<b;
		cout<<"\nHeight of box : "<<h<<endl<<endl;}
};


int main()
{	int m,n,p;
	cout<<"\nEnter the length:"<<endl;
	cin>>m;

	cout<<"\nEnter the breadth:"<<endl;
	cin>>n;

	cout<<"\nEnter the height:"<<endl;
	cin>>p;

	Box b1(m,n,p),b2(m+1,n+1,p+1),b3(0,0,0);
	b1.display();
	b2.display();
	++b1;
	++b2;
	b3=b1+b2;
	cout<<"\n\nAfter adding corrosponding data members of two Box class objects :";
	b3.display();
}

