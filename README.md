# samemilecse3150lab5
# Cosine Distance Calculator  
 Samuel Emile

---

## Overview  
This C++ program reads in vectors (lists of numbers) from a text file and calculates the cosine angle between every possible pair of vectors. It then sorts the results so that the most similar vector pairs (those with the smallest angles between them) appear first.

---

## Features  
- Input Parsing:** Reads vectors from a text file. Each line in the file should contain a vector with numbers separated by spaces.  
- Validation:** Checks that all vectors are the same length.  
- Cosine Angle Calculation:** Calculates the angle between two vectors using the dot product and vector lengths (Euclidean norms).  
- Sorting:** Sorts the vector pairs by their angle, from smallest to largest.  
- Output:** Prints out each vector pair with their calculated angle in radians.

---

## Requirements  
- A C++ compiler that supports C++11 (for example, `g++`).  
- A text file with vectors, one per line, with numbers separated by spaces.

---

## Usage  

### 1. Compile the Program and Running the Program. 
```bash
g++ -std=c++11 -o cosine_pairs cosine_pairs.cpp
./cosine_pairs test_vectors.txt

