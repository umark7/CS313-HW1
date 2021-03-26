#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "DLL1.h"
#include "DLL1.cpp"
using namespace std;

int main(){
	
	DLL1<double> appointments;
	string day, answer;
	double dayChosen = 0, begin = 0, end = 0;
	double deleteDay=0, deleteTime=0;
	double monday = 0;
	double tuesday = 1;
	double wednesday = 2;
	double thursday = 3;
	double friday = 4;
	bool deleteAppointment = false;
	bool addAppointment = false;
	
	cout<<"welcome to google, we are open monday-friday, 9AM-5PM\n";
	cout<<"please enter the day of the appointment, the time it begins and time it ends\n";
	cin>> day;
	cin>> begin;
	cin>> end;
	
	if(day == "monday"){
		dayChosen = monday;
	}
	else if(day == "tuesday"){
		dayChosen = tuesday;
	}
	else if(day == "wednesday"){
		dayChosen = wednesday;
	}
	else if(day == "thursday"){
		dayChosen = thursday;
	}
	else if(day == "friday"){
		dayChosen = friday;
	}
	else{
		cout << "an invalid day was entered\n";
	}
	
	appointments.insert(dayChosen, begin, end);
	
	cout<<"would you like to add another appointment?";
	cin >> answer; 
	
	if(answer == "yes") addAppointment=true;
	while(addAppointment){
		cout<<"please enter the day of the appointment, the time it begins and time it ends\n";
		cin>> day;
		cin>> begin;
		cin>> end;
		
		if(day == "monday"){
		dayChosen = monday;
		}
	
		else if(day == "tuesday"){
		dayChosen = tuesday;
		}
	
		else if(day == "wednesday"){
		dayChosen = wednesday;
		}
	
		else if(day == "thursday"){
		dayChosen = thursday;
		}
	
		else if(day == "friday"){
		dayChosen = friday;
		}
	
		else{
		cout << "an invalid day was entered\n";
		}
	
	    appointments.insert(dayChosen, begin, end);
	    
	    cout<<"would you like to add another appointment?";
		cin >> answer;
	
		if(answer == "yes") addAppointment=true;
		else addAppointment=false;
	
	}
	
	
	cout<< "would you like to delete your appointment?";
	cin>> answer;
	
	if(answer == "yes"){
		deleteAppointment = true;
	}
	if(deleteAppointment == true){
		cout<< "please enter appointment day?";
		cin>>deleteDay;
		cout<< "please enter the time the appointment begins?";
		cin>>deleteTime;
		appointments.deleteAppointment(deleteDay, deleteTime);
	}
	
};
	


