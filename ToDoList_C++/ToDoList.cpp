#include "ToDoList.h"
#include <cstdlib> // For system() 
using namespace std;
void ToDoList::AddTask(const string& description, const string& dueDate)
{
	Task newTask = { nextId++,description,dueDate ,false };
	tasks.push_back(newTask);
    cout << "Task Added successfully\n";
}

void ToDoList::RemoveTask(int id)
{
    
    auto it = remove_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.id == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "\nTask deleted successfully!\n";
    }
    else {
        cout << "\nTask not found!\n";
    }
}

void ToDoList::MarkTaskAsCompleted(int id)
{
    for (auto& task : tasks) {
        if (task.id == id) {
            cout << "Done!\n";
            task.isCompleted = true;
            return;
        }
    }
    cout << "\nInvalid ID\n";
}
 

void ToDoList::Print()
{
    cout << "======== ToDoList ========" << endl;
    for (auto& task : tasks) {
        cout << "ID: " << task.id
            << "\nDescription: " << task.description
            << "\nDue Date: " << task.datetime
            << "\nCompleted: " << (task.isCompleted ? "Yes" : "No") << endl << endl;
    }
}


