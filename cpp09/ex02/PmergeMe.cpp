#include "PmergeMe.hpp"

// ---------------- Canonical Form ----------------

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

// ---------------- Input Parsing ----------------

void PmergeMe::parseInput(long long argc, char **argv)
{
    for (long long i = 1; i < argc; ++i)
    {
        std::istringstream ss(argv[i]);
        long long num;
        ss >> num;
        if (ss.fail() || num <= 0)
            throw std::runtime_error("Error: invalid number.");

        _vector.push_back(num);
        _deque.push_back(num);
    }
}

// ---------------- Display ----------------

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

// ---------------- Sorting (Ford-Johnson simplified) ----------------

// For simplicity, using insertion sort which is compatible with merge-insert
void PmergeMe::insertionSortVector(std::vector<long long> &seq)
{
    for (size_t i = 1; i < seq.size(); ++i)
    {
        long long key = seq[i];
        long long j = i - 1;
        while (j >= 0 && seq[j] > key)
        {
            seq[j + 1] = seq[j];
            --j;
        }
        seq[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<long long> &seq)
{
    for (size_t i = 1; i < seq.size(); ++i)
    {
        long long key = seq[i];
        long long j = i - 1;
        while (j >= 0 && seq[j] > key)
        {
            seq[j + 1] = seq[j];
            --j;
        }
        seq[j + 1] = key;
    }
}

void PmergeMe::sortVector() { insertionSortVector(_vector); }
void PmergeMe::sortDeque()  { insertionSortDeque(_deque);  }

// ---------------- Measure Time ----------------

void PmergeMe::measureTime()
{
    clock_t start, end;
    double elapsed_us;

    // Vector
    std::vector<long long> tmpVec = _vector; // copy to preserve original
    start = clock();
    sortVector();
    end = clock();
    elapsed_us = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << elapsed_us << " us" << std::endl;

    // Deque
    std::deque<long long> tmpDeq = _deque; // copy to preserve original
    start = clock();
    sortDeque();
    end = clock();
    elapsed_us = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << elapsed_us << " us" << std::endl;
}
