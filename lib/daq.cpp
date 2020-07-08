#include "daq.h"

/*
    Constructor Function for the Daq class
*/
Daq::Daq(const string serial) {

    try {

        if (!serial) {
            return;
        }

        this->SetSerial(serial);

    }

    catch (const std::exception& err) {

        using namespace std;

        cout << err.what() << endl;
        
    }
}