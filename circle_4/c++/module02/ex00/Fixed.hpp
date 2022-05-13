#ifndef _FIXED_H_
# define _FIXED_H_

#include <iostream>

class Fixed {
	private:
		int	_fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& ref);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
