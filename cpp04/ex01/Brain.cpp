#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] Default constructor called\n" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "[Brain] copy constructor called\n" << std::endl;
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "[Brain] copy assignment called\n" << std::endl;
    if (this != &other)
    {
        for (size_t i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] destructor called\n" << std::endl;
}

void Brain::setIdea(size_t idx, const std::string& idea)
{
    if (idx < 100)
        ideas[idx] = idea;
}

std::string Brain::getIdea(size_t idx) const
{
    if (idx < 100)
        return ideas[idx];
    return "";
}