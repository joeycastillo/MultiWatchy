class SunriseWatchFace : public WatchFace {
  public:
    void drawWatchFace() {
        watch->display.fillRect(0, 0, 200, 200, GxEPD_WHITE);
        watch->display.drawBitmap(0, 0, sunriseset, 200, 200, GxEPD_BLACK);
    }
};

class TideChartWatchFace : public WatchFace {
  public:
    void drawWatchFace() {
        watch->display.fillRect(0, 0, 200, 200, GxEPD_WHITE);
        watch->display.drawBitmap(0, 0, tides, 200, 200, GxEPD_BLACK);
    }
};

class MoonPhaseWatchFace : public WatchFace {
  public:
    void drawWatchFace() {
        watch->display.fillRect(0, 0, 200, 200, GxEPD_WHITE);
        watch->display.drawBitmap(0, 0, moon, 200, 200, GxEPD_BLACK);
    }
};
