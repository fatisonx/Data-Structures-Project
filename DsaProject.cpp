#include <iostream>
using namespace std;

 

struct Student {
    string name;   //this is the data
    int id;  //this is the data
    float gpa;   //this is the data
    string major;   //this is the data
    Student* next;  //this is the pointer
};

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


void SearchStudent(Student* &head){
    int id;
    cout<<"Enter Student's ID to look up: ";
    cin>>id;

    if(head == NULL){  //checking if the list is empty. 
        cout<<"There Are no students registered. ";
    }
    Student* temp = head;
    
    if(temp->id == id){  //at head node
        cout<<"Student Found. ";
    }
    else if()  //at the next node
}
 

 

int main() {
    Student* head = NULL;  //this is the head
    Student* tail = NULL;  //this is the tail

    int choice;
    
    do {
        cout << "      Student Management System      \n";
        cout << "---–---------------------------------\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Delete Student by ID\n";
        cout << "4. Edit Student by ID\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "---------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                deleteStudent();
                break;

            case 4:
                editStudent();
                break;

            case 5:
                displayAllStudents();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);
   return 0;
}