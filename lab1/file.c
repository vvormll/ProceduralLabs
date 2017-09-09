#include <stdio.h>
#include <stdlib.h>

#define LOWEST_KELVIN 0
#define LOWEST_CELSIUS -273.15
#define LOWEST_FAHRENHEIT -459.67

float fahrenheitToCelsius(float degrees) {
	return (degrees - 32) * 5 / 9;
}

float fahrenheitToKelvin(float degrees) {
	return (degrees + 459.67) * 5 / 9;
}

float celsiusToFahrenheit(float degrees) {
	return degrees * 9 / 5 + 32;
}

float celsiusToKelvin(float degrees) {
	return degrees + 273.15;
}

float kelvinToCelsius(float degrees) {
	return degrees - 273.15;
}

float kelvinToFahrenheit(float degrees) {
	return degrees * 9 / 5 - 459.67;
}

void printUsage(char* filename) {
	printf("Usage: %s temperature [scale]\n", filename);
	printf("temperature - temperature value\n");
	printf("scale - (optional) scale type\n");
	printf("supported scales: Celsius - C, Fahrenheit - F, Kelvin - K\n");
}

void printLowerThanAbsoluteZero(char scaleType) {
	printf("Error: specified temperature is lower than absolute zero in %c\n", scaleType);
}

void printUnknownScaleType(char scaleType) {
	printf("Error: unknown scale type %c\n", scaleType);
}

void convertCelsius(float degrees) {
	printf("%.2f F\n", celsiusToFahrenheit(degrees));
	printf("%.2f K\n", celsiusToKelvin(degrees));
}

void convertFahrenheit(float degrees) {
	printf("%.2f C\n", fahrenheitToCelsius(degrees));
	printf("%.2f K\n", fahrenheitToKelvin(degrees));
}

void convertKelvin(float degrees) {
	printf("%.2f C\n", kelvinToCelsius(degrees));
	printf("%.2f F\n", kelvinToFahrenheit(degrees));
}

void checkAndConvert(float degrees, char scaleType) {
	switch (scaleType) {
		case 'C':
			if (degrees < LOWEST_CELSIUS) {
				printLowerThanAbsoluteZero(scaleType);
			} else {
				convertCelsius(degrees);
			}
			break;
		case 'F':
			if (degrees < LOWEST_FAHRENHEIT) {
				printLowerThanAbsoluteZero(scaleType);
			} else {
				convertFahrenheit(degrees);
			}
			break;
		case 'K':
			if (degrees < LOWEST_KELVIN) {
				printLowerThanAbsoluteZero(scaleType);
			} else {
				convertKelvin(degrees);
			}
			break;
		default:
			printUnknownScaleType(scaleType);
			exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv) {

	char* filename = argv[0];

	if (argc < 2 || argc > 3) {
		printUsage(filename);
		return EXIT_FAILURE;
	}

	char* tempString = argv[1];
	float degrees = atof(tempString);

	if (argc == 3) {
		char scaleType = argv[2][0];
		checkAndConvert(degrees, scaleType);
	} else if (argc == 2) {
		printf("%.2f C:\n", degrees);
		checkAndConvert(degrees, 'C');
		printf("\n");
		printf("%.2f F:\n", degrees);
		checkAndConvert(degrees, 'F');
		printf("\n");
		printf("%.2f K:\n", degrees);
		checkAndConvert(degrees, 'K');
	}

	return EXIT_SUCCESS;
}
