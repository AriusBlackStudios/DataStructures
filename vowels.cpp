// Name: Lillibeth Hunter and Jade Ainsworth
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 5

#include<iostream>
#include<string>

using namespace std;

int Menu(){
		int opt;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout << "Enter an option: "<< endl;
		cout << "1. Read input String " << endl;
		cout<< "2. Compute number of vowels" << endl;
		cout << "3. Quit Program" << endl;
		cin>>opt;
		return opt;
}
bool isVowel(char ch)
{
	ch = toupper(ch);
	return (ch == 'A' || ch =='E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int countVowels(std::string input, int n)
{
	if(n==1)
		return isVowel(input[n-1]);
	return countVowels(input, n-1) + isVowel(input[n-1]);
}

int main()
{
	string input;
	int n;
	int option=0;

	option = Menu();
	cin.ignore();
	
	while (option != 3)
	{
		switch(option)
		{
			case 1:
			{
				cout << "Enter a line : " << endl;
				getline(cin,input);
				
				
				cout << "You entered string: " << input<< endl;
				
				break;
			}
			case 2:
			{
				cout << "Number of vowels: " << countVowels(input, input.length())<<endl;
				break;
			}
		}
		option=Menu();
		cin.ignore();
	}
	return 0;
}


