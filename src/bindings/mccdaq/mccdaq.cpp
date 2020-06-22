#include <string>
#include <iostream>

using namespace std;

/*
    INTERFACE BRIDGE:
    Here we create the class that is going to bridge communication between the V8 javascript runtime engine
    and the MCC DAQ device Universal library.

    MCC DAQ hardware driver (universal library) API reference in C++:
    https://www.mccdaq.com/PDFs/Manuals/UL-Linux/c/index.html

*/


enum Status { ERROR, READY, RUNNING };

class Daq {
    
    public:
        Status status();

        Daq(string serial) {
            bool found = this->initialize(serial);
            
            if (found) {
                this->state = READY;
                return;
            }
            
            this->state = ERROR;

        }

    private:
        Status state;
        string serial, samplesPerChannel;
        int lowChannel, highChannel, channelCount, rate;
        bool initialize(string);

};

bool Daq::initialize(string serial) {
    // TODO: 
    // Initialize the data acquisition system from the javascript engine here
    cout << "1. Initializing hardware" << endl;
    
    //Access usb devices and loop through to find the matching serial number
    cout << "2. Serial found: " << serial << endl;

    // Initialize the data acquisition system
    cout << "3. Hardware initialized" << endl;

    //Currently in development, but this blueprint should return true or false.
    return true;
}