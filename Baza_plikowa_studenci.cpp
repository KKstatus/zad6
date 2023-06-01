#include <iostream>
#include <fstream>
#include "student.h"
#include <algorithm> 
#include <vector>

using namespace std;
int main()
{
	ifstream file("info.txt");
	
	Student obj1;
	vector<Student> students;

	while (file >> obj1) {
		students.push_back(obj1); // wczytanie listy studentow z pliku do vektora
	}
	file.close();

	cout << "         Wszyscy studneci        " << endl << endl;
	cout << "Imie Nazwisko Nr Albumu Grupa Rok" << endl << endl;

	// lambda i wyswietlenie wszystkich studentow
	for_each(students.begin(), students.end(), [](Student student1) {
		cout << student1.name << " " << student1.surname << " " << student1.album_number << " " << student1.group << " " << student1.year << " " << endl;
		});

	// zliczanie studentow 3 roku
	int year3 = count_if(students.begin(), students.end(), [](Student student1) {
		return student1.year == 3;
		});

	cout << endl << endl << "Ilosc wszyskitch studentow 3 roku = " << year3 << endl;


	ofstream save("info.txt");

	for (auto student : students) {
		save << student << endl;
	}

	save.close();
	


	return 0;
}
	