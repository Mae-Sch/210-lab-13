#include <iostream>
#include <ifstram>

using namespace std;

struct Student{
    int ID;
    float grade;
}

int main() {
    ifstream inFile("210-lab-13-grades.txt");

    if (!inFile.is_open) {
        cout << "Error: file was not opened successfully" << endl;
        return -1;
    }

    Student studentsList[100];

    while(!inFile.eof()) {
        static int i = 0;
        cin >> studentsList[i].ID;
        cin >> studentsList[i].grade;
        cin.ignore;
    }

    return 1;
}