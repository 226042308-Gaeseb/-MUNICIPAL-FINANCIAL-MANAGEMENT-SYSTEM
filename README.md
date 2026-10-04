Municipal Financial Management system

Project: Project A – Municipal Financial Management System
Programming Language: ANSI C (C99)
Development Environment: Visual Studio Code + GCC
Version Control: Git & GitHub
Project Type: Group Project

No.	Name	Student Number	Responsibility
1	Gaeseb Toby	226042308	Testing, Documentation & Git Coordination
2	Amwaandangi Tadeus	226088588	Functions, Integration & Validation
3	Salmi Shaanika	226146359	Budget Management
4	Kampira Heather	226108953	Supplier Management
5	Makumbi Tapuwa	226134563	Employee Management
6	Chakanya Takudzwa	226013286	Reports
7	Hangula Dries	226135896	Asset Management

Project Description

The Municipal Financial Management System (MFMS) is a C-based application developed for PAP521S – Programming in Practice.
The purpose of the system is to provide a foundation for managing basic municipal financial information.
The system demonstrates the application of programming concepts covered during the first part of the course,
including variables, data types, input validation, decision-making, loops, arrays, strings, and functions
The system is designed as a foundation version that can be extended and improved in future project stages.

System Objectives

The main objectives of the system are to:

Develop a menu-driven C application.
Manage municipal employee information.
Manage departmental budgets and expenditure.
Manage supplier information.
Maintain a municipal asset register.
Generate basic financial and management reports.
Validate user input.
Demonstrate the use of arrays, strings, loops and functions.
Demonstrate collaborative software development using Git and GitHub.

System Features

Employee Management

The employee management module allows users to:
Add employees.
Display employees.
Search for employees.
Store employee information.
Calculate employee salary information.

Employee information may include:
Employee ID
Employee name
Department
Basic salary
Housing allowance
Transport allowance

Budget Management

The budget management module allows users to:
Enter departmental budgets.
Enter departmental expenditure.
Calculate remaining budget.
Determine whether expenditure is within budget.
Identify departments that have exceeded their allocated budget.
Display budget information.

Supplier Management
The supplier management module allows users to:
Add suppliers.
Display suppliers.
Search for suppliers.
Store supplier information.

Supplier information includes:
Supplier ID
Supplier name
Email
Telephone number
Town/Location

Asset Management
The asset management module provides a basic municipal asset register.

The system can store and display information such as:
Asset ID
Asset name
Asset type
Purchase value
Department
Condition

Examples of assets include vehicles, computers, buildings, equipment and office furniture.

Reports
The system provides basic reports including:
Employee Report
Budget Report
Supplier Report
Asset Report

The reports provide useful information such as employee salary statistics, total allocated budget, 
total expenditure, remaining budget and departments exceeding their budgets.


Main Menu

The system provides a menu-driven interface similar to:

========================================
MUNICIPAL FINANCIAL MANAGEMENT SYSTEM
========================================

1. Employee Management
2. Budget Management
3. Supplier Management
4. Asset Management
5. Reports
6. Exit

Enter your choice:
5. Technologies Used
C (C99) – Programming language
GCC – C compiler
Visual Studio Code – Development environment
Git – Version control
GitHub – Repository and team collaboration

6. Project Structure

The project is organised into separate source and header files:

MFMS/
│
├── main.c
├── employees.c
├── employees.h
├── budget.c
├── budget.h
├── suppliers.c
├── suppliers.h
├── assets.c
├── assets.h
├── reports.c
├── reports.h
└── README.md


7. Compilation Instructions

Make sure GCC is installed on your computer.

Open a terminal in the project directory and compile the program using:

gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o MFMS

If your project uses additional source files, include them in the compilation command.

8. How to Run the System

After successfully compiling the program, run it using:

Linux / Ubuntu
./MFMS
Windows
MFMS.exe

The main menu will appear, allowing the user to select the required module.

9. Input Validation

The system performs basic input validation to prevent invalid data.

Examples include:

Negative salaries are not accepted.
Negative budgets are not accepted.
Invalid menu choices are handled.
Empty names are handled appropriately.
Invalid numerical values are detected where possible.
10. C Programming Concepts Demonstrated

The project demonstrates the following C programming concepts:

Variables and data types
Input and output
Arithmetic operators
Relational operators
Logical operators
if statements
if-else statements
switch statements
Loops
Arrays
Strings
String functions
Functions
Parameters
Return values
Modular programming
Input validation




