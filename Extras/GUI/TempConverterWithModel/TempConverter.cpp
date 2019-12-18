#include "TempConverter.h"

TempConverter::TempConverter()
{
}

//Core "logic" functions do not know about GUI at all
double TempConverter::FahrenheitToCelsius(double fTemp) {
    return 5.0 / 9.0 * (fTemp - 32);
}

double TempConverter::CelsiusToFahrenheit(double cTemp) {
    return 9.0 / 5.0 * cTemp + 32;
}
