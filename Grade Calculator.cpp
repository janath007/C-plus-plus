#include <iostream>
using namespace std;

// Function to calculate grade based on percentage
char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    if (percentage >= 80) return 'B';
    if (percentage >= 70) return 'C';
    if (percentage >= 60) return 'D';
    return 'F';
}

int main() {
    float marks[5];
    float total = 0;

    cout << "===== Student Grade Calculator =====\n\n";

    // Input marks for 5 subjects
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks for Subject " << i + 1 << " (0-100): ";
        cin >> marks[i];

        // Validate input
        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid marks entered! Try again.\n";
            i--; // repeat this subject input
            continue;
        }

        total += marks[i];
    }

    float percentage = total / 5.0;
    char grade = calculateGrade(percentage);

    // Output results
    cout << "\n===== Result =====\n";
    cout << "Total Marks: " << total << "/500\n";
    cout << "Percentage : " << percentage << "%\n";
    cout << "Grade      : " << grade << "\n";

    return 0;
}

