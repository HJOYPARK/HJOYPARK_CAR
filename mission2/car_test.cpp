#include "gmock/gmock.h"
#include "Car.cpp"
#include "Engine.cpp"
#include "BrakeSystem.cpp"
#include "SteeringSystem.cpp"

TEST(Group, CarTest) {
	Car* car = 0;
	string strRet;
	int iRet;

	car = (Car*)new SedanCar();
	strRet = car->getName();
	EXPECT_EQ("Sedan", strRet);
	iRet = car->getType();
	EXPECT_EQ(CT_SEDAN, iRet);

	car = (Car*)new SUVCar();
	strRet = car->getName();
	EXPECT_EQ("SUV", strRet);
	iRet = car->getType();
	EXPECT_EQ(CT_SUV, iRet);

	car = (Car*)new TruckCar();
	strRet = car->getName();
	EXPECT_EQ("Truck", strRet);
	iRet = car->getType();
	EXPECT_EQ(CT_TRUCK, iRet);
}

TEST(Group, EngineTest) {
	Engine* engine = 0;
	string strRet;
	int iRet;

	engine = (Engine*)new GMEngine();
	strRet = engine->getName();
	EXPECT_EQ("GM", strRet);
	iRet = engine->getType();
	EXPECT_EQ(ET_GM, iRet);

	engine = (Engine*)new ToyotaEngine();
	strRet = engine->getName();
	EXPECT_EQ("TOYOTA", strRet);
	iRet = engine->getType();
	EXPECT_EQ(ET_TOYOTA, iRet);

	engine = (Engine*)new WIAEngine();
	strRet = engine->getName();
	EXPECT_EQ("WIA", strRet);
	iRet = engine->getType();
	EXPECT_EQ(ET_WIA, iRet);
}

TEST(Group, BrakeSystemTest) {
	BrakeSystem* brakeSystem = 0;
	string strRet;
	int iRet;

	brakeSystem = (BrakeSystem*)new MandoBrakeSystem();
	strRet = brakeSystem->getName();
	EXPECT_EQ("MANDO", strRet);
	iRet = brakeSystem->getType();
	EXPECT_EQ(BST_MANDO, iRet);

	brakeSystem = (BrakeSystem*)new ContinentalBrakeSystem();
	strRet = brakeSystem->getName();
	EXPECT_EQ("CONTINENTAL", strRet);
	iRet = brakeSystem->getType();
	EXPECT_EQ(BST_CONTINENTAL, iRet);

	brakeSystem = (BrakeSystem*)new BoschBrakeSystem();
	strRet = brakeSystem->getName();
	EXPECT_EQ("BOSCH", strRet);
	iRet = brakeSystem->getType();
	EXPECT_EQ(BST_BOSCH, iRet);
}

TEST(Group, SteeringSystemTest) {
	SteeringSystem* steeringSystem = 0;
	string strRet;
	int iRet;

	steeringSystem = (SteeringSystem*)new BoschSteeringSystem();
	strRet = steeringSystem->getName();
	EXPECT_EQ("BOSCH", strRet);
	iRet = steeringSystem->getType();
	EXPECT_EQ(SST_BOSCH, iRet);

	steeringSystem = (SteeringSystem*)new MobisSteeringSystem();
	strRet = steeringSystem->getName();
	EXPECT_EQ("MOBIS", strRet);
	iRet = steeringSystem->getType();
	EXPECT_EQ(SST_MOBIS, iRet);
}
