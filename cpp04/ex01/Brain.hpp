#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    void setIdea(size_t idx, const std::string& idea);
    std::string getIdea(size_t idx) const;

private:
    std::string ideas[100];
};

#endif
