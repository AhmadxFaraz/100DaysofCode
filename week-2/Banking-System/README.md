<h1><u>Command-Line-Bank in C++</u></h1>

<p>A command-line banking system built in C++... supports account creation,
deposits, withdrawals, and tracking your transaction history on txt file... and reading from it to dispaly your transaction histroy.</p>

## Features
- Lets user create new account, with his name & inital amount to deposit...
- Lets user deposit & withdraw money in his/her existing account, with Account Number as logging ID(unique)...
- Stores data in a "customer-data.txt" file for recording and saving for later access...
- Uses timestamps for tracking transaction history with time & date...
- Lets user view his/her transaction history by logging with Account Number...
- Validates input entered by user...

## How to Run
1. Clone the repository
2. Compile using a C++ compiler 
   `g++ Command-Line-Bank.cpp -o Command-Line-Bank`
3. Run the executable  
   `./Command-Line-Bank`
4. Follow the on-screen menu

## Design Decisions
- Account data is loaded at startup and kept in memory as the single source of truth.
- Account numbers act as unique IDs, not direct vector indices.
- Transaction history is append-only and stored separately for clean auditing.

## What I Learned
This project showed me how real systems juggle state,
why leaning on raw indices is a recipe for chaos,
and how file-based persistence can completely reshape a program’s design. 
It also sharpened my instincts for spotting tricky edge cases and thinking clearly about correctness.

## Future Improvements
- Support multi-word names
- Improve input validation further
- Add Exception Handling for errors
- Add derived Classes for different types of Accounts

## Author
Ahmad Faraz  
Computer Engineering Student, ZHCET, AMU.