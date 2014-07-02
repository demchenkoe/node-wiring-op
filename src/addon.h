#ifndef _ADDON_H_
#define _ADDON_H_

  #include <node.h>
  #include <node_buffer.h>
  #include <v8.h>
  #include <iostream>
  #include <sstream>
  #include <algorithm>
  #include <initializer_list>
    
  using namespace v8;
  
  template<std::size_t N>
  struct type_of_size { typedef char type[N]; };

  template <typename T, size_t size> 
  char (&sizeof_array_helper(T(&)[size]))[size];

  #define sizeof_array(array) sizeof(sizeof_array_helper(array))
  
  template<typename T>
  void ThrowError(T func, const char* format, ...) {
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, 156, format, args);
    va_end(args);
    
    ThrowException(func(String::New(buffer)));
  }

  template<typename T>
  bool isInList(T value, std::initializer_list<T> values) {
    return !(std::find(values.begin(), values.end(), value) == values.end());
  }
    
  #define DECLARE(name) \
    namespace nodemodule { \
      static Handle<Value> name(const Arguments& args); \
    }
    
  #define IMPLEMENT(name) \
    Handle<Value> nodemodule::name(const Arguments& args)
  
  #define EXPORT_FUNCTION(name)  \
    target->Set(String::NewSymbol(#name), \
      FunctionTemplate::New(nodemodule::name)->GetFunction())
    
  #define EXPORT_CONSTANT_INT(name) \
    target->Set(String::NewSymbol(#name), \
      Int32::New(name), static_cast<PropertyAttribute>(ReadOnly | DontDelete));
  
  #define EXPORT_CONSTANT_STRING(name) \
    target->Set(String::NewSymbol(#name), \
      String::New(name), static_cast<PropertyAttribute>(ReadOnly | DontDelete));
    
  #define EXPORT_CONSTANT_INT_ARRAY(name, array, length) \
    { \
      Local<Array> arr = Array::New(); \
      for (int i = 0; i < length; i++) { \
        arr->Set(i, INT32(array[i])); \
      } \
      target->Set(String::NewSymbol(#name), arr, static_cast<PropertyAttribute>(ReadOnly | DontDelete)); \
    }
    
  #define EXPORT_CONSTANT_STRING_ARRAY(name, array, length) \
    { \
      Local<Array> arr = Array::New(); \
      for (int i = 0; i < length; i++) { \
        arr->Set(i, STRING(array[i])); \
      } \
      target->Set(String::NewSymbol(#name), arr, static_cast<PropertyAttribute>(ReadOnly | DontDelete)); \
    }
  
  #define NODE_MODULE_INIT() \
    namespace nodemodule { \
      void init(Handle<Object> target); \
    } \
    void nodemodule::init(Handle<Object> target)
  #define NODE_MODULE_DECLARE(name) NODE_MODULE(name, nodemodule::init)
  #define IMPLEMENT_EXPORT_INIT(name) void nodemodule::init##name(Handle<Object> target)
  #define DECLARE_EXPORT_INIT(name) \
    namespace nodemodule { \
      void init##name(Handle<Object> target); \
    }
  
  #define INIT(name) nodemodule::init##name(target);
  
  #define SCOPE_OPEN() HandleScope scope
  #define SCOPE_CLOSE(obj) return scope.Close(obj)
  
  #define UNDEFINED() Undefined()
  #define INT32(v) Int32::New(v)
  #define UINT32(v) Uint32::New(v)
  #define STRING(v) String::New(v)
    
  #define THROW_ERROR(fmt, ...) \
    ThrowError(Exception::Error, fmt, __VA_ARGS__); \
    SCOPE_CLOSE(UNDEFINED())
    
  #define THROW_TYPE_ERROR(fmt, ...) \
    ThrowError(Exception::TypeError, fmt, __VA_ARGS__); \
    SCOPE_CLOSE(UNDEFINED())
  
  #define SET_ARGUMENT_NAME(id, name) static const char* arg##id = #name
  #define GET_ARGUMENT_NAME(id) arg##id
  
  #define CHECK_ARGUMENTS_LENGTH_EQUAL(length) \
    if (args.Length() != length) { \
      THROW_ERROR("%s: arguments.length => (%i === %i) === false", __func__, args.Length(), length); \
    }
    
  #define CHECK_ARGUMENT_TYPE(id, istype) \
    if (!args[id]->istype()) { \
      THROW_ERROR("%s: %s(%s) === false", __func__, #istype, GET_ARGUMENT_NAME(id)); \
    }
  
  #define CHECK_ARGUMENT_TYPE_INT32(id) CHECK_ARGUMENT_TYPE(id, IsInt32)
  #define CHECK_ARGUMENT_TYPE_UINT32(id) CHECK_ARGUMENT_TYPE(id, IsUint32)
  #define CHECK_ARGUMENT_TYPE_NUMBER(id) CHECK_ARGUMENT_TYPE(id, IsNumber)
  #define CHECK_ARGUMENT_TYPE_STRING(id) CHECK_ARGUMENT_TYPE(id, IsString)
  #define CHECK_ARGUMENT_TYPE_FUNCTION(id) CHECK_ARGUMENT_TYPE(id, IsFunction)
  #define CHECK_ARGUMENT_TYPE_OBJECT(id) CHECK_ARGUMENT_TYPE(id, IsObject)
  #define CHECK_ARGUMENT_TYPE_NODE_BUFFER(id) \
    if (!(args[id]->IsObject() && node::Buffer::HasInstance(args[id]))) { \
      THROW_ERROR("%s: %s(%s) === false", __func__, "isBuffer", GET_ARGUMENT_NAME(id)); \
    }
  
  #define GET_ARGUMENT_AS_TYPE(id, type) args[id]->type()
  
  #define GET_ARGUMENT_AS_INT32(id) GET_ARGUMENT_AS_TYPE(id, Int32Value)
  #define GET_ARGUMENT_AS_UINT32(id) GET_ARGUMENT_AS_TYPE(id, Uint32Value)
  #define GET_ARGUMENT_AS_NUMBER(id) GET_ARGUMENT_AS_TYPE(id, NumberValue)
  #define GET_ARGUMENT_AS_STRING(id) GET_ARGUMENT_AS_TYPE(id, ToString)
  #define GET_ARGUMENT_AS_LOCAL_FUNCTION(id) Local<Function>::Cast(args[id])
  #define GET_ARGUMENT_AS_PERSISTENT_FUNCTION(id) Persistent<Function>::New(GET_ARGUMENT_AS_LOCAL_FUNCTION(id))
  
  #define LIST(...) { __VA_ARGS__ }
  #define CHECK_ARGUMENT_IN_STRINGS(id, value, T) \
    if (!isInList<std::string>(std::string(*value), LIST T)) { \
      THROW_ERROR("%s: arguments['%s'] => (\"%s\" in %s) === false", __func__, GET_ARGUMENT_NAME(id), std::string(*value).c_str(), #T); \
    }
    
  #define CHECK_ARGUMENT_IN_INTS(id, value, T) \
    if (!isInList<int>(value, LIST T)) { \
      THROW_ERROR("%s: arguments['%s'] => (%i in %s) === false", __func__, GET_ARGUMENT_NAME(id), value, #T); \
    }

#endif