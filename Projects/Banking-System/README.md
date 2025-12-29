<h1><u>Command-Line-Bank in C++</u></h1>

<p>A console-based banking system built in C++ that supports account creation,
deposits, withdrawals, and transaction history using file-based persistence.
The project focuses on correct system design rather than UI complexity.</p>

## Features
- Create and manage bank accounts
- Deposit and withdraw money
- Persistent account storage using files
- Transaction history with timestamps
- Safe account lookup using account numbers
- Input validation for user interaction

## How to Run
1. Clone the repository
2. Compile using a C++11 or later compiler  
   `g++ main.cpp -o banking-system`
3. Run the executable  
   `./banking-system`
4. Follow the on-screen menu

## Design Decisions
- Account data is loaded into memory at program start and treated as the
  single source of truth.
- Account numbers are treated as unique identifiers and are not mapped
  directly to vector indices.
- Transaction history is append-only and stored separately from account data
  to preserve auditability.

## What I Learned
This project helped me understand how real systems manage state, why relying
on indices is fragile, and how file-based persistence changes program design.
It also improved my ability to reason about correctness and edge cases.

## Future Improvements
- Support multi-word names
- Improve input validation further
- Migrate persistence to a database (e.g., SQLite)

## Author
Ahmad Faraz  
Computer Engineering Student, ZHCET, AMU.