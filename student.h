#include <string>
using namespace std;
class Student {
public:
	string name;
	string surname;
	int album_number;
	int group;
	int year;

    friend ifstream& operator>>(ifstream& input, Student& data) {
        input >> data.name >> data.surname >> data.album_number >> data.group >> data.year;
        return input;
    }

    friend ofstream& operator<<(ofstream& output, Student& data) {
        output << data.name << endl << data.surname<< endl << data.album_number<< endl << data.group << endl << data.year << endl;
        return output;
    }

    bool check(Student& data) {
        if (data.year == 3) 
            return true;
        else
            return false;
    }


};