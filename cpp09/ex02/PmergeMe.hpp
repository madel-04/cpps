#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <stdexcept>

class PmergeMe
{
    private:
        std::vector<long long> _vector;
        std::deque<long long> _deque;

        void insertionSortVector(std::vector<long long>& seq);
        void insertionSortDeque(std::deque<long long>& seq);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();   

        void parseInput(long long argc, char** argv);
        void sortVector();
        void sortDeque();
        void displayBefore() const;
        void displayAfter() const;
        void measureTime();
};

#endif

/*
Vector: Mejor rendimiento para acceso aleatorio y memoria contigua
Deque: Mejor para inserciones en ambos extremos
*/