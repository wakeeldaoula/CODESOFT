#include <iostream>
using namespace std;

struct Task
{
    string description;
    bool completed;
};

struct Node
{
    Task task;
    Node *next;
};

class ToDoListManager
{
private:
    Node *head;

public:
    ToDoListManager()
    {
        head = nullptr;
    }

    void addTask(const string &description)
    {
        Node *newNode = new Node;
        newNode->task.description = description;
        newNode->task.completed = false;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Task added successfully." << endl;
    }

    void viewTasks()
    {
        if (head == nullptr)
        {
            cout << "No tasks found." << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            cout << current->task.description << " - " << (current->task.completed ? "Completed" : "Pending") << endl;
            current = current->next;
        }
    }

    void markTaskAsCompleted(const string &description)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->task.description == description)
            {
                current->task.completed = true;
                cout << "Task marked as completed." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Task not found." << endl;
    }

    void removeTask(const string &description)
    {
        if (head == nullptr)
        {
            cout << "No tasks found." << endl;
            return;
        }

        if (head->task.description == description)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Task removed successfully." << endl;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->task.description == description)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "Task removed successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Task not found." << endl;
    }
};

int main()
{
    ToDoListManager manager;

    while (true)
    {
        cout << "\t\t\t***** TO-DO LIST MANAGER *****" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter task description: ";
            string description;
            cin.ignore();
            getline(cin, description);
            manager.addTask(description);
        }
        else if (choice == 2)
        {
            manager.viewTasks();
        }
        else if (choice == 3)
        {
            cout << "Enter task description: ";
            string description;
            cin.ignore();
            getline(cin, description);
            manager.markTaskAsCompleted(description);
        }
        else if (choice == 4)
        {
            cout << "Enter task description: ";
            string description;
            cin.ignore();
            getline(cin, description);
            manager.removeTask(description);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}