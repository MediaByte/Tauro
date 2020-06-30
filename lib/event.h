#ifndef EVENT_OBJECT
#define EVENT_OBJECT

#include <string>
#include "sample.h"

using namespace std;

class Event {
    public:
        Event(const Sample *data, string typeOf_sensor) {
            this->initialize(data, typeOf_sensor);
        }

    private:
        void initialize(const Sample*, string);
        const Sample* reading;
        string sensor;
        
};

void Event::initialize(const Sample *data, string typeOf_sensor) {
    this->sensor = typeOf_sensor;
    this->reading = data;
}


#endif