#include "whatever.hpp"
#include <string>
#include <iostream>

void testOnSubject() {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void test() {
	int ia = 10;
	int ib = 20;
	double da = 10.0;
	double db = 20.0;
	char ca = 'a';
	char cb = 'b';
	std::string sa = "hello";
	std::string sb = "world";

	std::cout << "ia: " << ia << std::endl;
	std::cout << "ib: " << ib << std::endl;
	::swap(ia, ib);
	std::cout << "After swap - " << std::endl;
	std::cout << "ia: " << ia << std::endl;
	std::cout << "ib: " << ib << std::endl;
	std::cout << "min(ia, ib): " << ::min(ia, ib) << std::endl;
	std::cout << "max(ia, ib): " << ::max(ia, ib) << std::endl;
	std::cout << std::endl;

	std::cout << "da: " << da << std::endl;
	std::cout << "db: " << db << std::endl;
	::swap(da, db);
	std::cout << "After swap - " << std::endl;
	std::cout << "da: " << da << std::endl;
	std::cout << "db: " << db << std::endl;
	std::cout << "min(da, db): " << ::min(da, db) << std::endl;
	std::cout << "max(da, db): " << ::max(da, db) << std::endl;
	std::cout << std::endl;

	std::cout << "ca: " << ca << std::endl;
	std::cout << "cb: " << cb << std::endl;
	::swap(ca, cb);
	std::cout << "After swap - " << std::endl;
	std::cout << "ca: " << ca << std::endl;
	std::cout << "cb: " << cb << std::endl;
	std::cout << "min(ca, cb): " << ::min(ca, cb) << std::endl;
	std::cout << "max(ca, cb): " << ::max(ca, cb) << std::endl;
	std::cout << std::endl;

	std::cout << "sa: " << sa << std::endl;
	std::cout << "sb: " << sb << std::endl;
	::swap(sa, sb);
	std::cout << "After swap - " << std::endl;
	std::cout << "sa: " << sa << std::endl;
	std::cout << "sb: " << sb << std::endl;
	std::cout << "min(sa, sb): " << ::min(sa, sb) << std::endl;
	std::cout << "max(sa, sb): " << ::max(sa, sb) << std::endl;
	std::cout << std::endl;

}

int main() {
	testOnSubject();
	std::cout << std::endl;
	test();
}