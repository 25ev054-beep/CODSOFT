#include <windows.h>

// tell compiler that main() exists
int main();

// Windows entry point
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> tasks;
    vector<bool> completed;
    int choice;

    do {
        cout << "\n📋 TO-DO LIST MENU\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string task;
            cin.ignore();
            cout << "Enter task: ";
            getline(cin, task);
            tasks.push_back(task);
            completed.push_back(false);
            cout << "Task added successfully!\n";
        }

        else if (choice == 2) {
            cout << "\nYour Tasks:\n";
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i];
                if (completed[i])
                    cout << " ✔";
                cout << endl;
            }
        }

        else if (choice == 3) {
            int num;
            cout << "Enter task number to mark completed: ";
            cin >> num;
            completed[num - 1] = true;
            cout << "Task marked as completed!\n";
        }

        else if (choice == 4) {
            int num;
            cout << "Enter task number to remove: ";
            cin >> num;
            tasks.erase(tasks.begin() + num - 1);
            completed.erase(completed.begin() + num - 1);
            cout << "Task removed successfully!\n";
        }

    } while (choice != 5);

    return 0;
}
