// https://github.com/nodejs/node-addon-examples/tree/master/6_object_wrap/node-addon-api
// https://github.com/nodejs/node-addon-examples/blob/master/object-wrap-demo/node-addon-api/src/object_wrap_demo.cc
// https://github.com/nodejs/node-addon-api/blob/master/doc/basic_types.md

#include <napi.h>
#include "tauro.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::String name = Napi::String::New(env, "Tauro");
    exports.Set(name, Tauro::Init(env));

    return exports;
    
}

Napi::Object InitTauro(Napi::Env env, Napi::Object exports) {
  return Init(env, exports);
}

NODE_API_MODULE(addon, InitTauro)