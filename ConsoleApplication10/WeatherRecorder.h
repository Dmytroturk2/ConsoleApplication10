#pragma once
#include <vector>
#include <string>
using namespace std;

class WeatherRecorder {
private:
    string date;
    double temperature;
    int humidity;
    double precipitation;
public:
    WeatherRecorder();
    WeatherRecorder(string d, double t, int h, double p);
    string getDate() const;
    double getTemperature() const;
    int getHumidity() const;
    double getPrecipitation() const;
    bool hasPrecipitation() const;
    bool isWarmerThan(const WeatherRecorder& other) const;
    bool isSameDay(const WeatherRecorder& other) const;
    void display() const;
};

class WeatherLog {
private:
    vector<WeatherRecorder> records;
public:
    void addRecord(const WeatherRecorder& record);
    int getCount() const;
    double getAverageTemperature() const;
    string getHottestDay() const;
    string getColdestDay();
    string RainyDays();
    void printAll();
};

