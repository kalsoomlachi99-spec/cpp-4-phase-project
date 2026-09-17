#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Add one student
void addStudents(vector <string> &studentsName){ //TC : O(n), SC : O(n) 
    string name;
    cout << "Enter the name of student : ";
    getline(cin, name);
    studentsName.push_back(name);
}

// Get marks for one student
vector <double> getMarks(int noOfSub){ //TC : O(n), SC : O(n) 
    vector <double> marks;

    for (int i = 0; i < noOfSub; i++){
        cout << "Enter marks of subject " << i + 1 << ": ";
        double mark;
        cin >> mark;
        marks.push_back(mark);
    }

    return marks;
}

// Calculate total marks
double total(const vector<double>& marks){ //TC : O(n), SC : O(1)
    double totalMarks = 0;
    
    for (int i = 0; i < marks.size(); i++){
        totalMarks += marks[i];
    }

    return totalMarks;
}

// Calculate average marks
double average(const vector<double>& marks){ //TC : O(n), SC : O(1)
   return total(marks) / marks.size();
}

// Determine grade based on average marks
char grade(const vector<double>& marks){ //TC : O(n), SC : O(1)
    double avg = average(marks);

    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

// Find highest mark
double highestMarks(const vector <double>& marks){ //TC : O(n), SC : O(1)
    double highest = marks[0];

    for (int i = 1; i < marks.size(); i++){
        if (marks[i] > highest){
            highest = marks[i];
        }
    }

    return highest;
}

// Find lowest mark
double lowestMarks(const vector <double>& marks){ //TC : O(n), SC : O(1)
    double lowest = marks[0];

    for (int i = 1; i < marks.size(); i++){
        if (marks[i] < lowest){
            lowest = marks[i];
        }
    }

    return lowest;
}

// Search for a student by name
int searchStudent(const string& searchingStudent, const vector<string>& studentsName){ //TC : O(n), SC : O(1)
    
    for (int i = 0; i < studentsName.size(); i++){
        if (studentsName[i] == searchingStudent){
            return i;
        }
    }

    return -1; // Return -1 if the student is not found
}

// Display all students
void allStudents(const vector<string>& studentsName){ //TC : O(n), SC : O(1)
    cout << "\nList of all students: \n" << endl;

    for (const auto& name : studentsName){
        cout << name << endl;
    }
}

int main() {
    
    // Number of students
    int noOfStudents;

    cout << "Enter the number of students: ";
    cin >> noOfStudents;
    cin.ignore(); 

    if(noOfStudents <= 0) { // edge case: if the number of students is less than or equal to 0
        cout << "Number of students must be greater than 0." << endl;
        return 1; // Exit the program with an error code
    }

    //Add Students
    vector<string> studentsName;

    for (int i = 0; i < noOfStudents; i++) {
        addStudents(studentsName);
    }

    // Display all students
    allStudents(studentsName);

    // Number of subjects
    int noOfSub;

    cout << "\nEnter no of subjects: ";
    cin >> noOfSub;

    if(noOfSub <= 0) {
        cout << "Number of subjects must be greater than 0." << endl;
        return 1;
    }

    // Get marks and display results for each student
    for (int i = 0; i < noOfStudents; i++) { 

        cout << "\n====== " << studentsName[i] << " =======\n";
        
        vector<double> marks = getMarks(noOfSub);

        double totalMarks = total(marks); 
        double avgMarks = average(marks); 
        char studentGrade = grade(marks); 
        double highest = highestMarks(marks); 
        double lowest = lowestMarks(marks); 

        cout << "\nTotal Marks: " << totalMarks << endl; 
        cout << "Average Marks: " << avgMarks << endl; 
        cout << "Grade: " << studentGrade << endl; 
        cout << "Highest Marks: " << highest << endl; 
        cout << "Lowest Marks: " << lowest << endl;
    }
         
    return 0;
}
