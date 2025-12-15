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

// ---------------- Jacobsthal Numbers ----------------

size_t PmergeMe::jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t current = 1;
    
    for (size_t i = 2; i <= n; ++i)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// ---------------- Ford-Johnson Algorithm (Vector) ----------------

void PmergeMe::binaryInsertVector(std::vector<long long>& sorted, long long value)
{
    std::vector<long long>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

std::vector<long long> PmergeMe::mergeInsertVector(std::vector<long long>& seq)
{
    if (seq.size() <= 1)
        return seq;

    // Step 1: Create pairs and sort each pair
    std::vector<std::pair<long long, long long> > pairs;
    bool hasStraggler = (seq.size() % 2 != 0);
    long long straggler = hasStraggler ? seq.back() : 0;

    for (size_t i = 0; i + 1 < seq.size(); i += 2)
    {
        if (seq[i] > seq[i + 1])
            pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        else
            pairs.push_back(std::make_pair(seq[i + 1], seq[i]));
    }

    // Step 2: Recursively sort by larger elements
    std::vector<long long> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].first);

    larger = mergeInsertVector(larger);

    // Step 3: Create main chain with larger elements
    std::vector<long long> result = larger;

    // Step 4: Insert smaller elements using Jacobsthal sequence
    std::vector<long long> pending;
    for (size_t i = 0; i < pairs.size(); ++i)
        pending.push_back(pairs[i].second);

    // Insert first element at beginning
    if (!pending.empty())
    {
        result.insert(result.begin(), pending[0]);
        pending.erase(pending.begin());
    }

    // Use Jacobsthal sequence for optimal insertion order
    size_t jacobIndex = 3;
    size_t inserted = 0;
   
    while (inserted < pending.size())
    {
        size_t jacob = jacobsthal(jacobIndex);
        size_t prevJacob = jacobsthal(jacobIndex - 1);
        
        // Insert elements in reverse order between Jacobsthal numbers
        for (size_t pos = jacob - 1; pos >= prevJacob && pos < pending.size(); --pos)
        {
            binaryInsertVector(result, pending[pos]);
            ++inserted;
            if (pos == 0) break;
        }
        ++jacobIndex;
    }

    // Insert straggler if exists
    if (hasStraggler)
        binaryInsertVector(result, straggler);

    return result;
}

void PmergeMe::fordJohnsonVector(std::vector<long long>& seq)
{
    seq = mergeInsertVector(seq);
}
void PmergeMe::sortVector()
{
    fordJohnsonVector(_vector);
}

// ---------------- Ford-Johnson Algorithm (Deque) ----------------

void PmergeMe::binaryInsertDeque(std::deque<long long>& sorted, long long value)
{
    std::deque<long long>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

std::deque<long long> PmergeMe::mergeInsertDeque(std::deque<long long>& seq)
{
    if (seq.size() <= 1)
        return seq;

    // Step 1: Create pairs and sort each pair
    std::vector<std::pair<long long, long long> > pairs;
    bool hasStraggler = (seq.size() % 2 != 0);
    long long straggler = hasStraggler ? seq.back() : 0;

    for (size_t i = 0; i + 1 < seq.size(); i += 2)
    {
        if (seq[i] > seq[i + 1])
            pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        else
            pairs.push_back(std::make_pair(seq[i + 1], seq[i]));
    }

    // Step 2: Recursively sort by larger elements
    std::deque<long long> larger;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].first);

    larger = mergeInsertDeque(larger);

    // Step 3: Create main chain with larger elements
    std::deque<long long> result = larger;

    // Step 4: Insert smaller elements using Jacobsthal sequence
    std::deque<long long> pending;
    for (size_t i = 0; i < pairs.size(); ++i)
        pending.push_back(pairs[i].second);

    // Insert first element at beginning
    if (!pending.empty())
    {
        result.insert(result.begin(), pending[0]);
        pending.erase(pending.begin());
    }

    // Use Jacobsthal sequence for optimal insertion order
    size_t jacobIndex = 3;
    size_t inserted = 0;
    
    while (inserted < pending.size())
    {
        size_t jacob = jacobsthal(jacobIndex);
        size_t prevJacob = jacobsthal(jacobIndex - 1);
        
        // Insert elements in reverse order between Jacobsthal numbers
        for (size_t pos = jacob - 1; pos >= prevJacob && pos < pending.size(); --pos)
        {
            binaryInsertDeque(result, pending[pos]);
            ++inserted;
            if (pos == 0) break;
        }
        ++jacobIndex;
    }

    // Insert straggler if exists
    if (hasStraggler)
        binaryInsertDeque(result, straggler);

    return result;
}

void PmergeMe::fordJohnsonDeque(std::deque<long long>& seq)
{
    seq = mergeInsertDeque(seq);
}

void PmergeMe::sortDeque()
{
    fordJohnsonDeque(_deque);
}

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
