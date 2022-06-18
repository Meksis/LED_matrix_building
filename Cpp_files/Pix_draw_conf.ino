byte ihue = 0;
byte fade_delay = 1;

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void rainbow_fade() {                         //-m2-FADE ALL LEDS THROUGH HSV RAINBOW
  ihue++;
  if (ihue > 255) {
    ihue = 0;
  }
  for (int idex = 0 ; idex < NUM_LEDS; idex++ ) {
    leds[idex] = CHSV(ihue, 255, 255);
    delay(fade_delay);
  }
  LEDS.show();
  delay(20);
}

void strip_setup()
{
  ihue = 0;
  for (int idex = 0; idex < NUM_LEDS; idex++)
  {
    ihue = ihue + 3;
    if (ihue > 255)
    {
      ihue = 0;
    }
    leds[idex] = CHSV(ihue, 255, 255);
    LEDS.show();
    delay(fade_delay);
  }


  delay(250);
  one_color_all(0, 0, 0);
  one_color_all(0, 255, 0);
  delay(100);
  ;

}

void tests()
{
  for (int idex = 0; idex < NUM_LEDS; idex++)
  {
    leds[idex] = CRGB(0, 0, 0);
    LEDS.show();
    delay(2000);
    leds[0] = CRGB(255, 255, 255);
    LEDS.show();
    delay(2000);
  }
}
