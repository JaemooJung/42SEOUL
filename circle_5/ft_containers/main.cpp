#include <vector>
#include <iostream>
#include <iterator>
#include "vector.hpp"
#include <stack>
#include <map>
#include "red_black_tree.hpp"
#include "utils.hpp"
#include "map.hpp"

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

void my_test_1(void) {
	std::vector<int> v;
	ft::vector<int> myV;
	std::cout << "===========================================================" << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::cout << myV.size() << std::endl;
	std::cout << myV.max_size() << std::endl;
	std::cout << myV.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;

	v.push_back(1);
	myV.push_back(1);
	v.push_back(2);
	myV.push_back(2);
	v.push_back(3);
	myV.push_back(3);
	std::cout << "========================push test==========================" << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::cout << myV.size() << std::endl;
	std::cout << myV.max_size() << std::endl;
	std::cout << myV.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "========================iterator test======================" << std::endl;
	std::cout << "v.begin() = " << *v.begin() << std::endl;
	std::cout << "v.end() - 1 = " << *(v.end() - 1) << std::endl;
	std::cout << "myV.begin() = " << *myV.begin() << std::endl;
	std::cout << "myV.end() - 1 = " << *(myV.end() - 1) << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "========================reverse iterator test================" << std::endl;
	std::cout << "v.rbegin() = " << *v.rbegin() << std::endl;
	std::cout << "v.rend() - 1 = " << *(v.rend() - 1) << std::endl;
	std::cout << "myV.rbegin() = " << *myV.rbegin() << std::endl;
	std::cout << "myV.rend() - 1 = " << *(myV.rend() - 1) << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::reverse_iterator it = myV.rbegin(); it != myV.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "=========================pop test========================" << std::endl;
	v.pop_back();
	myV.pop_back();
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "=========================resize test======================" << std::endl;
	v.resize(10);
	myV.resize(10);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "==========================================================" << std::endl;

	std::cout << "=========================reserve test========================" << std::endl;
	v.reserve(100);
	myV.reserve(100);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "myV.capacity() = " << myV.capacity() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;


	std::cout << "=========================insert test========================" << std::endl;
	v.insert(v.begin() + 9, 12);
	myV.insert(myV.begin() + 9, 12);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;
}

void const_test() {
	// const int size = 5;
	// ft::vector<int> vct(size);
	// ft::vector<int>::iterator it = vct.begin();
	// ft::vector<int>::const_iterator ite = vct.begin();

	// for (int i = 0; i < size; ++i)
	// 	it[i] = i;

	// *ite = 42; // < -- error
}

void insert_test() {
	std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
	try {
    	vv.insert(vv.begin(), v1.begin(), v1.end());
	}
    catch (...) {
    	std::cout << vv.size() << std::endl;
        std::cout << vv.capacity() << std::endl;
    }
}

void swap_test() {
	ft::vector<int> vector;
	int _ratio = 10000;
    vector.assign(1100 * _ratio, 11);
    ft::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);

	std::cout << tmp4[2] << std::endl;
	std::cout << tmp4.size() << std::endl;
	std::cout << tmp4.capacity() << std::endl;

	std::cout << "=========================swap test========================" << std::endl;
	
    std::cout << vector[2] << std::endl;
	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	std::cout << "**1**" << std::endl;
    std::cout << vector[2] << std::endl;
	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;
    vector.swap(tmp3);
    std::cout << vector[2] << std::endl;
	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;
    vector.swap(tmp2);
    std::cout << vector[2] << std::endl;
	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;
    vector.swap(tmp4);
    std::cout << vector[2] << std::endl;
	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;
}

void map_test() {
	ft::map<int, char> map;


}

int main(void) {
	//insert_test();
	// swap_test();
	map_test();
	std::cout << "test done" << std::endl;
}
