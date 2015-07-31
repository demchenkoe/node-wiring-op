#include "addon.h"
#include <stdarg.h>
#include <strings.h>

bool find_string(const char* string, const char* array[], size_t s) {
  for (size_t i = 0; i < s; i++) {
    if (!strcasecmp(string, array[i])) {
      return true;
    }
  }
  return false;
}

bool find_int(const int value, const int array[], size_t s) {
  for (size_t i = 0; i < s; i++) {
    if (value == array[i]) {
      return true;
    }
  }
  return false;
}

#if NODE_VERSION_AT_LEAST(0, 11, 0)
void throw_error(v8::Isolate* isolate, const char* format, ...) {
#else
void throw_error(const char* format, ...) {
#endif
  char buffer[256];
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, 156, format, args);
  va_end(args);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    isolate->ThrowException(v8::Exception::Error(v8::String::NewFromUtf8(isolate, buffer)));
  #else
    v8::ThrowException(v8::Exception::Error(v8::String::New(buffer)));
  #endif
}