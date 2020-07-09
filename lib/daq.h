#ifndef TAURO_DAQ
#define TAURO_DAQ

#include <string>
#include <iostream>

using namespace std;

class Daq {
    
    public:
        void SetSerial(string);
        void SetSampleRate(double);
        void SetSamplesPerChannel(int);
        void SetLowChannel(int);
        void SetHighChannel(int);
        void SetInputMode(string);
        void SetVolts(string);
        void SetChannelCount(int);
        
        string GetSerial();
        double GetSampleRate();
        int GetSamplesPerChannel();
        int GetLowChannel();
        int GetHighChannel();
        string GetInputMode();
        void GetVolts();
        int GetChannelCount();

    private:
        double rate;
        int channelCount;
        int samples_per_channel;
        int low_channel;
        int high_channel;
        string serial;
        string input_mode;
        string volts;

};


#endif