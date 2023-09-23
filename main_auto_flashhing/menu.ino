

void button()
{

  //init varaiable button

  upb = digitalRead(up);
  downb = digitalRead(down);
  selectb = digitalRead(select);
  cancelb = digitalRead(cancel);
  currenttimebutton = millis();

  /*if (upb ==0 && downb == 0 && triglight == 0)
    {

    //selectcount =10;
    cleartampilan();
    // Serial.println("masuk");

    turnoff();
    triglight=1;
    delay(200);

    }*/
  if (upb == 0 && downb == 0 && triglight == 1)
  {

    //selectcount =10;
    cleartampilan();
    //Serial.println("masuk");
    turnon();
    triglight = 0;
    //delay(200);
  }


  if (currenttimebutton - timebutton >= 130)
  {
    timebutton = currenttimebutton ;

    if (!masuksetting)
    {
      //runningcountdown();


      if (selectb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        selectcount += 1;
        cleartampilan();
        //Serial.println(selectcount);
      }
      else if (selectb == 1)
      {
        //Serial.println("mati");
        digitalWrite(ledbutton, LOW);
      }
    }
    if (cancelb == 0)
    {
      digitalWrite(ledbutton, HIGH);
      selectcount -= 1;
      cleartampilan();
      if (selectcount <= 0)
      {
        selectcount = 0;
      }
      upcount = 0;
      downcount = 0;
      set = 0;
      kondisinyala = 0;
      kondisisave = 0;
      masuksetting = false;
    }

    else  if (cancelb == 1)
    {
      digitalWrite(ledbutton, LOW);
    }
    if (masuksetting)
    {
      selectcount = 3;
    }

    //config button cancel


    // currenttimebutton=0;
    //noInterrupts();
    //timer0_millis=0;
    //interrupts();
    //millis()=0;


    if (selectcount == 1)
    {
      menusetting();
      //stopcount=true;
    }
    if (selectcount == 2)
    {
      //settingnyala();
      //stopcount=true;
      pilihsetting();
    }
    if (selectcount == 3 && setpilih == 0)
    {
      masukpilih = false;
      settingnyala();
    }
    if (selectcount == 3 && setpilih == 1)
    {
      masukpilih = false;
      settingmati();
    }
    if (selectcount == 4)
    {
      masuksetting = false;
      savesetting();
    }

    if (selectcount >= 10 )
    {
      display_light();
      menulight();
    }

    else if (selectcount == 0)
    {
      // tampilan();

      runningcountdown();
    }

    //timebutton=0;
  }

  // Serial.println(selectcount);

}

void menusetting()
{
  //config button up
  if (upb == 0)
  {
    digitalWrite(ledbutton, HIGH);
    cleartampilan();

    downcount -= 1;
    if (downcount < 0)
    {
      downcount = 3;
    }

  }

  //config button up
  if (downb == 0)
  {
    cleartampilan();
    digitalWrite(ledbutton, HIGH);
    downcount += 1;
    if (downcount > 3)
    {
      downcount = 0;
    }

  }

  else
  {
    digitalWrite(ledbutton, LOW);
  }

  display_menu_setting(downcount);

}

void pilihsetting()
{
  if (downcount == 0)
  {
    //config button up
    if ( selectcount == 2 )
    {
      masukpilih = true;
      selectcount = 2;
    }
    if ( selectcount == 3 )
    {
      masukpilih = false;
      //selectcount=3;

    }

    if (upb == 0)
    {
      cleartampilan();
      digitalWrite(ledbutton, HIGH);

      setpilih -= 1;
      if (setpilih < 0)
      {
        setpilih = 1;
      }

    }

    //config button up
    if (downb == 0)
    {
      cleartampilan();
      digitalWrite(ledbutton, HIGH);
      setpilih += 1;
      if (setpilih > 1)
      {
        setpilih = 0;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    display_pilih_setting_t1(setpilih);
  }

  if (downcount == 1)
  {
    //config button up
    if ( selectcount == 2 )
    {
      masukpilih = true;
      selectcount = 2;
    }
    if ( selectcount == 3 )
    {
      masukpilih = false;
      //selectcount=3;

    }

    if (upb == 0)
    {
      digitalWrite(ledbutton, HIGH);
      cleartampilan();

      setpilih -= 1;
      if (setpilih < 0)
      {
        setpilih = 1;
      }

    }

    //config button up
    if (downb == 0)
    {
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      setpilih += 1;
      if (setpilih > 1)
      {
        setpilih = 0;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    display_pilih_setting_t2(setpilih);
  }

  if (downcount == 2)
  {
    //config button up
    if ( selectcount == 2 )
    {
      masukpilih = true;
      selectcount = 2;
    }
    if ( selectcount == 3 )
    {
      masukpilih = false;
      //selectcount=3;

    }

    if (upb == 0)
    {
      digitalWrite(ledbutton, HIGH);
      cleartampilan();

      setpilih -= 1;
      if (setpilih < 0)
      {
        setpilih = 1;
      }

    }

    //config button up
    if (downb == 0)
    {
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      setpilih += 1;
      if (setpilih > 1)
      {
        setpilih = 0;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    display_pilih_setting_t3(setpilih);
  }

  if (downcount == 3)
  {
    //config button up
    if ( selectcount == 2 )
    {
      masukpilih = true;
      selectcount = 2;
    }
    if ( selectcount == 3 )
    {
      masukpilih = false;
      //selectcount=3;

    }

    if (upb == 0)
    {
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      setpilih -= 1;
      if (setpilih < 0)
      {
        setpilih = 1;
      }

    }

    //config button up
    if (downb == 0)
    {
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      setpilih += 1;
      if (setpilih > 1)
      {
        setpilih = 0;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    display_pilih_setting_t4(setpilih);
  }

}

void settingnyala ()
{

  if (downcount == 0 )
  {
    kondisinyala = 1;
    nyala1 = true;

    if (set <= 5 && !save1)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save1)
    {
      masuksetting = false;
      selectcount = 4;

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala1 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala1 -= 1;
        if (jamnyala1 <= 0)
        {
          jamnyala1 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala1 += 1;
        if (menitnyala1 > 59)
        {
          menitnyala1 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala1 -= 1;
        if (menitnyala1 <= 0)
        {
          menitnyala1 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala1 += 1;
        if (detiknyala1 > 59)
        {
          detiknyala1 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala1 -= 1;
        if (detiknyala1 <= 0)
        {
          detiknyala1 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave1 = "TIDAK";
        save1 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave1 = "YA   ";
        save1 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        cleartampilan();
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        cleartampilan();
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting T0 Valve", jamnyala1, menitnyala1, detiknyala1, "ON", kondisisave1 , set);
    ///Serial.println(set);
  }


  if (downcount == 1)
  {
    kondisinyala = 1;
    nyala2 = true;

    if (set <= 5 && !save2)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save2)
    {
      masuksetting = false;
      selectcount = 4;
      // Serial.println(set);

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala2 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala2 -= 1;
        if (jamnyala2 <= 0)
        {
          jamnyala2 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala2 += 1;
        if (menitnyala2 > 59)
        {
          menitnyala2 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala2 -= 1;
        if (menitnyala2 <= 0)
        {
          menitnyala2 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala2 += 1;
        if (detiknyala2 > 59)
        {
          detiknyala2 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala2 -= 1;
        if (detiknyala2 <= 0)
        {
          detiknyala2 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave2 = "TIDAK";
        save2 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave2 = "YA   ";
        save2 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting timer 2 T0", jamnyala2, menitnyala2, detiknyala2, "ON", kondisisave2 , set);
    ///Serial.println(set);
  }

  if (downcount == 2)
  {
    kondisinyala = 1;
    nyala3 = true;

    if (set <= 5 && !save3)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save3)
    {
      masuksetting = false;
      selectcount = 4;
      // Serial.println(set);

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala3 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala3 -= 1;
        if (jamnyala3 <= 0)
        {
          jamnyala3 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala3 += 1;
        if (menitnyala3 > 59)
        {
          menitnyala3 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala3 -= 1;
        if (menitnyala3 <= 0)
        {
          menitnyala3 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala3 += 1;
        if (detiknyala3 > 59)
        {
          detiknyala3 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala3 -= 1;
        if (detiknyala3 <= 0)
        {
          detiknyala3 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave3 = "TIDAK";
        save3 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave3 = "YA";
        save3 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting timer 3 T0", jamnyala3, menitnyala3, detiknyala3, "ON", kondisisave3, set);
    ///Serial.println(set);
  }

  if (downcount == 3)
  {
    kondisinyala = 1;
    nyala4 = true;

    if (set <= 5 && !save4)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save4)
    {
      masuksetting = false;
      selectcount = 4;
      // Serial.println(set);

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala4 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jamnyala4 -= 1;
        if (jamnyala4 <= 0)
        {
          jamnyala4 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala4 += 1;
        if (menitnyala4 > 59)
        {
          menitnyala4 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitnyala4 -= 1;
        if (menitnyala4 <= 0)
        {
          menitnyala4 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala4 += 1;
        if (detiknyala4 > 59)
        {
          detiknyala4 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detiknyala4 -= 1;
        if (detiknyala4 <= 0)
        {
          detiknyala4 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave4 = "TIDAK";
        save4 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave4 = "YA";
        save4 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting timer 4 T0", jamnyala4, menitnyala4, detiknyala4, "ON", kondisisave4, set);
    ///Serial.println(set);
  }

}

void settingmati ()
{

  if (downcount == 0 )
  {
    kondisinyala = 0;
    nyala1 = false;

    if (set <= 5 && !save1)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save1)
    {
      masuksetting = false;
      selectcount = 4;

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati1 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati1 -= 1;
        if (jammati1 <= 0)
        {
          jammati1 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati1 += 1;
        if (menitmati1 > 59)
        {
          menitmati1 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati1 -= 1;
        if (menitmati1 <= 0)
        {
          menitmati1 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati1 += 1;
        if (detikmati1 > 59)
        {
          detikmati1 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati1 -= 1;
        if (detikmati1 <= 0)
        {
          detikmati1 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave1 = "TIDAK";
        save1 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave1 = "YA";
        save1 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting T1 Valve", jammati1, menitmati1, detikmati1, "OFF", kondisisave1 , set);
    ///Serial.println(set);
  }


  if (downcount == 1 )
  {
    kondisinyala = 0;
    nyala2 = false;

    if (set <= 5 && !save2)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save2)
    {
      masuksetting = false;
      selectcount = 4;

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati2 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati2 -= 1;
        if (jammati2 <= 0)
        {
          jammati2 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati2 += 1;
        if (menitmati2 > 59)
        {
          menitmati2 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati2 -= 1;
        if (menitmati2 <= 0)
        {
          menitmati2 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati2 += 1;
        if (detikmati2 > 59)
        {
          detikmati2 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati2 -= 1;
        if (detikmati2 <= 0)
        {
          detikmati2 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave2 = "TIDAK";
        save2 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave2 = "YA";
        save2 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting timer 2 T0", jammati2, menitmati2, detikmati2, "OFF", kondisisave2 , set);
    ///Serial.println(set);
  }

  if (downcount == 2 )
  {
    kondisinyala = 0;
    nyala3 = false;

    if (set <= 5 && !save3)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save3)
    {
      masuksetting = false;
      selectcount = 4;

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati3 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati3 -= 1;
        if (jammati3 <= 0)
        {
          jammati3 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati3 += 1;
        if (menitmati3 > 59)
        {
          menitmati3 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati3 -= 1;
        if (menitmati3 <= 0)
        {
          menitmati3 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati3 += 1;
        if (detikmati3 > 59)
        {
          detikmati3 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati3 -= 1;
        if (detikmati3 <= 0)
        {
          detikmati3 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave3 = "TIDAK";
        save3 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave3 = "YA";
        save3 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting timer 3 T0", jammati3, menitmati3, detikmati3, "OFF", kondisisave3 , set);
    ///Serial.println(set);
  }

  if (downcount == 3 )
  {
    kondisinyala = 0;
    nyala4 = false;

    if (set <= 5 && !save4)
    {
      masuksetting = true;
      selectcount = 3;
    }
    if (set == 5 && save4)
    {
      masuksetting = false;
      selectcount = 4;

    }

    if (selectb == 0)
    {
      //Serial.println("cok");
      digitalWrite(ledbutton, HIGH);
      cleartampilan();
      set += 1;
      //Serial.println(set);

      //Serial.println(save);
      if (set > 5 )
      {
        //masuksetting =false;

        set = 1;
      }

    }

    else
    {
      digitalWrite(ledbutton, LOW);
    }

    if (set == 1)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati4 += 1;
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        jammati4 -= 1;
        if (jammati4 <= 0)
        {
          jammati4 = 0;
        }
      }



    }
    if (set == 2)
    {
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati4 += 1;
        if (menitmati4 > 59)
        {
          menitmati4 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        menitmati4 -= 1;
        if (menitmati4 <= 0)
        {
          menitmati4 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 1);
    }
    if (set == 3)
    {

      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati4 += 1;
        if (detikmati4 > 59)
        {
          detikmati4 = 0;
        }
      }
      //config button up
      if (downb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        detikmati4 -= 1;
        if (detikmati4 <= 0)
        {
          detikmati4 = 59;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 2);
    }

    if (set == 4)
    {
      if (kondisisave == 0)
      {
        kondisisave4 = "TIDAK";
        save4 = false;
      }
      if (kondisisave == 1)
      {
        kondisisave4 = "YA";
        save4 = true;
      }
      //config button up
      if (upb == 0)
      {
        digitalWrite(ledbutton, HIGH);
        //nyala1 =true;
        kondisisave += 1;
        if (kondisisave > 1)
        {
          kondisisave = 0;
        }

      }
      //config button up
      if (downb == 0)
      {
        kondisisave -= 1;
        if (kondisisave < 0 )
        {
          kondisisave = 1;
        }
      }
      //display_setting("setting timer 1 T0",jamnyala1,menitnyala1,detiknyala1, "ON", kondisisave1, 3);

    }

    display_setting("setting timer 4 T0", jammati4, menitmati4, detikmati4, "OFF", kondisisave4 , set);
    ///Serial.println(set);
  }


}
void menulight()
{
  //Serial.println(triglight);
  //Serial.println(selectcount);

  if (upb == 0)
  {
    // Serial.println("++++++++");
    triglight ++;
    if ( triglight > 1)
    {
      triglight = 0;
    }
  }
  if (downb == 0)
  {
    // Serial.println("--------------");
    triglight --;
    if ( triglight < 0)
    {
      triglight = 1;
      //Serial.println(triglight)
    }
  }

  if (selectcount == 11)
  {
    //  Serial.println("ok");

    if (triglight == 1)
    {

      turnoff();

    }


    // savesetting();
    selectcount = 0;
  }

}
