#include "WatchFace.h"
#include "MultiWatchy.h"
#include "DSEG7_Classic_Bold_53.h"

void WatchFace::drawWatchFace() {
  watch->display.fillRect(0, 0, 200, 200, GxEPD_BLACK);
  watch->display.setTextColor(GxEPD_WHITE);
  watch->display.setFont(&DSEG7_Classic_Bold_53);
  watch->display.setCursor(5, 53 + 60);
  if (watch->currentTime.Hour < 10) {
    watch->display.print("0");
  }
  watch->display.print(watch->currentTime.Hour);
  watch->display.print(":");
  if (watch->currentTime.Minute < 10) {
    watch->display.print("0");
  }
  watch->display.println(watch->currentTime.Minute);
}
