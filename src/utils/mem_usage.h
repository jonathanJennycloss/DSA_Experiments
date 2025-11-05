#pragma once

/*
 * mem_usage.h
 * -----------
 * Small helper used by tests to sample approximate process memory usage.
 *
 * Current implementation:
 * - Windows: uses GetProcessMemoryInfo (PSAPI) and reports WorkingSetSize in KB.
 * - Non-Windows: stubs return 0. Add platform-specific code (procfs, mach_api)
 *   if cross-platform measurements are required.
 *
 * Limitations and notes:
 * - Working set is a coarse process-level metric and includes more than the
 *   memory used by the linked list (stack, runtime, other allocations).
 * - This utility is intended for quick regression checks and not for exact
 *   per-object accounting.
 */

#if defined(_WIN32)
#include <windows.h>
#include <psapi.h>
#include <cstdint>

// Returns current process working set size in KB
inline size_t getCurrentMemoryKB() {
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        return static_cast<size_t>(pmc.WorkingSetSize / 1024);
    }
    return 0;
}

// Simple RAII snapshot for peak memory measurement
struct MemorySnapshot {
    size_t beforeKB;
    MemorySnapshot() : beforeKB(getCurrentMemoryKB()) {}
    size_t diffKB() const { return (getCurrentMemoryKB() > beforeKB) ? (getCurrentMemoryKB() - beforeKB) : 0; }
};

#else
#include <cstddef>
inline size_t getCurrentMemoryKB() { return 0; }
struct MemorySnapshot { size_t beforeKB{0}; size_t diffKB() const { return 0; } };
#endif