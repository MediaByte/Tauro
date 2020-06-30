#ifndef TAURO
#define TAURO

#include <napi.h>
#include <queue>
#include "event.h"

enum Status { ERROR, READY, RUNNING };

class Tauro : public Napi::ObjectWrap<Tauro> {
  
  public:
    Status status;

    static Napi::Object initialize(Napi::Env, Napi::Object);

    Napi::Value listen(const Napi::CallbackInfo& info);

    Tauro(const Napi::CallbackInfo& info);
  
  private:
    queue<Event> q;
};


#endif