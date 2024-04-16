#pragma once
#include <string>

class Task
{
private: // Private Class to set level of priority
    std::string description;
    int priority;

public: // Public Class to set Descriptions for tasks, the prioirty and setting the level of prio
    Task(const std::string &desc, int prio);
    std::string getDescription() const;
    int getPriority() const;
    void setDescription(const std::string &desc);
    void setPriority(int prio);
};