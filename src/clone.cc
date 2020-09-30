#ifndef BUILDING_NODE_EXTENSION
#define BUILDING_NODE_EXTENSION
#endif  // BUILDING_NODE_EXTENSION
// #include <node.h>
#include "nan.h"

using namespace v8;
//using namespace Nan;

NAN_METHOD(Clone) {
  Nan::HandleScope scope;
  Handle<Value>arg = info[0];
  if (arg->IsObject()) {
    Handle<Object>obj = Handle<Object>::Cast(arg);
    Handle<Object>newObj = Handle<Object>::Cast(obj->Clone());
    info.GetReturnValue().Set(newObj);
    return;
  }
  info.GetReturnValue().Set(arg);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New<String>("clone").ToLocalChecked(),
      Nan::GetFunction(Nan::New<FunctionTemplate>(Clone)).ToLocalChecked());
}

NODE_MODULE(clone, Init)
