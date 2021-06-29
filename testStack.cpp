// Name: Lillibeth Hunter and Jade Ainsworth
// Class: CS 3305
// Term: Summer 2021
// Instructor: Dr. Haddad
// Assignment: 4

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void topToBottom(stack<int> integers)
{
	stack <int> tempIntegers;
		
		while(!integers.empty())
		{
			tempIntegers.push(integers.top());
			
			cout <<(tempIntegers.top())<< " ";
			integers.pop();
				/*int x = integers.top();

			integers.pop();
			
			cout << x << " ";
			topToBottom(integers);
			/*takes a stack object of type integer and displays the stack content
		from the top of the stack to the bottom of the stack. That is, the top value is printed first; while the
		bottom value is printed last. This function does not change the stack content.*/
			//integers.push(x);
		}
}

void bottomToTop(stack<double> doubles)
{
	stack<double> tempDoubles;
	/*takes a stack object of type double and displays the stack content
from the bottom of the stack to the top of the stack. That is, the bottom value is printed first; while
the top value is printed last. This function does not change the stack content.*/
		if(doubles.empty())
			return;
			//populate temp stack from original stack
			double x = doubles.top();
			doubles.pop();
			
			//recursively call
			bottomToTop(doubles);
			
			cout << x << " ";
			doubles.push(x);

}

void flipStack(stack<string> food)
{
	/*takes a stack object of type string and returns the same stack object
with its content being flipped. That is, if the stack has values are Ed, Tom, Bob, Amy before
calling this function, the stack will have the values Amy, Bob, Ed, Tom after the function is
executed*/

	if(food.empty())
			return;
			//populate temp stack from original stack
			string x = food.top();
			food.pop();
			
			//recursively call
			flipStack(food);
			
			cout << x << " ";
			food.push(x);
}

bool searchStack(stack<int> integers, int target)
{
	/*takes 2 parameters: a stack object of type integer and an integer
target value. It returns true if the target value is on the stack at any place; otherwise it returns
false. This function does not change the stack content.*/
	while(!integers.empty())
		{
			if( target == integers.top())
			{
				return true;
			}
			integers.pop();
		}
		return false;
}

int main()
{
	//populate array with integers
	stack<int> integers;
	integers.push(21);
	integers.push(34);
	integers.push(56);
	integers.push(77);
	integers.push(138);
	
	//populate array with doubles
	stack<double> doubles;
	doubles.push(2.1);
	doubles.push(3.4);
	doubles.push(5.6);
	doubles.push(7.7);
	doubles.push(13.8);
	
	//populate array with strings
	stack<string> food;
	food.push("pancakes");
	food.push("pizza");
	food.push("pear");
	food.push("pineapples");
	food.push("pastry");
	
	//USER INPUT MENU
	int option; 
	int target = 0;
	
	while(option != 5)
	{
	cout<< "Select an option: " <<endl;
	cout<<"1: Test function topToBottom with integer type stack" << endl;
	cout<<"2: Test function bottomToTop with double type stack" << endl;
	cout<<"3: Test function flipStack with string type stack" <<endl;
	cout<<"4: Test function searchStack with integer type stack" <<endl;
	cout<<"5: Quit program"<<endl;
	cin>> option;
	
		switch(option)
		{
			case 1:
			topToBottom(integers);
			break;
			
			case 2:
			bottomToTop(doubles);
			break;
			
			case 3:
			flipStack(food);
			break;
			
			case 4:
			//NOTE: cannot find the target value in list even though it is in list
			//get target value from user
			cout<< "enter target value.";
			cin >> target;
			if(searchStack(integers, target)== true)
				cout<<"found"<< endl;
			else{cout << "not found" << endl;}
			break;
		}
	}
	return 0; 
}

