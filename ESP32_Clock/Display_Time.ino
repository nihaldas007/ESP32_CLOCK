void Clock() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; //-> save the last time

    GetDateTime(); //-> Retrieve time and date data from DS1307
    //..............................................Hour.........................................................//
    dmd.selectFont(Font_15x19);

    str_hr_24 = String(_hour24);
    str_hr_24.toCharArray(hr_24, 3);

    if (_hour24 < 10) {
      dmd.drawString(9, 6, "0", 1, GRAPHICS_NORMAL);
      dmd.drawString(25, 6, hr_24, 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(9, 6, hr_24, 3, GRAPHICS_NORMAL);
    }

    if (_second % 2 == 0) {
      dmd.drawFilledBox(46, 13, 50, 8, GRAPHICS_OR);
      dmd.drawFilledBox(46, 22, 50, 17, GRAPHICS_OR);
    }
    else {
      dmd.drawFilledBox(46, 13, 50, 8, GRAPHICS_NOR);
      dmd.drawFilledBox(46, 22, 50, 17, GRAPHICS_NOR);
    }
    //..........................................Minutes...................................................//

    dmd.selectFont(Font_15x19);
    str_mn = String(_minute);
    str_mn.toCharArray(mn, 3);

    if (_minute < 10) {
      dmd.drawString(56, 6, "0", 1, GRAPHICS_NORMAL);
      dmd.drawString(72, 6, mn, 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(56, 6, mn, 2, GRAPHICS_NORMAL);
    }

    dmd.selectFont(Arial_Black_16);
    str_ta = String(_day);
    str_ta.toCharArray(ta, 3);
    //.....................................DAY..........................................//
    if (_day < 10) {
      dmd.drawString(4, 32, "0", 1, GRAPHICS_NORMAL);
      dmd.drawString(13, 32, ta, 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(4, 32, ta, 2, GRAPHICS_NORMAL);
    }

    dmd.drawFilledBox(23, 40, 27, 38, GRAPHICS_OR);

    str_mo = String(_month);
    str_mo.toCharArray(mo, 3);
    //........................................MONTH...................................//
    if (_month < 10) {
      dmd.drawString(30, 32, "0", 1, GRAPHICS_NORMAL);
      dmd.drawString(39, 32, mo, 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(31, 32, mo, 2, GRAPHICS_NORMAL);
    }

    dmd.drawFilledBox(50, 40, 54, 38, GRAPHICS_OR);
    //..................................YEARS....l..................................//
    str_ye = String(_year);
    str_ye.toCharArray(ye, 6);

    dmd.drawString(57, 32, ye, 4, GRAPHICS_NORMAL);
  }
  dmd.selectFont(Comic24);
  if (_second == 10) { //-> Display the date when seconds equal to 11
    if (_day == 7 && _month == 5) {
      while (1) {
        dmd.clearScreen(true);
        delay(0);
        dmd.drawString(50, 3, "Eid", 3, GRAPHICS_NORMAL);
        dmd.drawString(4, 25, "Mubarak", 8, GRAPHICS_NORMAL);
        delay(500000);
        dmd.clearScreen(true);
        delay(0);
        return;
      }
    }
  }
}
