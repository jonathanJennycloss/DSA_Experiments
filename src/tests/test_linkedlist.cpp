#include "gtest/gtest.h"
#include "../data_structures/LinkedList.hpp"
#include "../utils/mem_usage.h"

// The algorithm implementation is defined in src/algorithms/LinkedList_algos.cpp
extern Node* findMiddleNode(LinkedList& list);

#include <chrono>
#include <iostream>

using namespace std::chrono;

/*
 * Tests in this file serve two purposes:
 * 1) Unit tests: verify correctness of small inputs and edge cases.
 * 2) Lightweight perf check: measure runtime and approximate memory
 *    usage for a larger input N. The perf test prints results to stdout so
 *    CI logs can be inspected for regressions.
 *
 * Test implementation notes:
 * - The project's LinkedList API constructs a list with an initial value
 *   (LinkedList(int)). There is no default constructor; tests create a
 *   one-element list and call `makeEmpty()` when an empty list is needed.
 * - `append()` is used to grow the list. The perf test uses N = 200k by
 *   default which is reasonable on CI; adjust N for local profiling.
 * - Memory measurement is approximate: on Windows we sample Working Set via
 *   GetProcessMemoryInfo. This reports process memory usage change and is
 *   sufficient for rough comparisons but not for precise per-node accounting.
 */

TEST(LinkedListBasic, PushAndMiddle) {
    // Create a small list with values 1..5 and assert middle is 3.
    LinkedList list(1);
    for (int i = 2; i <= 5; ++i) list.append(i);

    Node* mid = findMiddleNode(list);
    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->value, 3);
}

TEST(LinkedListBasic, EmptyList) {
    LinkedList list(0);
    list.makeEmpty();
    EXPECT_EQ(findMiddleNode(list), nullptr);
}

TEST(LinkedListPerf, MiddleRuntimeAndMemory) {
    // Lightweight benchmark to observe runtime and memory allocation
    // characteristics. Not intended as a rigorous microbenchmark.
    const int N = 200000; // tune this to trade-off speed vs. fidelity
    LinkedList list(0);
    list.makeEmpty();

    // memory snapshot before population
    MemorySnapshot beforePop;

    for (int i = 0; i < N; ++i) list.append(i);

    size_t memUsedKB = beforePop.diffKB();
    std::cout << "Memory used to allocate list (approx): " << memUsedKB << " KB\n";

    // Measure time taken by findMiddleNode only (exclude allocation time)
    auto t0 = high_resolution_clock::now();
    Node* mid = findMiddleNode(list);
    auto t1 = high_resolution_clock::now();

    auto elapsed = duration_cast<microseconds>(t1 - t0).count();
    std::cout << "findMiddleNode for " << N << " elements took " << elapsed << " microseconds\n";

    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->value, N/2);

    // Basic sanity check that the operation took non-zero time.
    EXPECT_GT(elapsed, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
