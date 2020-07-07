#pragma once

#ifndef TAURO_DAQ
#define TAURO_DAQ


#include <string>
#include <iostream>

#include "uldaq.h"
#include "tauro.h"
#include "utility.h"

class Daq {
    
    public:
    Daq(string)
        Status GetStatus();
        void SetSampleRate(int);
        void SetSamplesPerChannel(int);
        void SetLowChannel(int);
        void SetHighChannel(int);
        void SetInputMode(string);
        void SetVolts(string);

    private:
        std::string rate;
        std::string samples_per_channel;
        std::string low_channel;
        std::string high_channel;
        std::string serial;
        std::string input_mode;
        std::string volts;

        Status status;

};


#endif