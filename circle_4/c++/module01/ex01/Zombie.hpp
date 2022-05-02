#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>
# include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void			announce(void);
		void			setZombieName(std::string name);
		static Zombie	*zombieHorde(int N, std::string name);
};

#endif
