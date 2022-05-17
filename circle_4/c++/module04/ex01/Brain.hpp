#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <string>
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	
	public:
		void setIdea(const int& i, const std::string& idea);
		std::string getIdea(const int& i) const;

		Brain& operator=(const Brain& other);
		Brain();
		Brain(const Brain& other);
		~Brain();
};

#endif // __BRAIN_H__