#include <iostream>
#include "WeatherRecorder.h"

using namespace std;

int main()
{
    cout << "=== Weather Recorder System ===" << endl << endl;

    // Створення об'єктів двома способами
    cout << "1. Creating WeatherRecord objects:" << endl;
    cout << "   - Using parameterized constructor" << endl;
    cout << "   - Using default constructor" << endl << endl;

    // Через конструктор з параметрами
    WeatherRecorder rec1("2024-01-10", 5.5, 65, 2.3);
    WeatherRecorder rec2("2024-01-11", 3.2, 70, 0.0);
    WeatherRecorder rec3("2024-01-12", 8.1, 60, 1.5);
    WeatherRecorder rec4("2024-01-13", 6.7, 75, 3.2);
    WeatherRecorder rec5("2024-01-14", 4.3, 80, 0.0);

    // Через конструктор за замовчуванням
    WeatherRecorder rec6;
    rec6 = WeatherRecorder("2024-01-15", 7.2, 68, 0.8);

    // Додавання записів до журналу
    cout << "2. Adding 6 records to the log:" << endl;
    WeatherLog log;
    log.addRecord(rec1);
    log.addRecord(rec2);
    log.addRecord(rec3);
    log.addRecord(rec4);
    log.addRecord(rec5);
    log.addRecord(rec6);
    cout << "   Total records: " << log.getCount() << endl << endl;

    // Вивід повного журналу
    cout << "3. Full weather log:" << endl;
    log.printAll();
    cout << endl;

    // Вивід середної, мінімальної та максимальної температури
    cout << "4. Temperature statistics:" << endl;
    cout << "   Average temperature: " << log.getAverageTemperature() << "°C" << endl;
    cout << "   Hottest day: " << log.getHottestDay() << endl;
    cout << "   Coldest day: " << log.getColdestDay() << endl << endl;

    // Вивід списку днів з опадами
    cout << "5. Rainy days:" << endl;
    cout << "   " << log.RainyDays() << endl << endl;

    // Виклик методів isWarmerThan() і isSameDay()
    cout << "6. Comparison methods:" << endl;
    cout << "   rec1 (" << rec1.getDate() << ", " << rec1.getTemperature() << "°C) is warmer than rec2 ("
         << rec2.getDate() << ", " << rec2.getTemperature() << "°C): "
         << (rec1.isWarmerThan(rec2) ? "Yes" : "No") << endl;
    cout << "   rec1 (" << rec1.getDate() << ") is same day as rec2 ("
         << rec2.getDate() << "): "
         << (rec1.isSameDay(rec2) ? "Yes" : "No") << endl;
    cout << "   rec1 (" << rec1.getDate() << ") is same day as rec1: "
         << (rec1.isSameDay(rec1) ? "Yes" : "No") << endl;

    return 0;
}