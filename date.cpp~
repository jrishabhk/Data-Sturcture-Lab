#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class date
{
	int dd,mm,yy;
	public:
	date(int d,int m,int y)
	{
		dd=d;
		mm=m;
		yy=y;
	}
	int operator-(date d2);
	void check();
	date operator+(int n);
	friend ostream &operator<<(ostream &,date);
};
	
int date::operator-(date d2)
{
	date d1(dd,mm,yy);
	int nod=0,flag=0;
	if(d2.dd==d1.dd&&d2.mm==d1.mm&&d2.yy==d1.yy)
		return nod;
	else
		flag=1;
	while(flag)
	{
		d2.dd++;
		nod++;
		d2.check();
		if(d2.dd==d1.dd&&d2.mm==d1.mm&&d2.yy==d1.yy)
			flag=0;
	}
	return nod;
}
date date::operator+(int n)
{
	date d(dd,mm,yy);
	for(int i=0;i<n;i++)
	{
		d.dd++;
		d.check();
	}
	return d;
}	
void date::check()
{
	if(yy%4==0&&mm==2&&dd==29)
		return;
	else if(dd>a[mm])
	{
		dd=1;
		mm++;
	}
	if(mm>12)
	{
		mm=1;
		yy++;
	}
}
ostream &operator<<(ostream &out,date d)
{
	out<<d.dd<"/";
	out<<d.mm<<"/";
	out<<d.yy<<endl;
	return out;
}

int main()
{
	int d,m,y,n;
	cout<<"\nEnter the date d1>d2"<<endl;
	cout<<" Enter valid date \n";
	cin>>d>>m>>y;
	date d1(d,m,y);
	cout<<"Enter the valid date d2\n";
	cin>>d>>m>>y;
	date d2(d,m,y);
	n=d1-d2;	
	cout<<"\n Difference b/w the dates is="<<n;
	cout<<"\n no. of days:";
	cin>>n;
	d2=d1+n;
	cout<<"\n date will be "<<d2<<endl;
}
	
	
	
