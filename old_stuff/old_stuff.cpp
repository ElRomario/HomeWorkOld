/*Создать класс «Лифт», представляющий собой предельно упрощенную модель лифта. Класс должен
обеспечить:
▷ установку диапазона движения лифта (нижний
и верхний этаж);
▷ включение / выключение лифта;
▷ возвращение текущего состояния лифта (работает / не работает);
▷ возвращение текущего положения лифта (этаж);
▷ обработку вызова лифта (этаж).
Написать программу, тестирующую класс «Лифт»*/
#include <iostream>

using namespace std;

class Elevator
{
private:
	bool isWorking;
	int floorArraySize;
	int currentFloor;
public:
	Elevator();
	Elevator(int floorCount);
	void setFloor(int floor);
	bool turnOnElevator();
	void displayElevator();
	int whichFloor();
	~Elevator();

};

Elevator::Elevator()
{
	isWorking = false;
	floorArraySize = 0;
	floorArray = new int[floorArraySize];
	currentFloor = 0;
}
Elevator::Elevator(int floorCount)
{
	isWorking = true;
	floorArraySize = floorCount;
	floorArray = new int[floorArraySize];
	currentFloor = 1;
}

void Elevator::setFloor(int floor)
{
	if (floor > floorArraySize || isWorking == false)
	{
		cout << "Elevator Error" << endl;
		return;
	}
	else
	{
		currentFloor = floor;
	}
}

bool Elevator::turnOnElevator()
{
	switch (isWorking)
	{
	case true: cout << "Elevator has been turned off!" << endl; return isWorking = false; break;
	case false: cout << "Elevator has been turned on!" << endl; return isWorking = true; break;
	}
	
}

void Elevator::displayElevator()
{
	if (isWorking == false)cout << "Elevator is off!" << endl;
	else cout << "Elevator is on!" << endl;
	cout << "You are currently on " << currentFloor <<" out of "<<floorArraySize <<" floors"<<endl<<endl;
}

int Elevator::whichFloor()
{
	return currentFloor;
}

Elevator::~Elevator()
{
	
}

void moveElevatorTo(Elevator &elevator)
{
	cout << "Enter floor you would like to visit: ";
	int floor;
	cin >> floor;
	cout << endl;
	elevator.setFloor(floor);
}

void elevatorTest(Elevator& elevator)
{

	elevator.displayElevator();
	cout << "|?|What would you like to do?" << endl<<endl;
	cout << "|*|Enter - 1 to turn on/of elevator" << endl;
	cout << "|*|Enter - 2 to go on floor" << endl;
	cout << "|*|Enter - 0 to exit" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1: elevator.turnOnElevator(); elevator.displayElevator(); elevatorTest(elevator); break;
	case 2: moveElevatorTo(elevator); elevator.displayElevator(); elevatorTest(elevator); break;
	case 0: return;
	}
}
int main()
{
	Elevator elevator(10);
	elevatorTest(elevator);
	

}

