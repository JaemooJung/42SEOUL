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
		static Zombie	*newZombie(std::string name);
		static void		randomChump(std::string name);
};

#endif