cmake_minimum_required(VERSION 3.15)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms
        main.cpp johnson_and_trotter.cpp Trie.h SegmentTree.h RMQ.h JarvisMarchConvexHull.h GrahamScanConvexHull.h GreatestCommonDivisor.h Determinant.h NumberTheory.h LongestCommonSubsequence.h Knapsack.h AVLTree.h PatternMatching.h)
