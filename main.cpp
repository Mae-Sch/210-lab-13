#include <iostream>
#include <ifstram>

using namespace std;

const int MAX_LENGTH = 100;

struct Student{
    int ID;
    float grade;
}

void sortArray(Student*);

int main() {
    ifstream inFile("210-lab-13-grades.txt");

    if (!inFile.is_open) {
        cout << "Error: file was not opened successfully" << endl;
        return -1;
    }

    Student studentsList[MAX_LENGTH];

    while(!inFile.eof()) {
        static int i = 0;
        cin >> studentsList[i].ID;
        cin >> studentsList[i].grade;
        cin.ignore();
        i++;
    }

    return 1;
}

void sortArray(Student *list) {
    for (int i = 0; i < MAX_LENGTH - 1; ++i) {
      int lowest = i;
      for (int j = i + 1; j < MAX_LENGTH; ++j) {
         if ((list[j].ID < list[lowest].ID) && list[j].ID != 0) {
            lowest = j;
         }
      }
     Student temp = list[i];
     list[i] = list[lowest];
     list[lowest] = temp;
      
   }
}