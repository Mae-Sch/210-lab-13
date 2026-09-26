#include <iostream>
#include <fstream>

using namespace std;

const int MAX_LENGTH = 300;

struct Student{
    int ID;
    float grade;
};

void sortArray(Student*);

int main() {
    ifstream inFile("210-lab-13-grades.txt");

    if (!inFile.is_open()) {
        cout << "Error: input file was not opened successfully" << endl;
        return -1;
    }

    Student studentsList[MAX_LENGTH];

    while(!inFile.eof()) {
        static int i = 0;
        inFile >> studentsList[i].ID;
        inFile >> studentsList[i].grade;
        inFile.ignore();
        i++;
    }

    inFile.close();

    sortArray(studentsList);

    ofstream outFile("210-lab-13-sorted-grades.txt");

    if (!outFile.is_open()) {
        cout << "Error: output file was not opened successfully" << endl;
        return -1;
    }

    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (studentsList[i].ID == 0)
            break;
        if ((studentsList[i].ID > 0) && (studentsList[i].grade > 0.1))
            outFile << studentsList[i].ID << " " << studentsList[i].grade << endl;
    }

    outFile.close();
    return 1;
}

void sortArray(Student *list) {
    for (int i = 0; i < MAX_LENGTH - 1; ++i) {
      int lowest = i;
      if (list[i].ID == 0)
        break;
      for (int j = i + 1; j < MAX_LENGTH; ++j) {
        if (list[j].ID == 0)
            break;
         if (list[j].ID < list[lowest].ID) {
            lowest = j;
         }
      }
    // "=" operator is not definited for struct student so we have to set each member individually
        Student temp;
        temp.ID = list[i].ID;
        temp.grade = list[i].grade;
        list[i].ID = list[lowest].ID;
        list[i].grade = list[lowest].grade;
        list[lowest].ID = temp.ID;
        list[lowest].grade = temp.grade;
   }
}