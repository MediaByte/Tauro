#include <string>
#include "sample.h"

using namespace std;

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