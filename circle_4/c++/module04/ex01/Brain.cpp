#include "Brain.hpp"

void Brain::setIdea(const int& i, const std::string& idea) {
	if (i < 0 || i >= 100) {
		std::cout << "Error: [" << i << "] out of range" << std::endl;
		return;
	}
	_ideas[i] = idea;
}

std::string Brain::getIdea(const int& i) const {
	if (i < 0 || i >= 100) {
		std::cout << "Error: [" << i << "] out of range" << std::endl;
		return;
	}
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other.getIdea(i);
		}
	}
	std::cout << "Brain copy assignation operator called" << std::endl;
	return *this;
}

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other.getIdea(i);
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
