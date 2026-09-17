# 🚀 C++ 4-Phase Project Roadmap

Welcome to the **C++ 4-Phase Project Roadmap** repository! This is a comprehensive, project-based learning and assessment track designed to bridge the gap between theoretical C++ syntax and practical production-grade software engineering.

## 📌 How to Use This Roadmap
1. **Sequential Progression**: Complete the projects in chronological order. Each phase introduces structural shifts in data layout and system architecture.
2. **Beyond "It Works"**: Do not advance to the next project simply because the program runs. 
3. **The Interview Test**: For every single project, ensure you can articulately explain its:
   * Architectural approach & code organization
   * Internal data structures & algorithms used
   * Time and space complexity ($O(N)$ analyses)
   * Edge cases handled (e.g., buffer overflows, type mismatches, empty states)

---

## 🛠️ Roadmap Breakdown

### 🟢 Phase 1 — Easy Projects
**Goal:** Solidify core language fundamentals, conditional execution, iterative blocks, elementary array/string manipulations, and basic Standard Template Library (STL) components.

*   **Project 1: Student Grade Manager**
    *   *Features:* Add students, input subject marks, calculate metrics (total, average, grade), evaluate extrema (highest/lowest marks), search and render student records.
    *   *Core Concepts:* `std::vector`, `std::string`, loops, functions, conditionals.
*   **Project 2: Number Guessing Game**
    *   *Features:* Pseudo-random number generation, dynamic attempt limits, high/low proximity hints, multi-tier difficulty levels, persistent scoring, replay loops.
    *   *Core Concepts:* Loops, boolean flags, functions, `<random>` or `<cstdlib>`.
*   **Project 3: Quiz Game**
    *   *Features:* Multiple-choice question engine (4 options), live tracking of correct/incorrect counts, cumulative score evaluation, isolated question categories.
    *   *Core Concepts:* Multidimensional arrays/vectors, structured text processing, loops.
*   **Project 4: Contact Book**
    *   *Features:* Full CRUD (Create, Read, Update, Delete) on contact entries, query lookups matching by name or primary phone digits.
    *   *Core Concepts:* `std::vector`, string parsing, linear search optimizations.
*   **🏆 Phase 1 Final Project: ATM System**
    *   *Features:* Secure PIN verification loop, real-time balance inquiries, validated deposits/withdrawals, peer-to-peer balance transfers, structured transaction log, runtime state mutations.
    *   *Focus:* Clean functional decomposition, input validation, strict state machine isolation.

---

### 🟡 Phase 2 — Medium Projects
**Goal:** Introduce advanced STL containers, pointers/references, memory-efficient passing, associative mapping collections, linear sorting pipelines, and intermediate problem-solving paradigms.

*   **Project 1: Library Management System**
    *   *Features:* Books lifecycle management (add/remove/find), checkout/return state pipelines, user profiles tracker, inventory availability flags.
    *   *Core Concepts:* `std::vector`, `std::map`, references (`&`) to avoid deep copies.
*   **Project 2: Inventory Management System**
    *   *Features:* Product catalogs (add/update/delete), stock mutations, custom sorting routines by cost metrics or item volume counts, extrema valuation extraction.
    *   *Core Concepts:* Compound structs/classes, `std::sort` with custom lambda comparators.
*   **Project 3: Bank Account Management**
    *   *Features:* On-the-fly bank account allocation, deposit/withdrawal/transfer transaction auditing, sequential transaction history generation.
    *   *Core Concepts:* Associative arrays (`std::map`, `std::unordered_map`) for $O(1)$ or $O(\log N)$ account queries.
*   **Project 4: Expense Tracker**
    *   *Features:* Monetary tracking (add/delete), category tagging, temporal aggregating (daily/monthly metrics), top-expense filtering, grouped category breakdowns.
    *   *Core Concepts:* Pair mappings, date extraction, floating-point precision safety.
*   **🏆 Phase 2 Final Project: E-Commerce Console App**
    *   *Features (Customer):* Product catalog browsing, item filtering, active shopping cart caching (add/remove), checkout loops, personal order logs.
    *   *Features (Admin):* CRUD operations on inventory global arrays, physical stock updates, comprehensive sales/order overview.

---

### 🔴 Phase 3 — Hard Projects
**Goal:** Deep dive into recursive algorithms, exhaustive state space backtracking, graph theories, algorithmic complexity optimization, and structural data visualization.

*   **Project 1: Maze Solver**
    *   *Features:* Two-dimensional grid parsing, definitive start-to-finish routing, recursive pathfinding, visited matrix state tracking, visual path rendering. *Extension:* Enumerate all valid paths.
    *   *Core Concepts:* Recursion, Backtracking, implicit Matrix representation.
*   **Project 2: Sudoku Solver**
    *   *Features:* Read an unfinished 9x9 board configuration, execute a brute-force recursive backtracking solver, enforce rapid constraint matrix validations.
    *   *Core Concepts:* 2D vectors, sub-grid hashing, recursive constraint pruning.
*   **Project 3: Path Finding System**
    *   *Features:* Configurable grid topologies with defined nodes (Start, End, Walls, Empty space), complete execution engines for Depth-First Search (DFS) and Breadth-First Search (BFS).
    *   *Theoretical Focus:* Compare traversal behaviors and explain why BFS guarantees the shortest path in unweighted environments.
*   **Project 4: Algorithm Visualizer**
    *   *Features:* Implement Linear/Binary searches alongside Bubble, Selection, Insertion, Merge, and Quick Sorts. Render stepwise array transformations, metrics for comparison counts, and explicit space/time Big-O analysis.
    *   *Core Concepts:* Divide-and-conquer mechanics, in-place vs out-of-place sorting memory overheads.
*   **🏆 Phase 3 Final Project: Route/Delivery Management System**
    *   *Features:* Node graphs for geographic layout locations, drivers arrays, delivery routing requests, automated shortest path scheduling, pending/completed state queues.
    *   *Core Concepts:* Adjacency lists/matrices, Graph Traversal algorithms (BFS/DFS, Dijkstra's variants).

---

### 🟣 Phase 4 — Advanced Projects
**Goal:** Transition from a C++ learner into a software architect. Build highly modular, encapsulated, exception-safe, object-oriented applications that utilize file persistence.

*   **Project 1: Hospital Management System**
    *   *Modules:* Patients registries, Doctors directory, dynamic Appointment schedules, Prescriptions writer, Billing sub-system. Includes binary or plain-text save/load state loops.
    *   *Core Concepts:* Object-Oriented Design (OOD), File I/O (`<fstream>`).
*   **Project 2: Advanced Banking System**
    *   *Features:* Account onboarding with secure credentials hashing, multi-tier account rules (Checking vs Savings inheritance models), robust Exception Handling (`try-catch` blocks), unique Transaction ID string generation, detailed financial statement exporting.
    *   *Core Concepts:* Polymorphism, standard exception subclasses, data persistence validation.
*   **Project 3: Mini File Management System**
    *   *Features:* Console-based shell to manage virtual directory spaces: create, delete, rename, search, list, move, and copy real or mock disk assets.
    *   *Core Concepts:* C++17/C++20 `<filesystem>` library integration.
*   **Project 4: Text Search Engine**
    *   *Features:* Crawl and parse multiple raw `.txt` source files, build an inverted index, process complex multi-word phrase queries, calculate and rank results by term frequency.
    *   *Core Concepts:* `std::unordered_map<std::string, std::vector<...>>`, custom ranking heuristics, string tokenizer algorithms.
*   **🏆 Phase 4 Final Project: Full Console E-Commerce System**
    *   *Architecture:* Enterprise tier separation using pure header (`.h`) and implementation (`.cpp`) files.
    *   *Customer Features:* Multi-factor authorization workflows, deeply nested category navigation, conditional price/rating sorting, real-time cart valuations, orders state machines.
    *   *Admin Features:* Dynamic supply-chain metrics dashboards, inventory triggers, analytical sales logs.
    *   *Technical Matrix Constraints:* Enforced use of modern **Object-Oriented Programming (OOP)**, **STL Containers**, **Smart Pointers** (`std::unique_ptr`/`std::shared_ptr`) for strict memory safety, **Custom Exceptions**, robust stream verification, and binary serialization.

---

## 📊 Final Development Checklist

| Skill | Expected Ability Standard |
| :--- | :--- |
| **Problem Solving** | Convert abstract business rules into programmatic logic matrices before writing code. |
| **Data Structures** | Select the optimal memory container (e.g., `vector` vs `list` vs `unordered_map`) and justify the selection. |
| **Algorithms** | Choose fast, scalable routines and defend structural execution decisions. |
| **Complexity** | Accurately compute Time and Space complexities ($O(1), O(\log N), O(N), O(N \log N), O(N^2)$). |
| **Debugging** | Trace down memory leaks, segment faults, logical calculation flaws, and execution anomalies. |
| **Code Organization** | Decouple massive source files into isolated, logical modules and clear abstract interfaces. |
| **Testing** | Validate software boundaries against normal profiles, boundary limits, and malformed inputs. |
| **Modification** | Pivot, refactor, and update existing codebases cleanly when product requirements change. |

---

## 🛠️ Local Development & Compilation

To build these projects locally using a standard compiler (like `g++`), execute the following commands inside the target project directory:

```bash
# Compile a modular Phase 4 project
g++ -std=c++17 main.cpp model.cpp controller.cpp -o AppExecutable

# Run the executable
./AppExecutable
```
**Author : Kalsoom
