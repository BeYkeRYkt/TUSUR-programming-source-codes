﻿#include "Note.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int noteSize = 8;
Note* notes = new Note[noteSize];

void inputNote(int index){
	cin.clear(); //fix
	cout << "Person #" << (index + 1) << ": " << std::endl;
	cout << "Input family name: ";

	string family = "NULLABLE";
	cin >> family;
	notes[index].setFamilyName(family);

	cout << "Input name: ";
	string name = "NULL";
	cin >> name;
	notes[index].setName(name);

	cout << "Input the birthday: ";
	int* date = new int[3];
	for (int j = 0; j < 3; j++) {
		cin >> date[j];
	}
	notes[index].setDate(date);

	cout << "Input the phone number: ";
	int phone;
	cin >> phone;
	notes[index].setPhoneNumber(phone);
	cout << endl;
}

void inputInformation()
{
	for (int i = 0; i < noteSize; i++) {
		inputNote(i);
	}
}

void search(int month){
	for (int i = 0; i < noteSize; i++){
		if (notes[i].getDate()[1] == month){
			cout << notes[i].getFamilyName() << " " << notes[i].getName() << " " << notes[i].getPhoneNumber() << " ";
			cout << notes[i].getDate()[0] << ".";
			cout << notes[i].getDate()[1] << ".";
			cout << notes[i].getDate()[2] << endl;
		}
	}
}

int main(){
	bool run = true;
	while (run){
		cin.clear(); //fix
		cout << "0. Exit" << endl << endl;
		cout << "1. Create 8 notes" << endl;
		cout << "2. Create note in index" << endl;
		cout << "3. Search note from month" << endl;
		cout << endl << "--> ";

		int code = 0;
		cin >> code;

		switch (code){
		case 0:
			run = false;
			break;
		case 1:
			inputInformation();
			break;
		case 2:{
				   int index = 0;
				   cout << "Index: ";
				   cin >> index;
				   inputNote(index - 1);
				   break;
		}
		case 3:{
				   int month = 0;
				   cout << "Month: ";
				   cin >> month;
				   search(month);
				   break;
		}
		default:
			cout << "Unknown command" << endl;
			break;
		}
	}
	return 0;
}