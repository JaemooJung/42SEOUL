#include "Fixed.hpp"

int main(void) {

	std::cout << "------Test on the subject------" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "-------------------------------" << std::endl;

	Fixed c(11.f);
	Fixed d(12.05f);

	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << d / c << std::endl;

	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << " c > d : " << (c > d) << std::endl;
	std::cout << " c < d : " << (c < d) << std::endl;
	std::cout << " c >= d : " << (c >= d) << std::endl;
	std::cout << " c >= d : " << (c <= d) << std::endl;
	std::cout << " c == d : " << (c == d) << std::endl;
	std::cout << " c != d : " << (c != d) << std::endl;

	return 0;
}