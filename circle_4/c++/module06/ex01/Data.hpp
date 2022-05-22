#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>
#include <string>

class Data {
	private:
		std::string _doomName;
		int _dayLeft;
		bool _isDoomed;
		float _doomFactor;
		double _doomDuration;
	
	public:
		std::string getDoomName() const;
		int getDayLeft() const;
		bool isDoomed() const;
		float getDoomFactor() const;
		double getDoomDuration() const;
		
		void setDoomName(std::string doomName);
		void setDayLeft(int dayLeft);
		void setDoomed(bool isDoomed);
		void setDoomFactor(float doomFactor);
		void setDoomDuration(double doomDuration);
		
		Data& operator=(const Data& other);
		Data();
		Data(std::string doomName, int dayLeft, bool isDoomed, float doomFactor, double doomDuration);
		Data(const Data& other);
		~Data();
};

std::ostream& operator<<(std::ostream& os, const Data& data);

#endif // __DATA_H__