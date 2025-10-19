//This piece of code deals with the drone's decision making
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

int main() {

	int battery = 100;
	int weather = 0;
	bool obstacle = 0;
	int battery_drain = 0;
	string flight_status;
	char package = 'A';
	srand(time(0));

	cout << "Welcome. The day has started and the batter is at 100%." << endl;

	//The following piece of code deals with weather
	for (; package <= 'C'; package++) {
		weather = rand() % (3 - 2) + 1;
		if (weather == 1) {
			//The weather is sunny so no delay
			battery_drain = rand() % (25 - 10) + 10;
			battery = battery - battery_drain;
			cout << "The object "<< package<< " was delivered in sunny weather.Remaining Battery : " << battery << endl;
		}
		else if (weather == 2) {
			//Windy weather
			if (battery < 40) {
				cout << "Return to base to recharge" << endl;
				battery = battery + 10;
				cout << "Battery after charging: " << battery << endl;
			}
			else {
				battery_drain = rand() % (25 - 10) + 10;
				battery = battery - battery_drain;
				cout << "The object "<<package<< " was delivered. Remaining Battery : " << battery << endl;
			}
		}
		else if (weather == 3) {
			//Rainy Weather
			flight_status = "Delayed";
			battery = battery - 0;

		}

	}


	//This piece deals with obstacles. To be ordered/arranged later.
	obstacle = rand() % (1 - 0) + 1;
	if (obstacle == 1) {
		battery_drain = rand() % (25 - 10) + 10;
		battery = battery - (battery_drain + 5);
		cout << "The flight was rerouted. Battery Remaining: " << battery << endl;
	}
	else {
		battery_drain = rand() % (25 - 10) + 10;
		battery = battery - battery_drain;
		cout << "The object was delievered normally. Battery Remaining: " << battery << endl;
	}

	_getch();
	return 0;
}