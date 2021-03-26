#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "DLL2.h"
#include "DLL2.cpp"
using namespace std;

int main()
{
	DLL2<string> list1, list2;
	string name, job, answer;
	int listSize;
	

	cout << "How many names would you like in the list?\n";
	cin >> listSize;

	for (int i = 0; i < listSize; i++)
	{
		cout << "Give me a persons name to put in\n";
		cin >> name;
		cout << "Give me a job title to put in\n";
		cin >> job;
		list1.insertNode(name);
		list2.insertNode(job);
	}
	
	list1.print();
	cout<<endl;
	list2.print();
	cout<<endl;
	
	cout<< "is there a problem with the job assignments?\n";
	cin >> answer;
	if (answer == "yes"){
		list2.shift();
		list1.print();
		cout<<endl;
		list2.print();
	}
	
};


