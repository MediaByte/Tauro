#include <string>

class Sample {
    public:
        unsigned int channels;
        time_t timestamp;
        long *data{ new long[channels]{ } };

        Sample getData();

        Sample(const long *data) { 
            timestamp = time_t(); 
            channels = *(&data + 1) - data; 
        };

};

Sample Sample::getData(){
    return *this;
}