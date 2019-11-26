#include <stdio.h>
#include<string.h>
#include <math.h>
float vecAdd_wrapper(float a,float b);
float vecSub_wrapper(float a,float b);
float vecExp_wrapper(float a);
float vecMul_wrapper(float a,float b);
float vecPow_wrapper(float a,float b);

/*
Napi::Value Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  float a = info[1].As<Napi::Number>().FloatValue();
  float b = info[2].As<Napi::Number>().FloatValue();

  if(type_info=="add"){
        //float res=vecAdd_wrapper(arg0,arg1);
        Napi::Number num = Napi::Number::New(env,a+b);
        return num;
  }else if(type_info=="sub"){
        //float res=vecSub_wrapper(arg0,arg1);
        Napi::Number num = Napi::Number::New(env,a-b);
        return num;
  }else if(type_info=="mul"){
        //float res=vecMul_wrapper(arg0,arg1);
        Napi::Number num = Napi::Number::New(env,a*b);
        return num;
  }else if(type_info=="exp"){
        //float res=vecExp_wrapper(arg0);
        Napi::Number num = Napi::Number::New(env,exp(a));
        return num;
  }else if(type_info=="pow"){
        //float res=vecPow_wrapper(arg0,arg1);
        Napi::Number num = Napi::Number::New(env,pow(a,b));
        return num;
  }else{
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
  }
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "math_func"), Napi::Function::New(env, Add));
  return exports;
}

NODE_API_MODULE(addon, Init)
*/


#include <nan.h>

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  if (info.Length() < 3) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[1]->IsNumber() || !info[2]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }

  double arg0 = info[1]->NumberValue(context).FromJust();
  double arg1 = info[2]->NumberValue(context).FromJust();
  int type_info=info[0]->NumberValue();
  if(type_info==0){
        float res=vecAdd_wrapper(arg0,arg1);
        v8::Local<v8::Number> num = Nan::New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==1){
        float res=vecSub_wrapper(arg0,arg1);
        v8::Local<v8::Number> num = Nan::New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==2){
        float res=vecMul_wrapper(arg0,arg1);
        v8::Local<v8::Number> num = Nan::New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==3){
        float res=vecExp_wrapper(arg0);
        v8::Local<v8::Number> num = Nan::New(res);
        info.GetReturnValue().Set(num);
  }else if(type_info==4){
        float res=vecPow_wrapper(arg0,arg1);
        v8::Local<v8::Number> num = Nan::New(res);
        info.GetReturnValue().Set(num);
  }else{
        v8::Local<v8::Number> num = Nan::New(-1);
        info.GetReturnValue().Set(num);
  }
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();
  exports->Set(context,
               Nan::New("math_func").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Add)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(addon, Init)

