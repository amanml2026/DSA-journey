# Data Structures and Algorithms: A Theoretical and Systems Approach

This repository documents a rigorous, mathematically grounded study of Data Structures and Algorithms. Departing from standard heuristic-driven programming, this curriculum emphasizes formal mathematical derivations, inductive proofs of correctness, and hardware-aware systems profiling. It is designed to build a robust theoretical bedrock for advanced computational research and systems engineering.

## Objective

The primary objective of this repository is to treat computer science fundamentals as a formal scientific discipline. Every algorithm and data structure is studied not merely for its API or immediate utility, but for its asymptotic limits, underlying recurrence relations, and actual performance constraints within modern memory hierarchies.

## Principles of Execution

1. **Theoretical Rigor:** Problem-solving prioritizes analytical depth over speed. All implementations are accompanied by formal mathematical bounds ($O$, $\Omega$, $\Theta$) and inductive proofs of correctness (e.g., loop invariants).
2. **First-Principles Implementation:** Core data structures and algorithms are authored entirely from scratch in C/Python. High-level library abstractions are intentionally avoided to ensure absolute comprehension of the underlying memory mechanics and pointers.
3. **Hardware-Aware Profiling:** Asymptotic complexity is validated against physical hardware constraints. Spatial and temporal locality are measured, tracking L1/LLC cache misses using profiling tools such as `perf stat` or Valgrind's Cachegrind.
4. **Curated Problem Analysis:** A curated set of benchmark problems is analyzed extensively. Each problem requires a formal write-up defining state spaces, transition functions, and algorithmic edge cases prior to any code generation.

## Curriculum & Progress

| Module | Core Competencies | Status | 
| ----- | ----- | ----- | 
| **01: Asymptotic Analysis** | Formal bounds (Big-$O$, $\Omega$, $\Theta$, small-$o$), sequence limits. | ✅ Completed | 
| **02: Algorithmic Proofs** | Master Theorem, substitution method, inductive loop invariants. | ✅ Completed | 
| **03: Fundamental Structures** | Dynamic arrays (amortized), hash tables, min-heaps, BSTs. | 🚧 In Progress | 
| **04: Graph & DP Paradigms** | BFS/DFS, topological sorting, Dijkstra, optimal substructure, DAGs. | 📌 Planned | 
| **05: Memory Hierarchy** | Spatial/temporal locality, cache lines, cache-friendly matrix layouts. | 📌 Planned | 
| **06: Applied Problem Sets** | Formal $O(T)$/$O(S)$ proofs and edge-case documentation for benchmarks. | 📌 Planned | 

**Legend:** ✅ Completed &nbsp;|&nbsp; 🚧 In Progress &nbsp;|&nbsp; 📌 Planned

## Quality Assurance Standards

Before any module is committed and marked as completed, the following criteria must be strictly met:

- [ ] **Analytical Formulation:** Recurrence relations, decision trees, and inductive steps are documented explicitly.
- [ ] **Clean-Room Implementation:** Code is authored without standard library structures (e.g., no `dict` or `list.sort` when building hash tables or sorting algorithms).
- [ ] **Invariant Validation:** Comprehensive unit test suites structurally assert all invariants (e.g., heap properties, load factor constraints, tree balance).
- [ ] **Systems Benchmarking:** Relevant algorithmic implementations include profiling data contrasting baseline theoretical performance against loop-tiled or cache-optimized memory access patterns.

## Primary Literature & References

The theoretical frameworks and methodologies applied throughout this repository are drawn directly from the following texts and lectures:

* **Cormen, Leiserson, Rivest, Stein (CLRS):** *Introduction to Algorithms* (Focus: Chapters 3, 4, 6, 7, 10-12, 15, 22, 24)
* **MIT 6.006:** *Introduction to Algorithms*
* **MIT 6.042J:** *Mathematics for Computer Science*
* **Bryant & O'Hallaron (CS:APP):** *Computer Systems: A Programmer's Perspective* (Focus : Chapter 6 - Memory Hierarchy)

---

### License

This project is open source and available under the [MIT License](LICENSE).

> *"Theory earns its place by being built, not just read."*