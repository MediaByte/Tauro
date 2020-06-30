// https://github.com/nodejs/node-addon-examples/tree/master/6_object_wrap/node-addon-api

#include <napi.h>
#include "tauro.h"

Napi::Object InitTauro(Napi::Env env, Napi::Object exports) {
  return Tauro::initialize(env, exports);
}

NODE_API_MODULE(addon, InitTauro)