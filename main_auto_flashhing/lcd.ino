
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);


void lcd_setup()
{
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.noBacklight();
}
void turnoff()
{
  lcd.noBacklight();
}

void turnon()
{
  lcd.backlight();
}

void init_awal()
{
  lcd.setCursor(2, 1);
  lcd.print("PT. MULIA PRIMA");
  lcd.setCursor(9, 2);
  lcd.print("NUSA");
  delay(2000);
  lcd.clear();
}




void display_menu_setting(int cursormenu )
{
  //display.clearDisplay();
  // display.setTextSize(1);
  //display.setTextColor(WHITE);
  lcd.setCursor(0, 0);
  if (cursormenu == 0)
    lcd.print("> ");
  lcd.print("timer valve");
  // display.print(":");
  //lcd.setTextSize(1);

  //display.setTextColor(WHITE);
  lcd.setCursor(0, 1);
  if (cursormenu == 1)
    lcd.print("> ");
  lcd.print("timer1");
  // display.print(":");
  //display.setTextSize(1);
  lcd.setCursor(0, 2);
  //display.setTextColor(WHITE);
  if (cursormenu == 2)
    lcd.print("> ");
  lcd.print("timer2");
  //lcd.setTextSize(1);
  lcd.setCursor(0, 3);
  //display.setTextColor(WHITE);
  if (cursormenu == 3)
    lcd.print("> ");
  lcd.print("timer3");
  // display.display();

}

void display_pilih_setting_t1(int cursorpilih)
{
  //display.clearDisplay();
  //display.setTextSize(1);
  //display.setTextColor(WHITE);
  lcd.setCursor(0, 0);
  if (cursorpilih == 0)
    lcd.print("> ");
  lcd.print("Timer T0 Valve");
  // display.print(":");
  //display.setTextSize(1);
  lcd.setCursor(0, 1);
  //display.setTextColor(WHITE);
  if (cursorpilih == 1)
    lcd.print("> ");
  lcd.print("Timer T1 Valve");
  //display.display();
}

void display_pilih_setting_t2(int cursorpilih)
{

  lcd.setCursor(0, 0);
  if (cursorpilih == 0)
    lcd.print("> ");
  lcd.print("timer 1 T0");

  lcd.setCursor(0, 1);

  if (cursorpilih == 1)
    lcd.print("> ");
  lcd.print("timer 1 T1");
  // display.display();*/
}
void display_pilih_setting_t3(int cursorpilih)
{

  lcd.setCursor(0, 0);
  if (cursorpilih == 0)
    lcd.print("> ");
  lcd.print("timer 2 T0");

  lcd.setCursor(0, 1);

  if (cursorpilih == 1)
    lcd.print("> ");
  lcd.print("timer 2 T1");

}

void display_pilih_setting_t4(int cursorpilih)
{

  lcd.setCursor(0, 0);
  if (cursorpilih == 0)
    lcd.print("> ");
  lcd.print("timer 3 T0");

  lcd.setCursor(0, 1);

  if (cursorpilih == 1)
    lcd.print("> ");
  lcd.print("timer 3 T1");

}

void display_setting(String titlesetting, int hoursetting, int minutesetting, int secondsetting, String conditionsetting, String saved, int cursorsetting )
{

  lcd.setCursor(0, 0);
  lcd.print(titlesetting);

  lcd.setCursor(0, 1);


  if (cursorsetting == 1)
    lcd.print("> ");
  if (hoursetting < 10)
    lcd.print("0");
  lcd.print(hoursetting);
  lcd.print(":");
  if (cursorsetting == 2)
    lcd.print("> ");
  if (minutesetting < 10)
    lcd.print("0");
  lcd.print(minutesetting);
  lcd.print(":");
  // display.print(":");
  if (cursorsetting == 3)
    lcd.print("> ");
  if (secondsetting < 10)
    lcd.print("0");
  lcd.print(secondsetting);
  lcd.print(" = ");

  lcd.print(conditionsetting);

  lcd.setCursor(0, 2);

  if (cursorsetting == 4)
    lcd.print("> ");

  lcd.print("save = ");
  lcd.print(saved);


}
void savesetting()
{
  lcd.clear();
  lcd.setCursor(0, 2);
  lcd.print("SAVE");

  //selectcount = 3;
  upcount = 0;
  downcount = 0;
  set = 0;
  selectcount = 1;
  setpilih = 0;
  //Serial.print(selectcount);
  masuksetting = false;
  save1 = false;
  save2 = false;
  save3 = false;
  save4 = false;
  writeeep();
  readeep();




  //delay(300);
}
void cleartampilan()
{
  lcd.clear();
}
void tampilan()
{
  //Serial.println(detiknyala1);
  // if (nyala)
  //{

  //display.clearDisplay();
  //display.setTextSize(1);
  /*if (jamnyala1 <=0 )
    {
    lcd.setCursor(0,8);
    lcd.print("0");
    }

    if (jammati1 <= 0 )
    {
    lcd.setCursor(0,8);
    lcd.print("0");
    }*/

  if (nyala1 == true)
  {
    lcd.setCursor(0, 0);
    //display.setTextColor(WHITE);
    lcd.print("Timer V:");
    if (jamnyala1 < 10)
      lcd.print("0");
    lcd.print(jamnyala1);
    lcd.print(":");
    if (menitnyala1 < 10)
      lcd.print("0");
    lcd.print(menitnyala1);
    lcd.print(":");
    if (detiknyala1 < 10)
      lcd.print("0");
    lcd.print(detiknyala1);
    lcd.print(":");
    lcd.print(kondisi1);


  }
  if (nyala1 == false)
  {
    lcd.setCursor(0, 0);
    //display.setTextColor(WHITE);
    lcd.print("Timer V:");
    if (jammati1 < 10)
      lcd.print("0");
    lcd.print(jammati1);
    lcd.print(":");
    if (menitmati1 < 10)
      lcd.print("0");
    lcd.print(menitmati1);
    lcd.print(":");
    if (detikmati1 < 10)
      lcd.print("0");
    lcd.print(detikmati1);
    lcd.print(":");
    lcd.print(kondisi1);


  }
  if (nyala2 == true)
  {
    lcd.setCursor(0, 1);
    //display.setTextColor(WHITE);
    lcd.print("Timer 1:");
    if (jamnyala2 < 10)
      lcd.print("0");
    lcd.print(jamnyala2);
    lcd.print(":");
    if (menitnyala2 < 10)
      lcd.print("0");
    lcd.print(menitnyala2);
    lcd.print(":");
    if (detiknyala2 < 10)
      lcd.print("0");
    lcd.print(detiknyala2);
    lcd.print(":");
    lcd.print(kondisi2);
  }
  if (nyala2 == false)
  {
    lcd.setCursor(0, 1);
    //display.setTextColor(WHITE);
    lcd.print("Timer 1:");
    if (jammati2 < 10)
      lcd.print("0");
    lcd.print(jammati2);
    lcd.print(":");
    if (menitmati2 < 10)
      lcd.print("0");
    lcd.print(menitmati2);
    lcd.print(":");
    if (detikmati2 < 10)
      lcd.print("0");
    lcd.print(detikmati2);
    lcd.print(":");
    lcd.print(kondisi2);
  }
  if (nyala3 == true)
  {
    lcd.setCursor(0, 2);
    //display.setTextColor(WHITE);
    lcd.print("Timer 2:");
    if (jamnyala3 < 10)
      lcd.print("0");
    lcd.print(jamnyala3);
    lcd.print(":");
    if (menitnyala3 < 10)
      lcd.print("0");
    lcd.print(menitnyala3);
    lcd.print(":");
    if (detiknyala3 < 10)
      lcd.print("0");
    lcd.print(detiknyala3);
    lcd.print(":");
    lcd.print(kondisi3);
  }
  if (nyala3 == false)
  {
    lcd.setCursor(0, 2);
    //display.setTextColor(WHITE);
    lcd.print("Timer 2:");
    if (jammati3 < 10)
      lcd.print("0");
    lcd.print(jammati3);
    lcd.print(":");
    if (menitmati3 < 10)
      lcd.print("0");
    lcd.print(menitmati3);
    lcd.print(":");
    if (detikmati3 < 10)
      lcd.print("0");
    lcd.print(detikmati3);
    lcd.print(":");
    lcd.print(kondisi3);
  }
  //display.clearDisplay();
  if (nyala4 == true)
  {
    lcd.setCursor(0, 3);
    //display.setTextColor(WHITE);
    lcd.print("Timer 3:");
    if (jamnyala4 < 10)
      lcd.print("0");
    lcd.print(jamnyala4);
    lcd.print(":");
    if (menitnyala4 < 10)
      lcd.print("0");
    lcd.print(menitnyala4);
    lcd.print(":");
    if (detiknyala4 < 10)
      lcd.print("0");
    lcd.print(detiknyala4);
    lcd.print(":");
    lcd.print(kondisi4);
  }
  if (nyala4 == false)
  {
    lcd.setCursor(0, 3);
    //display.setTextColor(WHITE);
    lcd.print("Timer 3:");
    if (jammati4 < 10)
      lcd.print("0");
    lcd.print(jammati4);
    lcd.print(":");
    if (menitmati4 < 10)
      lcd.print("0");
    lcd.print(menitmati4);
    lcd.print(":");
    if (detikmati4 < 10)
      lcd.print("0");
    lcd.print(detikmati4);
    lcd.print(":");
    lcd.print(kondisi4);
  }
  // display.display();

  upcount = 0;
  downcount = 0;
  selectcount = 0;
  cancelcount = 0;

}

void display_light()
{
  lcd.setCursor(0, 0);
  if (triglight == 0)
    lcd.print("> ");
  lcd.print("Backlight ON");
  lcd.setCursor(0, 1);
  if (triglight == 1)
    lcd.print("> ");
  lcd.print("Backlight OFF");
}


void display_valve_open()
{
  lcd.setCursor(5, 1);
  //display.setTextColor(WHITE);
  lcd.print("BUKA VALVE");
}
void display_valve_close()
{
  lcd.setCursor(5, 1);
  //display.setTextColor(WHITE);
  lcd.print("TUTUP VALVE");
}
