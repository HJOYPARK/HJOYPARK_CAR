#include <string>

using namespace std;

enum SteeringSystemType
{
	SST_BOSCH = 1,
	SST_MOBIS,
	SST_MAX
};

class SteeringSystem {
public:
	virtual string getName() = 0;
	virtual int getType() = 0;
};

class BoschSteeringSystem : public SteeringSystem {
public:
	string getName() {
		string str = "BOSCH";
		return str;
	}
	int getType() {
		return SST_BOSCH;
	}
};

class MobisSteeringSystem : public SteeringSystem {
public:
	string getName() {
		string str = "MOBIS";
		return str;
	}
	int getType() {
		return SST_MOBIS;
	}
};
