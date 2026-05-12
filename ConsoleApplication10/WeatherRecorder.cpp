#include "WeatherRecorder.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructors
WeatherRecorder::WeatherRecorder() {
    date = "";
    temperature = 0.0;
    humidity = 0;
    precipitation = 0.0;
}

WeatherRecorder::WeatherRecorder(string d, double t, int h, double p) {
    this->date = d;
    this->temperature = t;
    this->humidity = h;
    this->precipitation = p;
}

//methods WR
string WeatherRecorder::getDate() const {
    return date;
}

double WeatherRecorder::getTemperature() const {
    return temperature;
}

int WeatherRecorder::getHumidity() const {
    return humidity;
}

double WeatherRecorder::getPrecipitation() const {
    return precipitation;
}

bool WeatherRecorder::hasPrecipitation() const {
    return precipitation > 0.0;
}

bool WeatherRecorder::isWarmerThan(const WeatherRecorder& other) const {
    return temperature > other.temperature;
}

bool WeatherRecorder::isSameDay(const WeatherRecorder& other) const {
    return date == other.date;
}

void WeatherRecorder::display() const {
    cout << "[" << date << "] Temp: " << temperature << "° Precipitation: " << humidity << "% Humidity: " << precipitation << "mm" << endl;
}

//methods WL

void WeatherLog::addRecord(const WeatherRecorder& record) {
    records.push_back(record);
}

int WeatherLog::getCount() const {
    return records.size();
}

double WeatherLog::getAverageTemperature() const {
    if (records.empty()) return 0.0;
    double totalTemp = 0.0;
    for (const auto& record : records) {
        totalTemp += record.getTemperature();
    }
    return totalTemp / records.size();
}

string WeatherLog::getHottestDay() const {
    if (records.empty()) return "No records";
    const WeatherRecorder* hottest = &records[0];
    for (const auto& record : records) {
        if (record.isWarmerThan(*hottest)) {
            hottest = &record;
        }
    }
	return hottest->getDate();
}

string WeatherLog::getColdestDay() {
    if (records.empty()) return "No records";
    const WeatherRecorder* coldest = &records[0];
    for (const auto& record : records) {
        if (coldest->isWarmerThan(record)) {
            coldest = &record;
        }
    }
    return coldest->getDate();
}

string WeatherLog::RainyDays() {
    string rainyDays = "";
    for (const auto& record : records) {
        if (record.hasPrecipitation()) {
            rainyDays += record.getDate() + " ";
        }
    }
    return rainyDays.empty() ? "No rainy days" : rainyDays;
}

void WeatherLog::printAll() {
    for (const auto& record : records) {
        record.display();
    }
}
