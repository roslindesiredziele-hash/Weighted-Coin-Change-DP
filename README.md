# Overencumbered Inventory

A C++ implementation of a Dynamic Programming solution to the weighted coin change problem. The project helps Geralt the Witcher collect a target amount of ancient elvish coins while minimizing the total weight carried.

## Overview

Geralt is rewarded with ancient elvish coins after completing a monster-hunting quest.

Each coin denomination has:

- A monetary value.
- A physical weight.

The objective is to obtain a target amount while minimizing the total weight of coins carried.

This problem is solved using Dynamic Programming.

---

## Problem Statement

Given:

```text
A
```

a target amount and a set of coin types:

```text
(value1, weight1)
(value2, weight2)
...
(valuen, weightn)
```

find a combination of coins whose total value equals:

```text
A
```

while minimizing the total weight.

Example:

| Value | Weight |
|---------|---------:|
| 1 | 10 |
| 2 | 5 |
| 5 | 2 |

Target:

```text
10
```

Possible solution:

```text
1+1+1+1+1+1+1+1+1+1
```

Weight:

```text
100
```

Optimal solution:

```text
5+5
```

Weight:

```text
4
```

---

## Data Structure

Each coin is represented by:

```cpp
struct Coin
{
    int value;
    int weight;
};
```

---

## Dynamic Programming Approach

The algorithm computes the minimum total weight needed to construct every amount from:

```text
0
```

to:

```text
A
```

A DP table is used:

```cpp
dp[x]
```

where:

```text
dp[x]
```

stores the minimum weight required to obtain amount:

```text
x
```

The final answer is:

```cpp
dp[A]
```

---

## Dynamic Programming Recurrence

Let:

```cpp
dp[x]
```

represent:

```text
The minimum total weight required
to obtain amount x.
```

### Base Case

The amount zero can be obtained without using any coins:

```cpp
dp[0] = 0;
```

All other entries are initialized to infinity:

```cpp
dp[i] = INF;
```

indicating that the amount has not yet been reached.

### Recurrence Relation

For every amount:

```cpp
x = 1 ... A
```

and for every available coin:

```cpp
value[i]
weight[i]
```

the state is updated using:

```cpp
dp[x] =
min(
    dp[x],
    dp[x - value[i]] + weight[i]
);
```

provided that:

```cpp
x >= value[i]
```

and amount:

```cpp
x - value[i]
```

has already been computed.

### Intuition

Suppose the algorithm wants to compute:

```text
dp[10]
```

and there exists a coin:

```text
value = 5
weight = 2
```

Then:

```cpp
dp[10]
=
dp[5] + 2
```

If the lightest way to obtain amount:

```text
5
```

has weight:

```text
2
```

then adding another coin of value:

```text
5
```

produces amount:

```text
10
```

with total weight:

```text
4
```

The algorithm evaluates every possible final coin and keeps the lightest valid solution.

---

## Why Unlimited Coin Usage Is Allowed

The Dynamic Programming formulation assumes that every coin denomination may be used an unlimited number of times.

This follows directly from the problem statement, which specifies the coin denominations and their weights but does not impose any limit on the number of available coins.

For example:

| Value | Weight |
|---------|---------:|
| 1 | 10 |
| 2 | 5 |
| 5 | 2 |

Target:

```text
10
```

Optimal solution:

```text
5 + 5
```

The denomination:

```text
5
```

is used twice.

The recurrence:

```cpp
dp[x] =
min(
    dp[x],
    dp[x - value[i]] + weight[i]
);
```

naturally allows this behavior because:

```cpp
dp[x - value[i]]
```

may already contain one or more copies of the same coin.

This problem is therefore an instance of the:

```text
Unbounded Coin Change Problem
```

where every denomination may be selected repeatedly.

---

## Correctness

The recurrence is correct because of the optimal substructure property.

An optimal solution for amount:

```text
x
```

can always be expressed as:

```text
Optimal solution for
x - value[i]
```

plus one final coin.

Since all possible final coins are considered and the minimum weight is chosen, the algorithm always finds the globally optimal solution.

---

## Complexity Analysis

Let:

```text
A
```

be the target amount and:

```text
n
```

be the number of coin types.

Time Complexity:

```text
O(A · n)
```

Space Complexity:

```text
O(A)
```

---

## Benchmarking Methodology

Execution time was measured using:

```cpp
QueryPerformanceCounter()
```

from the Windows API.

Several target amounts were tested.

Example benchmark sizes:

```text
100
500
1000
5000
10000
50000
100000
```

Average execution times were recorded and exported to:

```text
data/benchmark.csv
```

---

## Experimental Results

Example execution:

```text
Minimum weight for 10 = 4
```

which corresponds to:

```text
5 + 5
```

with total weight:

```text
4
```

The measured execution times increase approximately linearly with the target amount, which is consistent with the expected:

```text
O(A · n)
```

complexity.

Since the number of coin types remains fixed during testing, the practical behavior approaches:

```text
O(A)
```

with respect to the target amount.

---

## Generated Figures

### Runtime Comparison

```text
report/runtime_comparison.png
```

Displays execution time as a function of the target amount.

The graph shows the gradual increase in execution time as the DP table grows larger.

### Logarithmic Runtime Comparison

```text
report/runtime_logarithmic.png
```

Uses logarithmic axes to visualize scaling behavior over large input sizes.

The graph demonstrates stable growth consistent with the theoretical complexity of the algorithm.

---

## Setup

### Prerequisites

- C++17 compatible compiler
- Windows operating system
- Python 3.13+ (for graph generation)

---

## Build

```bash
g++ src/main.cpp src/DPSolver.cpp -o benchmark
```

---

## Usage

Run:

```bash
./benchmark.exe
```

Example output:

```text
Minimum weight for 10 = 4
```

The program:

1. Solves the weighted coin change problem.
2. Computes the minimum total weight.
3. Benchmarks the DP algorithm.
4. Exports benchmark results.

---

## Benchmark Output

Generated automatically:

```text
data/benchmark.csv
```

Format:

```csv
Amount,TimeMs
100,...
500,...
1000,...
...
```

---

## Generate Graphs

Install dependencies:

```bash
py -3.13 -m pip install pandas matplotlib
```

Run:

```bash
py -3.13 graph.py
```

Generated files:

```text
report/
├── runtime_comparison.png
└── runtime_logarithmic.png
```

---

## Project Structure

```text
overencumbered-inventory
│
├── data/
│   └── benchmark.csv
│
├── report/
│   ├── runtime_comparison.png
│   └── runtime_logarithmic.png
│
├── src/
│   ├── Coin.h
│   ├── DPSolver.h
│   ├── DPSolver.cpp
│   └── main.cpp
│
├── graph.py
├── README.md
└── benchmark.exe
```

---

## Conclusion

A Dynamic Programming solution was implemented to minimize the total weight of coins required to obtain a target amount.

The algorithm exploits optimal substructure by storing the minimum weight solution for every intermediate amount and reusing those results to construct larger solutions.

Experimental evaluation confirmed the expected:

```text
O(A · n)
```

time complexity.

The approach guarantees an optimal solution and remains practical even for large target amounts.

---

## Author

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź