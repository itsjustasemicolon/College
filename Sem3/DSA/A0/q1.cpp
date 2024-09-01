#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name, address;
    int marks[5]; // assume 5 subjects
};

const int MAX_STUDENTS = 12;

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    while (true) {
        cout << "1. Add Student\n";
        cout << "2. Find Pass/Fail Students\n";
        cout << "3. Max Marks in Mathematics\n";
        cout << "4. Min Marks in Physics\n";
        cout << "5. Max Average Marks\n";
        cout << "6. Print Student Record\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";

        int option;
        cin >> option;

        switch (option) {
            case 1:// Add student record
                if (numStudents < MAX_STUDENTS) {
                    cout << "Enter name: ";
                    cin >> students[numStudents].name;
                    cout << "Enter address: ";
                    cin >> students[numStudents].address;
                    for (int i = 0; i < 5; i++) {
                        cout<<"1.mathematics, 2.physics, 3.chemistry, 4.english, 5.computer"<<endl;
                        cout << "Enter marks for subject " << i + 1 << ": ";
                        cin >> students[numStudents].marks[i];
                    }
                    numStudents++;
                } else {
                    cout << "Student database is full!\n";
                }
                break;
            case 2:
                // Find pass/fail students
                for (int i = 0; i < numStudents; i++) {
                    int passed = 0, failed = 0;
                    for (int j = 0; j < 5; j++) {
                        if (students[i].marks[j] >= 40) {
                            passed++;
                        } else {
                            failed++;
                        }
                    }
                    if (passed >= 3 || failed >= 3) {
                        cout << "Name: " << students[i].name << endl;
                        cout << "Address: " << students[i].address << endl;
                        cout << "Passed: " << passed << ", Failed: " << failed << endl;
                    }
                }
                break;
            case 3:
                // Max marks in Mathematics
                int maxMath, maxMathIndex;
                maxMath = 0;
                maxMathIndex = -1;
                for (int i = 0; i < numStudents; i++) {
                    if (students[i].marks[0] > maxMath) {
                        maxMath = students[i].marks[0];
                        maxMathIndex = i;
                    }
                }
                if (maxMathIndex != -1) {
                    cout << "Name: " << students[maxMathIndex].name << endl;
                    cout << "Address: " << students[maxMathIndex].address << endl;
                    cout << "Math Marks: " << maxMath << endl;
                }
                break;
            case 4:
                // Min marks in Physics
                int minPhysics, minPhysicsIndex;
                minPhysics=100;
                minPhysicsIndex=-1;
                for (int i = 0; i < numStudents; i++) {
                    if (students[i].marks[1] < minPhysics) {
                        minPhysics = students[i].marks[1];
                        minPhysicsIndex = i;
                    }
                }
                if (minPhysicsIndex != -1) {
                    cout << "Name: " << students[minPhysicsIndex].name << endl;
                    cout << "Address: " << students[minPhysicsIndex].address << endl;
                    cout << "Physics Marks: " << minPhysics << endl;
                }
                break;
            case 5:
                // Max average marks
                int maxAverage, maxAverageIndex;
                maxAverage = 0;
                maxAverageIndex = -1;
                for (int i = 0; i < numStudents; i++) {
                    int sum = 0;
                    for (int j = 0; j < 5; j++) {
                        sum += students[i].marks[j];
                    }
                    int average = sum / 5;
                    if (average > maxAverage) {
                        maxAverage = average;
                        maxAverageIndex = i;
                    }
                }
                if (maxAverageIndex != -1) {
                    cout << "Name: " << students[maxAverageIndex].name << endl;
                    cout << "Address: " << students[maxAverageIndex].address << endl;
                    cout << "Marks: ";
                    for (int i = 0; i < 5; i++) {
                        cout <<"marks of subject[i]"<< students[maxAverageIndex].marks[i] << " "<<endl;
                    }
                    cout<<"max avg marks is: "<<maxAverage;
                    cout << endl;
                }
                break;
            case 6://record of the student with name and total.
                char c[20];
                cout<<"enter name:";
                cin>>c;
                int i,j,sum;
                for (i=0;i<numStudents;i++){
                    if (students[i].name==c){
                        sum=0;
                        for (j=0;j<5;j++){
                            sum+=students[i].marks[j];
                        }
                    }
                }
                cout<<"the name is: "<<c<<" and the marks total is: "<<sum;
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}
