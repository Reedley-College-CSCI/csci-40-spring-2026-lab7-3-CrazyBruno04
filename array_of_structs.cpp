//Bruno Ochoa, I
#include <iostream>
#include <fstream>
using namespace std;

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.

struct TemperatureRecord {
    int day;
    int temperature;
};


// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord temps[], int & size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord temps[], int size);
TemperatureRecord findMin(const TemperatureRecord temps[], int size);
TemperatureRecord findMax(const TemperatureRecord temps[], int size);
double findAverage(const TemperatureRecord temps[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
	TemperatureRecord temps[MAX_DAYS];
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
	readTemperatures(temps, size);
    // TODO: Step 4 - Print the temperatures
	printTemperatures(temps, size);
    // TODO: Step 5 - Compute and display min, max, and average temperature
	TemperatureRecord min = findMin(temps, size);
	TemperatureRecord max = findMax(temps, size);
	double average = findAverage(temps, size);

	cout << "Minimum Temperature: Day" << min.day << " = " << min.temperature << endl;
	cout << "Maximum Temperature: Day" << max.day << " = " << max.temperature << endl;
	cout << "Average Temperature: " << average << endl;
    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord temps[], int& size) {
	ifstream infile("temps.txt");

	if (!infile) {
		cout << "Error opening file!" << endl;
		return;
	}

	size = 0;

	while (file >> temps[size].day >> temps[size].temperature) && size < MAX_DAYS) {
		size++;
}

file.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const TemperatureRecord temps[], int size) {
	cout << "Day\tTemp" << endl;
	
	for (int i = 0; i < size; i++) {
		cout << temps[i].day << "\t" << temps[i].temperature << endl;
	}
}
// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature
TemperatureRecord findMin(const TemperatureRecord temps[], int size) {
	TemperatureRecord min = temps[0];
	for (int i = 1; i < size; i++) {
		if (temps[i].temperature < min.temperature) {
			min = temps[i];
		}
	}
	return min;
}
// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature
TemperatureRecord findMax(const TemperatureRecord temps[], int size) {
	TemperatureRecord max = temps[0];
	for (int i = 1; i < size; i++) {
		if (temps[i].temperature > max.temperature) {
			max = temps[i];
		}
	}
	return max;
}
// TODO: Step 10 - Implement findAverage()
double findAverage(const TemperatureRecord temps[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += temps[i].temperature;
	}
	return double sum / size;
}

// Compute and return the average temperature
