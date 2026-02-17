<div align="center">

# 🔢 Push_swap

*Sort data with a limited set of operations — in the minimum number of moves*

![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![42](https://img.shields.io/badge/42-School-000000?style=flat-square)
![Status](https://img.shields.io/badge/Status-Finished-success?style=flat-square)

</div>

---

## 📖 About

Push_swap is an `algorithm optimization` problem focused on sorting with `computational complexity` constraints. Given two stacks and a limited instruction set (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.), the goal is to sort integers in stack A with the minimum number of operations. The challenge lies in designing an algorithm that scales efficiently — handling small datasets with hardcoded optimal solutions while using `cost-based analysis` and `chunk partitioning` for larger inputs (100-500 elements). Performance is measured by operation count against strict thresholds.

---

## ✨ Features

- **Optimized sorting algorithm** with operation count minimization
- **Edge case handling:** Validates input (duplicates, non-integers, overflow), handles pre-sorted and reverse-sorted arrays
- **Scalable performance:** Efficient from 3 to 500+ elements
- **Instruction set compliance:** Uses only stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)
- **Memory efficient:** In-place operations with O(n) space complexity

---

## 🚀 Usage

```bash
git clone https://github.com/YourName/push_swap.git
cd push_swap
make
./push_swap [list of integers]
```

**Example:**
```bash
./push_swap 3 2 5 1 4
# Outputs the sequence of operations to sort the stack
```

**With checker (if you made it):**
```bash
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
# Should output "OK" if the stack is sorted correctly
```

**Testing with a visualizer:**

You can use external visualizers to see the sorting process in action:

- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) (Python-based, GUI)
- [push_swap_visualizer](https://github.com/ael-bekk/push_swap_visualizer) (Web-based)

Example with o-reo's visualizer:
```bash
git clone https://github.com/o-reo/push_swap_visualizer.git
cd push_swap_visualizer
mkdir build && cd build
cmake .. && make
./bin/visualizer
# Then paste your push_swap output or use random generation
```

---

## 🧠 Algorithm Strategy

**Small stacks (≤5 elements):** 
- Hardcoded optimal solutions using decision trees
- Guarantees minimum operation count for base cases

**Medium/Large stacks (>5 elements):**
- **Chunk-based partitioning:** Divides input into sorted segments for efficient processing
- **Cost calculation:** Evaluates rotation cost for each element (ra/rb vs rra/rrb)
- **Greedy optimization:** Selects moves that minimize total operation count
- **Two-stack coordination:** Strategically distributes elements between stacks to reduce moves

**Complexity:** O(n²) worst case, optimized for practical performance within 42 School thresholds (≤700 moves for 100 numbers, ≤5500 for 500).

---
<div align="center">
  <sub>Sorting integers one move at a time</sub>
</div>
