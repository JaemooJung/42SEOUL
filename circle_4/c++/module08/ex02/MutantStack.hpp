#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

class MutantStack {
	private:
		
	public:
		MutantStack& operator=(const MutantStack& other);
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
};

#endif // __MUTANTSTACK_H__