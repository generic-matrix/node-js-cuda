#include <stdio.h>
#include<string.h>
#include <math.h>
#include <nan.h>

float vecAdd_wrapper(float a,float b);
float vecSub_wrapper(float a,float b);
float vecExp_wrapper(float a);
float vecMul_wrapper(float a,float b);
float vecPow_wrapper(float a,float b);

using v8;
using Nan;

void Add(const FunctionCallbackInfo<Value>& info) {
  Local<Context> context = info.GetIsolate()->GetCurrentContext();

  if (info.Length() < 3) {
    ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[1]->IsNumber() || !info[2]->IsNumber()) {
    ThrowTypeError("Wrong arguments");
    return;
  }

  double arg0 = info[1]->NumberValue(context).FromJust();
  double arg1 = info[2]->NumberValue(context).FromJust();
  int type_info=  info[0]->NumberValue(context).FromJust();
  if(type_info==0){
        float res=vecAdd_wrapper(arg0,arg1);
        Local<Number> num = New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==1){
        float res=vecSub_wrapper(arg0,arg1);
        Local<Number> num = New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==2){
        float res=vecMul_wrapper(arg0,arg1);
        Local<Number> num = New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==3){
        float res=vecExp_wrapper(arg0);
        Local<Number> num = New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==4){
        float res=vecPow_wrapper(arg0,arg1);
        Local<Number> num = New(res);
        info.GetReturnValue().Set(num);
  }else{
        Local<Number> num = New(-1);
        info.GetReturnValue().Set(num);
  }
}

void Init(Local<Object> exports) {
  Local<Context> context = exports->CreationContext();
  exports->Set(context,
               New("math_func").ToLocalChecked(),
               New<FunctionTemplate>(Add)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(addon, Init)

