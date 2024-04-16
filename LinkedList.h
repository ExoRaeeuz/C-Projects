#pragma once
#include "Task.H"

class LinkedList // Class Declaration RAHHHHHHHH
{
private: // Private, Cotains nodes that contains a task and a pointer to the next node
    struct Node
    {
        Task task;
        Node *next;
        Node(const Task &t) : task(t), next(nullptr) {} // Constructor Prototype, initialies the tasks, member with a given task, then sets the pounte to nullptr
    };
    Node *head; // Pointer to the irst node on the linked list
    int size;   // Keeps track of the size of the list

public:                                                 // PUBLIC DATA RAHHHHH WHAT IS PRIVATE INFORMATIONNNNNNNN
    LinkedList();                                       // The Constructor default to the linked list
    ~LinkedList();                                      // The Destructor to reallocate memory taken by the LL
    void insert(const Task &task);                      // Inserts a new task into the LL
    void remove(int index);                             // Removes a node at the certian index in the LL
    void printTasks() const;                            // Prints Tasks from the LL
    void clear();                                       // Clears the LL by detonating all nodes
    void saveToFile(const std::string &filename) const; // Saves to file with a given name
    void loadFromFile(const std::string &filename);     // Loads file with a given name
    int getSize() const;                                // Returns the size of the LL
};