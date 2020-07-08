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
        Daq(string);

        Status GetStatus();
        
        void SetSerial(string);
        void SetSampleRate(double);
        void SetSamplesPerChannel(int);
        void SetLowChannel(int);
        void SetHighChannel(int);
        void SetInputMode(string);
        void SetVolts(string);
        
        void GetSerial(string);
        void GetSampleRate(int);
        void GetSamplesPerChannel(int);
        void GetLowChannel(int);
        void GetHighChannel(int);
        void GetInputMode(string);
        void GetVolts(string);

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