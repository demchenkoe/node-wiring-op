#include "extensions.h"

#include "dac7678.h"
#include "drcSerial.h"
#include "max5322.h"
#include "max31855.h"
#include "mcp23s08.h"
#include "mcp23s17.h"
#include "mcp3002.h"
#include "mcp3004.h"
#include "mcp3422.h"
#include "mcp4802.h"
#include "mcp23008.h"
#include "mcp23016.h"
#include "mcp23017.h"
#include "pcf8574.h"
#include "pcf8591.h"
#include "sn3218.h"
#include "sr595.h"
#include "pca9685.h"

IMPLEMENT_EXPORT_INIT(extensions) {
  INIT(dac7678);
  INIT(drcSerial);
  INIT(max5322);
  INIT(max31855);
  INIT(mcp23s08);
  INIT(mcp23s17);
  INIT(mcp3002);
  INIT(mcp3004);
  INIT(mcp3422);
  INIT(mcp4802);
  INIT(mcp23008);
  INIT(mcp23016);
  INIT(mcp23017);
  INIT(pcf8574);
  INIT(pcf8591);
  INIT(sr595);
  INIT(pca9685);
}
