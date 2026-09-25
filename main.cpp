#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

struct Expense {
    string date;
    string category;
    string description;
    double amount;
};

vector<Expense> expenses;
const string FILE_NAME = "expenses.txt";

void saveData() {
    ofstream file(FILE_NAME);
    for (const auto& e : expenses)
        file << e.date << '|' << e.category << '|' << e.description << '|' << e.amount << '\n';
}

void loadData() {
    ifstream file(FILE_NAME);
    Expense e;
    string amount;
    while (getline(file, e.date, '|') && getline(file, e.category, '|') &&
           getline(file, e.description, '|') && getline(file, amount)) {
        try {
            e.amount = stod(amount);
            expenses.push_back(e);
        } catch (...) {
            // Ignore malformed records.
        }
    }
}

void addExpense() {
    Expense e;
    cout << "Date (DD-MM-YYYY): ";
    cin >> e.date;
    cin.ignore();
    cout << "Category: ";
    getline(cin, e.category);
    cout << "Description: ";
    getline(cin, e.description);
    cout << "Amount: Rs. ";
    cin >> e.amount;
    expenses.push_back(e);
    saveData();
    cout << "Expense added successfully.\n";
}

void viewExpenses() {
    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }
    cout << "\n" << left << setw(14) << "Date" << setw(18) << "Category"
         << setw(30) << "Description" << right << setw(12) << "Amount" << '\n';
    cout << string(74, '-') << '\n';
    for (const auto& e : expenses)
        cout << left << setw(14) << e.date << setw(18) << e.category
             << setw(30) << e.description << right << setw(12) << fixed << setprecision(2) << e.amount << '\n';
}

void totalExpenses() {
    double total = 0;
    for (const auto& e : expenses) total += e.amount;
    cout << "Total expenses: Rs. " << fixed << setprecision(2) << total << '\n';
}

void categorySummary() {
    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }
    vector<pair<string, double>> summary;
    for (const auto& e : expenses) {
        auto it = find_if(summary.begin(), summary.end(), [&](const auto& p) { return p.first == e.category; });
        if (it == summary.end()) summary.push_back({e.category, e.amount});
        else it->second += e.amount;
    }
    cout << "\nCategory-wise summary:\n";
    for (const auto& p : summary)
        cout << "- " << p.first << ": Rs. " << fixed << setprecision(2) << p.second << '\n';
}

void searchExpenses() {
    cin.ignore();
    string category;
    cout << "Enter category to search: ";
    getline(cin, category);
    bool found = false;
    for (const auto& e : expenses) {
        if (e.category == category) {
            cout << e.date << " | " << e.description << " | Rs. " << fixed << setprecision(2) << e.amount << '\n';
            found = true;
        }
    }
    if (!found) cout << "No expenses found in this category.\n";
}

int main() {
    loadData();
    int choice;
    do {
        cout << "\n===== Smart Personal Expense Tracker =====\n"
             << "1. Add Expense\n2. View Expenses\n3. Total Expenses\n"
             << "4. Category Summary\n5. Search by Category\n6. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalExpenses(); break;
            case 4: categorySummary(); break;
            case 5: searchExpenses(); break;
            case 6: cout << "Thank you for using the Expense Tracker.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}
