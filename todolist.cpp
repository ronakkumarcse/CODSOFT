#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool isCompleted;
};

void showMenu() {
    cout << "\n========= TO-DO LIST MENU =========\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task \n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

void addTask(vector<Task> &tasks) {
    Task t;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, t.name);
    t.isCompleted = false;
    tasks.push_back(t);
    cout << " Task added successfully!\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet!\n";
        return;
    }
    cout << "\nYour To-Do List:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].name
             << (tasks[i].isCompleted ? " ✔ (Done)" : " (Pending)") << endl;
    }
}

void markCompleted(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);
    cout << "\nEnter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks[index - 1].isCompleted = true;
    cout << " Task marked as completed!\n";
}

void deleteTask(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);
    cout << "\nEnter task number to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "🗑 Task deleted successfully!\n";
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markCompleted(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: cout << " Have a productive day!\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}