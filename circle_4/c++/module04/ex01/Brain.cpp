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
	
}

Brain::Brain() {
	
}

Brain::Brain(const Brain& other) {
	
}

Brain::~Brain() {
	
}
