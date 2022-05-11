#include <string>
#include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		std::string debugMessage;
		std::string infoMessage;
		std::string warningMessage;
		std::string errorMessage;
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};