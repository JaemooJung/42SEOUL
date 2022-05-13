#ifndef _FIXED_H_
# define _FIXED_H_

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	_fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		explicit Fixed(const int i);
		explicit Fixed(const float f);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& ref);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
