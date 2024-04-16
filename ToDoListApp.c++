#include <iostream>
#include "Task.H"
#include "LinkedList.h"
// All of the HAHA FUNNNNNNNNNNY INCLUDES
using namespace std;

int main() // The Main Program
{
    LinkedList todoList;
    int choice;

    while (true)
    { // The list of stuff you can do on the list.
        cout << "\nTodo List Menu:" << endl;
        cout << "1. Insert a new Task." << endl;
        cout << "2. Remove a Task." << endl;
        cout << "3. Print Current Task." << endl;
        cout << "4. Save Task list to file." << endl;
        cout << "5. Load task list from file." << endl;
        cout << "6. Exit." << endl;
        cout << "What would you like to do?" << endl;
        cin >> choice;

        // A switch-break case for all options
        switch (choice)
        {
        case 1: // To add a new task
        {
            string desc;
            int prio;
            cout << "Enter task desription: ";
            cin.ignore();
            getline(cin, desc);
            cout << "Enter priority of the task (As an Integer): ";
            cin >> prio;
            Task newTask(desc, prio);
            todoList.insert(newTask);
            cout << "Task added." << endl;
            break;
        }
        case 2: // To take out a task based on index
        {
            int index;
            cout << "Enter the index of the task you want to remove: ";
            cin >> index;
            todoList.remove(index);
            break;
        }
        case 3: // Prints current tasks
            cout << "\nCurrent Tasks:" << endl;
            todoList.printTasks();
            break;

        case 4: // Saves to a file
        {
            string filename;
            cout << "Enter filename to save: ";
            cin.ignore();
            getline(cin, filename);
            todoList.saveToFile(filename);
            cout << "Task list saved to " << filename << endl;
            break;
        }

        case 5: // Loads to a file
        {
            string filename;
            cout << "Enter filename to load: ";
            cin.ignore();
            getline(cin, filename);
            todoList.loadFromFile(filename);
            cout << "Task list loaded from " << filename << endl;
            break;
        }
        case 6: // Program dies with a reutrn 0
            cout << "Exiting program." << endl;
            return 0;
        default: // If you want to be funny gices you the error nessage
            cout << "Invalid choice. PICK THE RIGHT ONE YOU DAFT BLIND MOTHER- ERROR." << endl;
        }
    }
    return 0;
}