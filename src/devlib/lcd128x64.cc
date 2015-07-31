#include "lcd128x64.h"
#include <lcd128x64.h>

DECLARE(lcd128x64setOrigin);
DECLARE(lcd128x64setOrientation);
DECLARE(lcd128x64orientCoordinates);
DECLARE(lcd128x64getScreenSize);
DECLARE(lcd128x64point);
DECLARE(lcd128x64line);
DECLARE(lcd128x64lineTo);
DECLARE(lcd128x64rectangle);
DECLARE(lcd128x64circle);
DECLARE(lcd128x64ellipse);
DECLARE(lcd128x64putchar);
DECLARE(lcd128x64puts);
DECLARE(lcd128x64update);
DECLARE(lcd128x64clear);
DECLARE(lcd128x64setup);

IMPLEMENT(lcd128x64setOrigin) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x);
  SET_ARGUMENT_NAME(1, y);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(2);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  
  int x = GET_ARGUMENT_AS_INT32(0);
  int y = GET_ARGUMENT_AS_INT32(1);
  
  ::lcd128x64setOrigin(x, y);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64setOrientation) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, orientation);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int orientation = GET_ARGUMENT_AS_INT32(0);
  
  ::lcd128x64setOrientation(orientation);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64orientCoordinates) {
  SCOPE_OPEN();
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(0);
  
  int x, y;
  ::lcd128x64orientCoordinates(&x, &y);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Local<v8::Array> res = v8::Array::New(isolate, 2);
    res->Set(0, v8::Int32::New(isolate, x));
    res->Set(1, v8::Int32::New(isolate, y));
  #else
    v8::Local<v8::Array> res = v8::Array::New(2);
    res->Set(0, v8::Int32::New(x));
    res->Set(1, v8::Int32::New(y));
  #endif
  
  SCOPE_CLOSE(res);
}

IMPLEMENT(lcd128x64getScreenSize) {
  SCOPE_OPEN();
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(0);
  
  int x, y;
  ::lcd128x64getScreenSize(&x, &y);
  
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Local<v8::Array> res = v8::Array::New(isolate, 2);
    res->Set(0, v8::Int32::New(isolate, x));
    res->Set(1, v8::Int32::New(isolate, y));
  #else
    v8::Local<v8::Array> res = v8::Array::New(2);
    res->Set(0, v8::Int32::New(x));
    res->Set(1, v8::Int32::New(y));
  #endif
  
  SCOPE_CLOSE(res);
}

IMPLEMENT(lcd128x64point) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x);
  SET_ARGUMENT_NAME(1, y);
  SET_ARGUMENT_NAME(2, color);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int x = GET_ARGUMENT_AS_INT32(0);
  int y = GET_ARGUMENT_AS_INT32(1);
  int color = GET_ARGUMENT_AS_INT32(2);
  
  ::lcd128x64point(x, y, color);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64line) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x0);
  SET_ARGUMENT_NAME(1, y0);
  SET_ARGUMENT_NAME(2, x1);
  SET_ARGUMENT_NAME(3, y1);
  SET_ARGUMENT_NAME(4, color);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(5);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  
  int x0 = GET_ARGUMENT_AS_INT32(0);
  int y0 = GET_ARGUMENT_AS_INT32(1);
  int x1 = GET_ARGUMENT_AS_INT32(2);
  int y1 = GET_ARGUMENT_AS_INT32(3);
  int color = GET_ARGUMENT_AS_INT32(4);
  
  ::lcd128x64line(x0, y0, x1, y1, color);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64lineTo) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x);
  SET_ARGUMENT_NAME(1, y);
  SET_ARGUMENT_NAME(2, color);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(3);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  
  int x = GET_ARGUMENT_AS_INT32(0);
  int y = GET_ARGUMENT_AS_INT32(1);
  int color = GET_ARGUMENT_AS_INT32(2);
  
  ::lcd128x64lineTo(x, y, color);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64rectangle) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x1);
  SET_ARGUMENT_NAME(1, y1);
  SET_ARGUMENT_NAME(2, x2);
  SET_ARGUMENT_NAME(3, y2);
  SET_ARGUMENT_NAME(4, color);
  SET_ARGUMENT_NAME(5, filled);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(6);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  CHECK_ARGUMENT_TYPE_INT32(5);
  
  int x1 = GET_ARGUMENT_AS_INT32(0);
  int y1 = GET_ARGUMENT_AS_INT32(1);
  int x2 = GET_ARGUMENT_AS_INT32(2);
  int y2 = GET_ARGUMENT_AS_INT32(3);
  int color = GET_ARGUMENT_AS_INT32(4);
  int filled = GET_ARGUMENT_AS_INT32(5);
  
  ::lcd128x64rectangle(x1, y1, x2, y2, color, filled);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64circle) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x);
  SET_ARGUMENT_NAME(1, y);
  SET_ARGUMENT_NAME(2, r);
  SET_ARGUMENT_NAME(3, color);
  SET_ARGUMENT_NAME(4, filled);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(5);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  
  int x = GET_ARGUMENT_AS_INT32(0);
  int y = GET_ARGUMENT_AS_INT32(1);
  int r = GET_ARGUMENT_AS_INT32(2);
  int color = GET_ARGUMENT_AS_INT32(3);
  int filled = GET_ARGUMENT_AS_INT32(4);
  
  ::lcd128x64circle(x, y, r, color, filled);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64ellipse) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, cx);
  SET_ARGUMENT_NAME(1, cy);
  SET_ARGUMENT_NAME(2, xRadius);
  SET_ARGUMENT_NAME(3, yRadius);
  SET_ARGUMENT_NAME(4, color);
  SET_ARGUMENT_NAME(5, filled);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(6);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  CHECK_ARGUMENT_TYPE_INT32(5);
  
  int cx = GET_ARGUMENT_AS_INT32(0);
  int cy = GET_ARGUMENT_AS_INT32(1);
  int xRadius = GET_ARGUMENT_AS_INT32(2);
  int yRadius = GET_ARGUMENT_AS_INT32(3);
  int color = GET_ARGUMENT_AS_INT32(4);
  int filled = GET_ARGUMENT_AS_INT32(5);
  
  ::lcd128x64ellipse(cx, cy, xRadius, yRadius, color, filled);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64putchar) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x);
  SET_ARGUMENT_NAME(1, y);
  SET_ARGUMENT_NAME(2, c);
  SET_ARGUMENT_NAME(3, bgColor);
  SET_ARGUMENT_NAME(4, fgColor);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(5);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  
  int x = GET_ARGUMENT_AS_INT32(0);
  int y = GET_ARGUMENT_AS_INT32(1);
  int c = GET_ARGUMENT_AS_INT32(2);
  int bgColor = GET_ARGUMENT_AS_INT32(3);
  int fgColor = GET_ARGUMENT_AS_INT32(4);
  
  ::lcd128x64putchar(x, y, c, bgColor, fgColor);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64puts) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, x);
  SET_ARGUMENT_NAME(1, y);
  SET_ARGUMENT_NAME(2, string);
  SET_ARGUMENT_NAME(3, bgColor);
  SET_ARGUMENT_NAME(4, fgColor);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(5);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_STRING(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  CHECK_ARGUMENT_TYPE_INT32(4);
  
  int x = GET_ARGUMENT_AS_INT32(0);
  int y = GET_ARGUMENT_AS_INT32(1);
  #if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::String::Utf8Value string(GET_ARGUMENT_AS_STRING(2));
  #else
    v8::String::AsciiValue string(GET_ARGUMENT_AS_STRING(2));
  #endif
  int bgColor = GET_ARGUMENT_AS_INT32(3);
  int fgColor = GET_ARGUMENT_AS_INT32(4);
  
  ::lcd128x64puts(x, y, *string, bgColor, fgColor);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64update) {
  SCOPE_OPEN();
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(0);
  
  ::lcd128x64update();
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64clear) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, color);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(1);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  
  int color = GET_ARGUMENT_AS_INT32(0);
  
  ::lcd128x64clear(color);
  
  SCOPE_CLOSE(UNDEFINED());
}

IMPLEMENT(lcd128x64setup) {
  SCOPE_OPEN();
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(0);
  
  int res = ::lcd128x64setup();
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(lcd128x64) {
  EXPORT_FUNCTION(lcd128x64setOrigin);
  EXPORT_FUNCTION(lcd128x64setOrientation);
  EXPORT_FUNCTION(lcd128x64orientCoordinates);
  EXPORT_FUNCTION(lcd128x64getScreenSize);
  EXPORT_FUNCTION(lcd128x64point);
  EXPORT_FUNCTION(lcd128x64line);
  EXPORT_FUNCTION(lcd128x64lineTo);
  EXPORT_FUNCTION(lcd128x64rectangle);
  EXPORT_FUNCTION(lcd128x64circle);
  EXPORT_FUNCTION(lcd128x64ellipse);
  EXPORT_FUNCTION(lcd128x64putchar);
  EXPORT_FUNCTION(lcd128x64puts);
  EXPORT_FUNCTION(lcd128x64update);
  EXPORT_FUNCTION(lcd128x64clear);
  EXPORT_FUNCTION(lcd128x64setup);
}