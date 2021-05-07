
#include "RTClib.h"
#include <DMD32.h>

//..........................Fonts...............................//
#include "fonts/SystemFont5x7.h"
#include "fonts/Arial_black_16.h"
#include "fonts/font_modi_15x19.h"
#include "fonts/Comic24.h"
#include "fonts/CHAD.h"
//...............................................................//

DMD dmd(3, 3);
RTC_DS3231 rtc;
hw_timer_t * timer = NULL;

//..............................RTC materials............................//
int _day, _month, _year, _hour12, _hour24, _minute, _second, _dtw;
int hr24;
String st;

//.......................................................................//

//..............................DMD Materials............................//
const long interval = 1000;
unsigned long previousMillis = 0;
char hr_24 [3];
String str_hr_24;
char mn [3];
String str_mn;
char ta [3];
String str_ta;
char mo [3];
String str_mo;
char ye [6];
String str_ye;
char dy [3];
String str_dy;
char mon [3];
String str_mon;

//.......................................................................//

void IRAM_ATTR triggerScan()
{
  dmd.scanDisplayBySPI();
}

void setup () {
  uint8_t cpuClock = ESP.getCpuFreqMHz();
  timer = timerBegin(0, cpuClock, true);
  timerAttachInterrupt(timer, &triggerScan, true);
  timerAlarmWrite(timer, 300, true);
  timerAlarmEnable(timer);

  dmd.clearScreen( true );
  if (! rtc.begin()) {
    while (1);
  }
  //  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (rtc.lostPower()) {
    //    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
  //Clock();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
//    dmd.selectFont(CHAD);
//    dmd.drawString(15, 0, "0", 1, GRAPHICS_NORMAL);
    dmd.selectFont(Comic24);
    dmd.drawString(50, 3, "Eid", 3, GRAPHICS_NORMAL);
    dmd.drawString(4, 25, "Mubarak", 8, GRAPHICS_NORMAL);
  }
}
