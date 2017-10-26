#include<iostream>
using namespace std;
class employee
{
	private :
	   int emp_no;
	   char emp_name[20];
   	   float basic;
	   float all_allowances;
	   float it, net_sal;
	public :
	   void read_data();
	   void net_salary();
	   void display();
};
void employee::read_data()
{
    cout<<"enter name\n";
    cin>>emp_name;
    cout<<"enter employee number\n";
    cin>>emp_no;
    cout<<"basic salary\n";
    cin>>basic;
    net_salary();
}
void employee::net_salary()
{
    float gross;
    all_allowances=(123.0/100)*basic;
    gross=basic+all_allowances;
    it=((30.0)/100)*gross;
    net_sal=gross-it;
}
void employee::display()
{
    cout<<emp_name<<"\t\t\t";
    cout<<emp_no<<"\t\t";
    cout<<all_allowances<<"\t\t";
    cout<<it<<"\t\t";
    cout<<net_sal<<"\t\t";
    cout<<basic<<"\t\n";
}
int main()
{
    int i,n;
    employee a[30];
    cout<<"enter the number of employee\n";
    cin>>n;
    cout<<"enter the details of employee\n";
    for(i=0;i<n;i++)
    {
	a[i].read_data();
    }
    cout<<" emp_no\temp_name\t basic\tall_allowance\t IT\t net_sal\n";
    for(i=0;i<n;i++)
    {
	a[i].display();
	cout<<endl;
    }
}
