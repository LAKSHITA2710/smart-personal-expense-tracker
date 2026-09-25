# Smart Personal Expense Tracker

A simple, professional console-based **C++ project** for recording and analyzing personal expenses.

## Project Details

- **Project Type:** C++ Application Development
- **Project Start Date:** 1 September 2026
- **SDG Alignment:** SDG 12 – Responsible Consumption and Production
- **Student:** LAKSHITA

## Problem Statement

Students often record expenses manually, making it difficult to categorize spending, calculate totals, and understand spending patterns. This project provides a simple offline C++ application for recording, managing, searching, and summarizing personal expenses.

## Features

- Add new expenses
- View all recorded expenses
- Calculate total expenses
- Generate category-wise summaries
- Search expenses by category
- Save expense records locally
- Load saved records automatically when the program starts

## Concepts Used

- C++ structures
- Functions
- Vectors
- File handling
- Strings
- Searching
- Basic algorithms
- Formatted console output

## How to Run

### Using g++

```bash
g++ main.cpp -o expense_tracker
./expense_tracker
```

On Windows:

```bash
g++ main.cpp -o expense_tracker.exe
expense_tracker.exe
```

The program creates an `expenses.txt` file in the same directory to store records.

## Methodology

The application uses a menu-driven design. Each expense is stored as a structured record containing date, category, description, and amount. A vector maintains records during execution, while file handling provides persistent local storage. Separate functions handle input, display, calculations, summaries, and searching.

## Expected Outcome

A working offline expense tracker capable of maintaining expense records, calculating totals, and providing category-wise spending summaries.

## Outcome Achieved

The prototype successfully records, updates through persistent storage, searches, and summarizes expenses while demonstrating core C++ programming concepts.

## Sustainable Development Goal

The project aligns with **SDG 12 – Responsible Consumption and Production** by encouraging awareness of personal spending and responsible resource use through expense tracking.

## Project Structure

```text
smart-personal-expense-tracker/
├── main.cpp
├── PROJECT_REPORT.md
├── sample_data/          # Optional sample records
└── README.md
```

## Future Improvements

- Add a graphical user interface
- Add monthly charts and reports
- Add budget limits and alerts
- Export reports to CSV/PDF
- Add password protection

## License

This project is intended for educational and academic use.
