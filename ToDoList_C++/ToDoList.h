#pragma once
#include <vector>
#include <iostream>
#include "Task.h"

using namespace std;

class ToDoList
{
private:
	vector<Task> tasks;
	int nextId;
public:
	ToDoList():nextId(1){}

	void AddTask(const string& description, const string& dueDate);
	void RemoveTask(int id);
	void MarkTaskAsCompleted(int id);
	void Print();

	

};

