#include <string>
#include <sample.h>

using namespace std;

/*
    EVENT DRIVEN:
    Here we create the class that is going to represent a single read from the data acquisition system. 
    This blueprint provides a context for the user interface.

    MCC DAQ hardware driver (universal library) API reference in C++:
    https://www.mccdaq.com/PDFs/Manuals/UL-Linux/c/index.html

*/

class Event {
    public:
        string sensor;
        const Sample* reading;

        Event(const Sample *event, string type_of_sensor) {
            initialize(event, type_of_sensor);
        }

    private:
        void initialize(const Sample*, string);
};

void Event::initialize(const Sample *event, string type_of_sensor) {
    this->sensor = type_of_sensor;
    this->reading = event;
}