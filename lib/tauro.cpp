#include <napi.h>
#include "tauro.h"
#include <iostream>

using namespace std;

Napi::Object Tauro::initialize(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function members = DefineClass(env, "Tauro", {
        InstanceMethod("listen", &Tauro::listen)
    });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(members);

    env.SetInstanceData(constructor);

    exports.Set("Tauro", members);

    return exports;

}


Tauro::Tauro(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Tauro>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  cout << info.Length() << endl;

//   int length = info.Length();

//   if (length <= 0 || !info[0].IsNumber()) {
//     Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
//     return;
//   }

//   Napi::Number value = info[0].As<Napi::Number>();
//   this->value_ = value.DoubleValue();
}