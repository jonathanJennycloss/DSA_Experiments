# Copilot Instructions for DSA Experiments

This repository contains implementations of various Data Structures and Algorithms. Follow these guidelines when working with this codebase.

## Project Structure

- Each data structure should be implemented in its own directory under `src/data_structures/`
- Each algorithm should be implemented in its own directory under `src/algorithms/`
- Test files should be placed alongside their implementations with a `.test` suffix
- Common utilities should be placed in `src/utils/`

## Implementation Guidelines

### Data Structures
- Each data structure implementation should include:
  - A clear class/interface definition
  - Basic operations (insert, delete, search etc.)
  - Time and space complexity documentation in comments
  - Usage examples in the accompanying README.md

### Algorithms
- Each algorithm implementation should include:
  - Function documentation with input/output specifications
  - Time and space complexity analysis
  - Edge case handling
  - Example usage in comments

## Testing Conventions
- Use pytest for testing
- Test files should cover:
  - Basic functionality
  - Edge cases
  - Performance benchmarks for complex operations
  - Example: `binary_search.py` should have `binary_search.test.py`

## Documentation Patterns
- Each implementation should have a README.md with:
  - Theory/concept explanation
  - Implementation details
  - Usage examples
  - Performance characteristics

## Development Workflow
1. Create new implementation directory
2. Write interface/specifications
3. Implement core functionality
4. Add comprehensive tests
5. Include documentation
6. Add performance benchmarks

## Code Style
- Follow PEP 8 guidelines
- Use type hints for better code clarity
- Include complexity analysis in docstrings
- Use descriptive variable names that reflect DSA terminology

Remember to maintain a balance between efficiency and readability in implementations.