

#include "setup.h"


void setup()
{
  Serial.begin(9600);
  setuppin();

  //setup_pinmode();
  lcd_setup();

  //attachInterrupt((flowsensor), flow, RISING); // Setup Interrupt

  /// currenttimeflow = millis();
  //resettimeflow = currenttimeflow;
  readeep();
  init_awal();


}
void loop ()
{
  read_water();

  // reset millis
  reset_millis();


  pin_set();
  //Serial.print ("nilai detiknyala1 :");
  //Serial.println (currenttimebutton);
  allcondition();
  button();


  if (!buka && !tutup && selectcount == 0)
  {
    //button();
    tampilan();

  }
  else if (buka)
  {
    counterstep++;
    if (counterstep <= 50 )
    {
      motor_stepper_on();
      // buka=true;
    }
    if (counterstep > 51)
    {
      counterstep = 0;
      cleartampilan();
      buka = false;
    }
  }
  else if (tutup)
  {
    counterstep++;
    if (counterstep <= 50 )
    {
      motor_stepper_on();
      // buka=true;
    }
    if (counterstep > 51 )
    {
      counterstep = 0;
      cleartampilan();
      tutup = false;
    }
  }

  lcd_nobacklight()


}
