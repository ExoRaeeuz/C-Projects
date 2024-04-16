#include "LinkedList.h"
#include <fstream>
#include <iostream>

LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::insert(const Task &task)
{
    Node *newNode = new Node(task);
    newNode->next = head;
    head = newNode;
    size++;
}

void LinkedList::remove(int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Invalid Index." << std::endl;
        return;
    }
    Node *current = head;
    if (index == 0)
    {
        head = head->next;
        delete current;
        size--;
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
}

void LinkedList::printTasks() const
{
    Node *current = head;
    int taskNum = 0;
    while (current != nullptr)
    {
        std::cout << "[" << taskNum << "] Priority: " << current->task.getPriority() << "-" << current->task.getDescription() << std::endl;
        current = current->next;
        taskNum++;
    }
}

void LinkedList::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

void LinkedList::saveToFile(const std::string &filename) const
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Unable to open File." << std::endl;
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        file << current->task.getPriority() << " " << current->task.getDescription() << std::endl;
    }
    file.close();
}

void LinkedList::loadFromFile(const std::string &filename)
{
    clear();
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Unable to open file." << std::endl;
        return;
    }

    int prio;
    std::string desc;
    while (file >> prio)
    {
        getline(file >> std::ws, desc);
        Task task(desc, prio);
        insert(task);
    }
    file.close();
}
int LinkedList::getSize() const
{
    return size;
}