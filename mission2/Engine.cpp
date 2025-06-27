#include <string>

using namespace std;

enum EngineType
{
	ET_GM = 1,
	ET_TOYOTA,
	ET_WIA,
	ET_MAX
};

class Engine {
public:
	virtual string getName() = 0;
	virtual int getType() = 0;
};

class GMEngine : public Engine {
public:
	string getName() {
		string str = "GM";
		return str;
	}
	int getType() {
		return ET_GM;
	}
};

class ToyotaEngine : public Engine {
public:
	string getName() {
		string str = "TOYOTA";
		return str;
	}
	int getType() {
		return ET_TOYOTA;
	}
};

class WIAEngine : public Engine {
public:
	string getName() {
		string str = "WIA";
		return str;
	}
	int getType() {
		return ET_WIA;
	}
};
