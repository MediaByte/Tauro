#pragma once

#ifndef TAURO
#define TAURO

#include <napi.h>

enum Status { ERROR = 0, READY = 1, RUNNING = 2, CONFIGURE = 3 };

class Tauro : public Napi::ObjectWrap<Tauro> {
  
  public:
    Tauro(const Napi::CallbackInfo& info);
    static Napi::Function Init(Napi::Env env);
    Napi::Value Listen(const Napi::CallbackInfo& info);
    Napi::Value GetStatus(const Napi::CallbackInfo& info);
    
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