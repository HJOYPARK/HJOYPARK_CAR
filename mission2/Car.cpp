#include <string>

using namespace std;

enum CarType
{
	CT_SEDAN = 1,
	CT_SUV,
	CT_TRUCK,
	CT_MAX
};

class Car {
public:
	virtual string getName() = 0;
	virtual int getType() = 0;
};

class SedanCar : public Car {
public:
	string getName() {
		string str = "Sedan";
		return str;
	}
	int getType() {
		return CT_SEDAN;
	}
};

class SUVCar : public Car {
public:
	string getName() {
		string str = "SUV";
		return str;
	}
	int getType() {
		return CT_SUV;
	}
};

class TruckCar : public Car {
public:
	string getName() {
		string str = "Truck";
		return str;
	}
	int getType() {
		return CT_TRUCK;
	}
};
