#include "MultiWatchy.h"
#include "WatchFace.h"
#include "settings.h"
#include "bitmaps.h"
#include "WatchFaces.h"

// This demo shows four example watch faces. Aside from the first watch face,
// they don't represent real data; they're just examples to spark the imagination
// about what may be possible with additional watch faces.

// * The first watch face is a basic 7-segment time display, matching the basic
//   Watchy behavior without a custom subclass.
// * The second watch face displays an example of sunrise and sunset times. This
//   data is currently returned in the weather object, and could be added easily.
// * The third watch face displays a hypothetical tide chart. This would require
//   making use of another API.
// * The fourth watch face displays the phase of the moon. For this one, we'd
//   only need the current date and time; moon phase can be calculated offline.

// Move to the next watch face with the Down button.
// Move to the previous watch face with the Up button.
// If you go past the first or last watch face, you will loop around.
// You may access the menu from any watch face using the Menu button.

MultiWatchy watchy(settings);

void setup() {
  watchy.addWatchFace(new WatchFace());
  watchy.addWatchFace(new SunriseWatchFace());
  watchy.addWatchFace(new TideChartWatchFace());
  watchy.addWatchFace(new MoonPhaseWatchFace());

  watchy.init();
}

void loop() {
}
