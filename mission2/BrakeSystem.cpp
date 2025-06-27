#include <string>

using namespace std;

enum BrakeSystemType
{
	BST_MANDO = 1,
	BST_CONTINENTAL,
	BST_BOSCH,
	BST_MAX
};

class BrakeSystem {
public:
	virtual string getName() = 0;
	virtual int getType() = 0;
};

class MandoBrakeSystem : public BrakeSystem {
public:
	string getName() {
		string str = "MANDO";
		return str;
	}
	int getType() {
		return BST_MANDO;
	}
};

class ContinentalBrakeSystem : public BrakeSystem {
public:
	string getName() {
		string str = "CONTINENTAL";
		return str;
	}
	int getType() {
		return BST_CONTINENTAL;
	}
};

class BoschBrakeSystem : public BrakeSystem {
public:
	string getName() {
		string str = "BOSCH";
		return str;
	}
	int getType() {
		return BST_BOSCH;
	}
};
