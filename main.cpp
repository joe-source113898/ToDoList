#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define LIMIT_OF_TASKS 100

int generateAutoID()
{
  static int number = 0;
  return number++;
}

class ToDoList
{
  private:
    int autoID;
    string name;
    string dueDate;

  public:
    ToDoList(const string& name, const string& dueDate) : autoID(generateAutoID()), name(name), dueDate(dueDate) {}

    int getID() const { return autoID; }
    string getName() const { return name; }
    string getDueDate() const { return dueDate; }

    void displayTask() const
    {
      cout << "Task ID: " << autoID << " | Task name: " << name << " | Task due date: " << dueDate << endl;
    }
};

class ToDoListManager
{
  private:
    vector<ToDoList> toDoList;
    int counterOfTasks;

  public:
    ToDoListManager() : counterOfTasks(0) {}

    void addTask(const string& name, const string& dueDate)
    {
      if (counterOfTasks >= LIMIT_OF_TASKS)
      {
        cout << "The limit of tasks has been reached!" << endl;
        return;
      }

      toDoList.emplace_back(name, dueDate);
      counterOfTasks++;
      cout << "Task added successfully!" << endl;
    }

    void removeTask(const string& name)
    {
      for (auto it = toDoList.begin(); it != toDoList.end(); it++)
      {
        if (it->getName() == name)
        {
          toDoList.erase(it);
          counterOfTasks--;
          cout << "Task removed successfully!" << endl;
          return;
        }
      }
      cout << "Task not found." << endl;
    }

    void showAllTasks()
    {
      if (toDoList.empty())
      {
        cout << "There is not any task in the list yet!" << endl;
        return;
      }

      cout << "\nThe total of tasks is: " << counterOfTasks << endl;;
      for (const auto& task : toDoList)
      {
        task.displayTask();
      }
    }
};

int main()
{
  ToDoListManager tdlManager;
  int option;

  do
  {
    cout << "\nWelcome to To-Do-List application: \n";
    cout << "What do you want to perform?\n";
    cout << "1. Add a task to the list.\n";
    cout << "2. Remove a task from the list.\n";
    cout << "3. Show all the tasks int the list.\n";
    cout << "4. Exit the program.\n";
    cout << "Enter your option: ";
    cin >> option;
    cin.ignore();

    switch (option)
    {
      case 1:
      {
        string name, dueDate;

        cout << "\nEnter the name of the task: ";
        getline(cin, name);

        cout << "Enter the due of date in this format (dd/mm/yyyy): ";
        getline(cin, dueDate);

        tdlManager.addTask(name, dueDate);
        break;
      }
      case 2:
      {
        string name;
        cout << "\nEnter the name of the task: ";
        getline(cin, name);

        tdlManager.removeTask(name);
        break;
      }
      case 3:
        tdlManager.showAllTasks();
        break;
      case 4:
        cout << "Exiting the program!\nYou have exited successfully from the program!\n";
        break;
      default:
        cout << "Enter a valid option!\n";
    }
  } while(option != 4);

  return 0;
}
