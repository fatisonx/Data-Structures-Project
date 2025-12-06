#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;   //this is the data
    int id;  //this is the data
    float gpa;   //this is the data
    string major;   //this is the data
    Student* next;  //this is the pointer
};

Student* head = NULL;
void addStudent() {
    Student* temp = new Student;


    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, temp->name);

    cout << "Enter student ID: ";
    cin >> temp->id;

    cout << "Enter student GPA: ";
    cin >> temp->gpa;

    cin.ignore(); 
    cout << "Enter student major: ";
    getline(cin, temp->major);

    
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } 
    else {
        Student* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }

    cout << "Student added successfully!\n";
}

void deleteStudent(Student*& head) {
    int id;
    cout << "Enter Student ID to delete: "; 
    cin >> id;

    if (head == NULL) {   //empty list
       cout << "Student not found.\n";
       return;
    }
    if (head->id == id) {   //deleting the head node
       Student* temp = head;
       head = head->next;
       delete temp;
       cout << "Student deleted successfully.\n";
       return;
    }

    Student* current = head;   //initilizing traversal
   
    while (current->next != NULL && current->next->id != id) {   //checking if its the next/middle node
       current = current->next;
    }

    if (current->next == NULL) {   //end of the list reached
       cout << "Student not found.\n";
       return;
    }

    Student* temp = current->next;
    current->next = temp->next;
    delete temp;

    cout << "Student deleted successfully.\n";
}


void searchStudent(Student* &head){
    int id;
    cout<<"Enter Student's ID to look up: ";
    cin>>id;

    if(head == NULL){  //checking if the list is empty. 
        cout<<"There Are no students registered. ";
        return;
    }
    Student* temp = head;
    
    
    while(temp != NULL ){  //traversing in the list
        if(temp->id == id){
        cout<<"Student Found. ";
        cout<<"Name: "<<temp->name<<endl;
        cout<<"ID: "<<temp->id<<endl;
        cout<<"GPA: "<<temp->gpa<<endl;
        cout<<"Major: "<<temp->major<<endl;
        return;
        }
        temp = temp->next;
    } 
    cout << "Student not found.";
}
 
void displayAllStudents() {
    if (head == NULL) {
        cout << "No students to display.\n";
        return;
    }

    Student* cur = head;
    int i = 1;

    while (cur != NULL) {
        cout << i << ": " << cur->name << "  ID: " << cur->id
             << "  GPA: " << cur->gpa << "  Major: " << cur->major << endl;

        cur = cur->next;
        i++;
    }
}
 

int main() {
    int choice;
    Student* head = NULL;
    Student* tail = NULL;

    do {
    
    cout << "      Student Management System      \n";
    cout << "---–---------------------------------\n";
    cout << "1. Add Student\n";
    cout << "2. Search Student by ID\n";
    cout << "3. Delete Student by ID\n";
    cout << "4. Display All Students\n";
    cout << "5. Exit\n";
    cout << "---------------------------------\n";
    cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                searchStudent(head);
                break;

            case 3:
                deleteStudent(head);
                break;

            case 4:
                displayAllStudents();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
