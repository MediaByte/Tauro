#include <iostream>
#include "tauro.h"

using namespace Napi;

/* 
  Constructor function for the Tauro Class
*/
Tauro::Tauro(const Napi::CallbackInfo& info) : ObjectWrap<Tauro>(info) {
  Napi::Env env = info.Env();

  if (info.Length() < 6 ) {
    Napi::TypeError::New(env, "Invalid argument count supplied.").ThrowAsJavaScriptException();
    
    return;

  }

  this->rate =                info[0].As<String>().Utf8Value();
  this->samples_per_channel = info[1].As<String>().Utf8Value();
  this->low_channel =         info[2].As<String>().Utf8Value();
  this->high_channel =        info[3].As<String>().Utf8Value();
  this->serial =              info[4].As<String>().Utf8Value();
  this->input_mode =          info[5].As<String>().Utf8Value();
  this->volts =               info[6].As<String>().Utf8Value();


  this->status = READY;

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