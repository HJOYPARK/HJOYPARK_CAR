#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Car.cpp"
#include "Engine.cpp"
#include "BrakeSystem.cpp"
#include "SteeringSystem.cpp"

using namespace std;

#define CLEAR_SCREEN "\033[H\033[2J"

#define GET_CAR_ID ((Car*)gQuestions[QT_CAR])->getType()
#define GET_ENGINE_ID ((Engine*)gQuestions[QT_ENGINE])->getType()
#define GET_BRAKE_SYSTEM_ID ((BrakeSystem*)gQuestions[QT_BRAKE_SYSTEM])->getType()
#define GET_STEERING_SYSTEM_ID ((SteeringSystem*)gQuestions[QT_STEERING_SYSTEM])->getType()

void selectCarType(int inputType);
void selectEngineType(int inputType);
void selectBrakeSystemType(int inputType);
void selectSteeringSystemType(int inputType);
void runProducedCar();
void testProducedCar();
void delay(int ms);
void showMenu(int questionStep);
int validInput(char* inputBuffer, int* inputType);
int validInput(int questionStep, int inputType);
int run(int* questionStep, int inputType);
void* getObject(int questionStep, int inputType);

enum QuestionType
{
    QT_CAR,
    QT_ENGINE,
    QT_BRAKE_SYSTEM,
    QT_STEERING_SYSTEM,
    QT_RUN_TEST,
    QT_MAX
};

void* gQuestions[QT_MAX];

int main()
{
    char inputBuffer[100];
    int questionStep = QT_CAR;
    int inputType;

    while (1)
    {
        showMenu(questionStep);

        printf("INPUT > ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        if (int ret = validInput(inputBuffer, &inputType)) {
            if (ret == 1) break;
            else continue;
        }

        if (!validInput(questionStep, inputType)) continue;

        if (!run(&questionStep, inputType)) continue;
    }
}

void* getObject(int questionStep, int inputType) {
    void* ret = 0;

    switch (questionStep) {
    case QT_CAR:
        switch (inputType) {
        case CT_SEDAN:
            ret = new SedanCar();
            break;
        case CT_SUV:
            ret = new SUVCar();
            break;
        case CT_TRUCK:
            ret = new TruckCar();
            break;
        }
        break;
    case QT_ENGINE:
        switch (inputType) {
        case ET_GM:
            ret = new GMEngine();
            break;
        case ET_TOYOTA:
            ret = new ToyotaEngine();
            break;
        case ET_WIA:
            ret = new WIAEngine();
            break;
        }
        break;
    case QT_BRAKE_SYSTEM:
        switch (inputType) {
        case BST_MANDO:
            ret = new MandoBrakeSystem();
            break;
        case BST_CONTINENTAL:
            ret = new ContinentalBrakeSystem();
            break;
        case BST_BOSCH:
            ret = new BoschBrakeSystem();
            break;
        }
        break;
    case QT_STEERING_SYSTEM:
        switch (inputType) {
        case SST_BOSCH:
            ret = new BoschSteeringSystem();
            break;
        case SST_MOBIS:
            ret = new MobisSteeringSystem();
            break;
        }
        break;
    default:
        ret = 0;
    }

    return (void*)ret;
}

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

void showMenu(int questionStep) {
    if (questionStep == QT_CAR)
    {
        printf(CLEAR_SCREEN);

        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("� ���� Ÿ���� �����ұ��?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (questionStep == QT_ENGINE)
    {
        printf(CLEAR_SCREEN);
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }
    else if (questionStep == QT_BRAKE_SYSTEM)
    {
        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (questionStep == QT_STEERING_SYSTEM)
    {
        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (questionStep == QT_RUN_TEST)
    {
        printf(CLEAR_SCREEN);
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");
}

int validInput(char* inputBuffer, int* inputType) {
    // ���� ���๮�� ����
    char* context = nullptr;
    strtok_s(inputBuffer, "\r", &context);
    strtok_s(inputBuffer, "\n", &context);

    if (!strcmp(inputBuffer, "exit"))
    {
        printf("���̹���\n");
        return 1;
    }

    // ���ڷ� �� ������� Ȯ��
    char* checkNumber;
    *inputType = strtol(inputBuffer, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

    // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        delay(800);
        return 2;
    }

    return 0;
}

int validInput(int questionStep, int inputType) {
    if (questionStep == QT_CAR && !(inputType >= 1 && inputType <= CT_MAX))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return 0;
    }

    if (questionStep == QT_ENGINE && !(inputType >= 0 && inputType <= ET_MAX))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        delay(800);
        return 0;
    }

    if (questionStep == QT_BRAKE_SYSTEM && !(inputType >= 0 && inputType <= BST_MAX))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return 0;
    }

    if (questionStep == QT_STEERING_SYSTEM && !(inputType >= 0 && inputType <= SST_MAX))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        delay(800);
        return 0;
    }

    if (questionStep == QT_RUN_TEST && !(inputType >= 0 && inputType <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        delay(800);
        return 0;
    }

    return 1;
}

int run(int* questionStep, int inputType) {
    // ó������ ���ư���
    if (inputType == 0 && *questionStep == QT_RUN_TEST)
    {
        *questionStep = QT_CAR;
        return 0;
    }

    // �������� ���ư���
    if (inputType == 0 && *questionStep >= 1)
    {
        *questionStep -= 1;
        return 0;
    }

    if (*questionStep == QT_CAR)
    {
        selectCarType(inputType);
        delay(800);
        *questionStep = QT_ENGINE;
    }
    else if (*questionStep == QT_ENGINE)
    {
        selectEngineType(inputType);
        delay(800);
        *questionStep = QT_BRAKE_SYSTEM;
    }
    else if (*questionStep == QT_BRAKE_SYSTEM)
    {
        selectBrakeSystemType(inputType);
        delay(800);
        *questionStep = QT_STEERING_SYSTEM;
    }
    else if (*questionStep == QT_STEERING_SYSTEM)
    {
        selectSteeringSystemType(inputType);
        delay(800);
        *questionStep = QT_RUN_TEST;
    }
    else if (*questionStep == QT_RUN_TEST && inputType == 1)
    {
        runProducedCar();
        delay(2000);
    }
    else if (*questionStep == QT_RUN_TEST && inputType == 2)
    {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
    }

    return 1;
}

void selectCarType(int inputType)
{
    Car* obj = (Car*)getObject(QT_CAR, inputType);;
    char text[100] = { 0, };

    gQuestions[QT_CAR] = (void*)obj;
    sprintf_s(text, "���� Ÿ������ %s�� �����ϼ̽��ϴ�.\n", obj->getName().c_str());

    string str = text;
    printf(str.c_str());
}

void selectEngineType(int inputType)
{
    Engine* obj = (Engine*)getObject(QT_ENGINE, inputType);;
    char text[100] = { 0, };

    gQuestions[QT_ENGINE] = (void*)obj;
    sprintf_s(text, "%s  ������ �����ϼ̽��ϴ�.\n", obj->getName().c_str());

    string str = text;
    printf(str.c_str());
}

void selectBrakeSystemType(int inputType)
{
    BrakeSystem* obj = (BrakeSystem*)getObject(QT_BRAKE_SYSTEM, inputType);;
    char text[100] = { 0, };

    gQuestions[QT_BRAKE_SYSTEM] = (void*)obj;
    sprintf_s(text, "%s ������ġ�� �����ϼ̽��ϴ�.\n", obj->getName().c_str());

    string str = text;
    printf(str.c_str());
}

void selectSteeringSystemType(int inputType)
{
    SteeringSystem* obj = (SteeringSystem*)getObject(QT_STEERING_SYSTEM, inputType);;
    char text[100] = { 0, };

    gQuestions[QT_STEERING_SYSTEM] = (void*)obj;
    sprintf_s(text, "%s  ������ġ�� �����ϼ̽��ϴ�.\n", obj->getName().c_str());

    string str = text;
    printf(str.c_str());
}

int isValidCheck()
{
    if (GET_CAR_ID == CT_SEDAN && GET_BRAKE_SYSTEM_ID == BST_CONTINENTAL)
    {
        return false;
    }
    else if (GET_CAR_ID == CT_SUV && GET_ENGINE_ID == ET_TOYOTA)
    {
        return false;
    }
    else if (GET_CAR_ID == CT_TRUCK && GET_ENGINE_ID == ET_WIA)
    {
        return false;
    }
    else if (GET_CAR_ID == CT_TRUCK && GET_BRAKE_SYSTEM_ID == BST_MANDO)
    {
        return false;
    }
    else if (GET_BRAKE_SYSTEM_ID == BST_BOSCH && GET_STEERING_SYSTEM_ID != SST_BOSCH)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (GET_ENGINE_ID == 4)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            if (GET_CAR_ID == 1)
                printf("Car Type : Sedan\n");
            if (GET_CAR_ID == 2)
                printf("Car Type : SUV\n");
            if (GET_CAR_ID == 3)
                printf("Car Type : Truck\n");
            if (GET_ENGINE_ID == 1)
                printf("Engine Type : GM\n");
            if (GET_ENGINE_ID == 2)
                printf("Engine Type : TOYOTA\n");
            if (GET_ENGINE_ID == 3)
                printf("Engine Type : WIA\n");
            if (GET_BRAKE_SYSTEM_ID == 1)
                printf("Brake System Type : Mando\n");
            if (GET_BRAKE_SYSTEM_ID == 2)
                printf("Brake System Type : Continental\n");
            if (GET_BRAKE_SYSTEM_ID == 3)
                printf("Brake System Type : Bosch\n");
            if (GET_STEERING_SYSTEM_ID == 1)
                printf("Steering System Type : Bosch\n");
            if (GET_STEERING_SYSTEM_ID == 2)
                printf("Steering System Type : Mobis\n");

            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (GET_CAR_ID == CT_SEDAN && GET_BRAKE_SYSTEM_ID == BST_CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (GET_CAR_ID == CT_SUV && GET_ENGINE_ID == ET_TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (GET_CAR_ID == CT_TRUCK && GET_ENGINE_ID == ET_WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (GET_CAR_ID == CT_TRUCK && GET_BRAKE_SYSTEM_ID == BST_MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (GET_BRAKE_SYSTEM_ID == BST_BOSCH && GET_STEERING_SYSTEM_ID != SST_BOSCH)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}

#endif
