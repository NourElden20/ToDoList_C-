#include "Application.h"
#include <vector>
#include <iostream>
#include "Task.h"
#include "ToDoList.h"
using namespace std;

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Application::MainMenu(ToDoList list)
{
    char choice;
    do {       
        cout << "======== ToDoList App ========" << endl;
        cout << "1)Show My list" << endl;
        cout << "2)Add to list" << endl;
        cout << "3)Remove from list" << endl;
        cout << "4)Complete task" << endl;
        cout << "5)Exit" << endl << endl;

    Select:
        cout << "Enter your choice: ";
        cin >> choice;


        string description;string date;int id;
        switch (choice) {
        case '1':
            list.Print();
            cout << "\nContinue ? || Y or N\n";
            char c;cin >> c;
            if (tolower(c) == 'y') {
                clearScreen();
                break;
            }
            else {
               cout << "\nThank You";
               return;
            }
            break;
        case '2':
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter the description of the task\n";
            getline(cin, description);
            
            cout << "Enter the date of the task\n";
            getline(cin, date);
            list.AddTask(description, date);
            break;
        case '3':
            cout << "Enter the id of the task: ";
            cin >> id;
            list.RemoveTask(id);
            break;
        case '4':
            cout << "Enter the id of the task: ";
            cin >> id;
            list.MarkTaskAsCompleted(id);
        case '5':
            cout << "Thank You";
            break;
        default:
            cout << "invalid input, Try again";
            goto Select;
        }
        cout << "\n";
    } while (choice != '5');
}


void Application::RunApplication()
{ 
    ToDoList list;
    MainMenu(list);
}
