// Name: Lillibeth Hunter and Jade Ainsworth
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 5

#include <iostream>
using namespace std;
int Menu(){
	int opt;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout << " Choose an option " << endl;
	cout << "1. Read class size " << endl;
	cout << "2. Read class grades " << endl;
	cout << "3. Compute class average" << endl;
	cout << "4. Quit program " << endl;
	cin >> opt;
	
	return opt;
}
double findAverage(int grades[], int i, int classSize)
{
	if(i == classSize-1)
		return grades[i];
	if(i==0)
		return ((grades[i] + findAverage(grades, i+1, classSize))/classSize);
		
	return (grades[i] + findAverage(grades, i+1, classSize));
}

int main()
{
	int option;
	int classSize= 0;
	double grade;
	int grades [classSize];
	
	option=Menu();

	
	while (option != 4)
	{
		switch(option)
		{
			case 1:
			{
			cout <<"Enter class size: " <<endl;
			cin >> classSize;
			
			cout << "You entered class size: " << classSize << endl;
			break;
			}
			case 2:
			{
			cout << "Enter Grades: " << endl;
			for(int i = 0; i < classSize; i++)
			{
				cin >> grade;
				if(grade >= 0 && grade <= 100)
				{
					grades[i] = grade;
				}
				else
				{
					cout << "invalid Grade Value, re-enter: " << endl;
					i--;
				}
				//grades[i]=grade;
			}
			cout << "You entered grades : " << endl;
			for(int i = 0; i < classSize; i++)
			{
				cout << grades[i] << " ";
			}
			cout << endl;
			}
			break;
		
			case 3:
			{
			cout<<"class average: " <<  findAverage(grades, 0, classSize)<< endl;
			break;
			}
		}
		
	option=Menu();
	}
	return 0;
}


