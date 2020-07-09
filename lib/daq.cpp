#include <string>
#include "daq.h"

#define MAX_DEV_COUNT  100

using namespace std; 

void Daq::SetSerial(string serial) {

    this->serial = serial;

}

void Daq::SetChannelCount(int count) {

    this->channelCount = count;

}

void Daq::SetSampleRate(double rate) {

    this->rate = rate;

}

void Daq::SetLowChannel(int low_channel) {

    this->low_channel = low_channel;

}

void Daq::SetHighChannel(int high_channel) {

    this->high_channel = high_channel;

}

void Daq::SetSamplesPerChannel(int samples_per_channel) {

    this->samples_per_channel = samples_per_channel;

}

void Daq::SetInputMode(string input_mode) {

    this->input_mode = input_mode;

}

void Daq::SetVolts(string volts) {

    this->volts = volts;

}

string Daq::GetSerial() {

    return this->serial;

}

double Daq::GetSampleRate() {

    return this->rate;

}

int Daq::GetChannelCount() {

    return this->channelCount;

}
