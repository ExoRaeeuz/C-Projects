#include "Task.H"

Task::Task(const std::string &desc, int prio) : description(desc), priority(prio) {} // Function Prtotype for the Tasks
std::string Task::getDescription() const                                             // Gets and Returns the description of the task
{
    return description;
}

int Task::getPriority() const
{ // Gets and Returns the Prioitiy level of the task
    return priority;
}

void Task::setDescription(const std::string &desc) // Allows to set the Deescrpition
{
    description = desc;
}

void Task::setPriority(int prio)
{ // Allows to Set Priority
    priority = prio;
}