#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int MAX_LENGTH = 300;

struct Student{
    int ID;
    float grade;
};

void sortArray(Student*);
void displayStats(Student*);

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
    displayStats(studentsList);

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

void displayStats(Student* list) {
    // find min score
    int minIndex = 0;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        if ((list[i].grade < list[minIndex].grade) && (list[i].grade > 1) && (list[i].ID > 0))
            minIndex = i;
    }

    // find max score
    int maxIndex = 0;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (list[i].grade > list[minIndex].grade && (list[i].ID > 0))
            maxIndex = i;
    }

    int length = 0;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (list[i].grade > 1 && (list[i].ID > 0)) {
            length++;
        }
    }

    float total = 0;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        if (list[i].grade > 1 && (list[i].ID > 0)) {
            total += list[i].grade;
        }
    }

    float mean = total / length;
    int medianIndex = length / 2;

    float variance = 0;
    for (int i = 0; i < length; ++i) {
        variance += (list[i].grade - mean) * (list[i].grade - mean);
    }
    variance = variance / (length - 1);

    float deviation = sqrt(variance);

    // Output code
    cout << "Minimum Score: " << list[minIndex].grade << " by student: " << list[minIndex].ID << endl;
    cout << "Maximum Score: " << list[maxIndex].grade << " by student: " << list[maxIndex].ID << endl;
    cout << "Mean Score: " << mean << " (despite it's name, the score is quite nicies)" << endl;
    cout << "Median Score: " << list[medianIndex].grade << " by student: " << list[medianIndex].ID << endl;
    cout << "Standard Deviation: " << deviation << endl;
}