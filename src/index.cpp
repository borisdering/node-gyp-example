#include <napi.h>
#include <string>
#include "greeting.h"

Napi::String greetFunction(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string name = (std::string) info[0].ToString();

    std::string result = greet(name);

    return Napi::String::New(env, result);
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {

    exports.Set(
        Napi::String::New(env, "greet"),
        Napi::Function::New(env, greetFunction)
    );

    return exports;
}

NODE_API_MODULE(greet, Init);