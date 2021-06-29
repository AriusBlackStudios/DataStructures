// Name: Lillibeth Hunter and Jade Ainsworth
// Class: CS 3305
// Term: Summer 2021
// Instructor: Dr. Haddad
// Assignment: 4

#include <cassert>
#include <cctype>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	queue <char> q;
				stack<char> s;
				char letter;
				queue<char>::size_type mismatches = 0;
				
							queue <std::string> q_word;
			stack <std::string> s_word;
			std::string word;
			queue<std::string>::size_type word_mismatches = 0;
	int option;
	
	while(option != 3)
	{
	cout<< "Select an option: " << endl;
	cout << "1. Test character-by-character palindrome" << endl;
	cout << "2. Test word-by word palindrome: " << endl;
	cout << "3. Quit program " << endl;
	cin >> option;
	
		switch(option)
		{
			case 1:
			//option 1 variables
				cout << "Enter a line and I will see if it is a palindrome " << endl;
				do
				{
					cin >> letter;
					if(letter != '\n' && isalpha(letter))
					{
						q.push(toupper(letter));
						s.push(toupper(letter));
					}
				}while (cin.peek() != '\n');
				
				while((!q.empty()) && (!s.empty()))
				{
					if(q.front() != s. top())
							++mismatches;
						q.pop();
						s.pop();
				}
				if(mismatches == 0)
					cout<< "Is a Palindrome" << endl;
					else
						cout << "Not a palindrome" << endl;
				break;
				
			case 2:
			//option 2 variables
			//NOTE: same issue here, not sure how to implememt with words only
			
			cout << "Enter a line and I will see if it is a palindrome " << endl;
			
					do
					{
						cin >> word;
						std::transform(word.begin(), word.end(), word.begin(), ::toupper);
						q_word.push(word);
						s_word.push(word);
					}while (cin.peek( ) != '\n');
					
					while((!q_word.empty()) && (!s_word.empty()))
				{
					if(q_word.front() != s_word. top())
							++mismatches;
						q_word.pop();
						s_word.pop();
				}
				if(mismatches == 0)
					cout<< "Is a Palindrome" << endl;
					else
						cout << "Not a palindrome" << endl;
				break;
		}
	}
}

