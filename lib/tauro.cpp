#include <iostream>
#include "tauro.h"
#include "daq.h"

using namespace Napi;
using namespace std;

/* 
  Constructor function for the Tauro Class
*/
Tauro::Tauro(const Napi::CallbackInfo& info) : ObjectWrap<Tauro>(info) {

  try {

    int argsCount = info.Length();

    if ( argsCount < 7 ) throw argsCount;

    this->jsArgs = new string[argsCount];
    
    try {

      for (int eachArgument = 0; eachArgument <= (int) info.Length() -1; eachArgument++) 

        this->jsArgs[eachArgument] = info[eachArgument].As<String>().Utf8Value();

    }

    catch(...) {

      cout << "Exception was raised" << endl;

    }

    Status initialized = this->InitializeDevice();

    if (initialized) this->status = initialized;

  } 
  
  catch (const std::exception& err) {

    cout << "Error: " << err.what() << endl;

  }

}

Status Tauro::InitializeDevice() {

  const Status returnValue = ERROR;
  
  try {
    
    this->Device = new Daq();

    this->Device->SetSerial(this->jsArgs[4]);
    this->Device->SetSampleRate(stod(this->jsArgs[0]));
    this->Device->SetSamplesPerChannel(stoi(this->jsArgs[1]));
    this->Device->SetLowChannel(stoi(this->jsArgs[2]));
    this->Device->SetHighChannel(stoi(this->jsArgs[3]));
    this->Device->SetInputMode(this->jsArgs[5]);
    this->Device->SetVolts(this->jsArgs[6]);
    this->Device->SetChannelCount(stoi(this->jsArgs[7]));

    return READY;

  }

  catch(std::exception& err) {

    std::cout << "Error initializing Daq device " << err.what() << std::endl;

  }

  return returnValue;

}


/* 
  Get the current operating status of Tauro.
  (Work in progress)
*/
Napi::Value Tauro::GetStatus(const Napi::CallbackInfo& info) {

  Napi::Env env = info.Env();

  Object returnValue = Napi::Object::New(env);

  returnValue.Set("status", (int) this->status);
  returnValue.Set("error", this->status == ERROR ? (bool) true : (bool) false);
  returnValue.Set("device", (string) this->Device->GetSerial());


  return returnValue;

}

/* 
  Start a new (non-blocking) thread to handle the finite scan process.
  (future)
*/
Napi::Value Tauro::Listen(const Napi::CallbackInfo& info) {
  
  return Napi::Number::New(info.Env(), this->status);

}

/* 
  Expose C++ bindings to V8 runtime engine.
  (Work in progress)
*/
Napi::Function Tauro::Init(Napi::Env env) {

  return DefineClass(env, "Tauro", { 

      Tauro::InstanceMethod("listen", &Tauro::Listen),
      Tauro::InstanceMethod("getStatus", &Tauro::GetStatus),

  });

}