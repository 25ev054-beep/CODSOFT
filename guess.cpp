#include <windows.h>

// tell compiler that main() exists
int main();

// Windows entry point
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess;

    cout << "🎯 Number Guessing Game\n";
    cout << "Guess a number between 1 and 100\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > number)
            cout << "Too High!\n";
        else if (guess < number)
            cout << "Too Low!\n";
        else
            cout << "🎉 Correct Guess!\n";

    } while (guess != number);

    return 0;
}
