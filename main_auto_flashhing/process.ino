#include <EEPROM.h>
//init_variable();


void read_water()
{
  currenttimeflow = millis();
  //Serial.println(currentTime);
  //Serial.println(currentTime);
  // Every second, calculate and print litres/hour



  if (currenttimeflow - resettimeflow  >=  1000)

  {

    resettimeflow = currenttimeflow; // Updates cloopTime
    //Serial.println(flow_frequency);
    if (flow_frequency != 0) {

      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.

      //      l_minute = (flow_frequency / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      //Serial.println(l_minute);



      flow_frequency = 0; // Reset Counter

      // Serial.println(l_minute, DEC); // Print litres/hour

      //Serial.println(" L/Sec");

    }

    else  {



    }

  }

  /*    else if (currentTime > 10000)
    {
     noInterrupts();
       timer0_millis = 0;
       interrupts();

    Serial.println("reset");
    cloopTime=0;
    delay(150);
    //Serial.println (currenttimebutton);

  */
}




void pin_set()
{
  if (aktifpin1 == 1)
  {
    digitalWrite(pin_out1, HIGH);
    //motor_stepper_on();
    trigstepper = 1;
  }
  else if (aktifpin1 == 0)
  {
    digitalWrite(pin_out1, LOW);
    trigstepper = 0;
  }


  if (aktifpin2 == 1)
  {
    digitalWrite(pin_out2, HIGH);
  }
  if (aktifpin2 == 0)
  {
    digitalWrite(pin_out2, LOW);
  }


  if (aktifpin3 == 1)
  {
    digitalWrite(pin_out3, HIGH);
  }
  if (aktifpin3 == 0)
  {
    digitalWrite(pin_out3, LOW);
  }


  if (aktifpin4 == 1)
  {
    digitalWrite(pin_out4, HIGH);
  }
  if (aktifpin4 == 0)
  {
    digitalWrite(pin_out4, LOW);
  }



}







void countingdownnyala1()
{

  if (jamnyala1 > 0 && menitnyala1 == 0 && detiknyala1 > 0 )
  {
    if (menitnyala1 == 0)
    {
      jamnyala1 -= 1;
      menitnyala1 = 59;
    }


  }
  if (jamnyala1 > 0 && menitnyala1 == 0 && detiknyala1 == 0 )
  {
    if (menitnyala1 == 0)
    {
      jamnyala1 -= 1;
      menitnyala1 = 60;
    }


  }

  if (menitnyala1 > 0 && detiknyala1 == 0)
  {
    if (detiknyala1 == 0)
    {
      menitnyala1 -= 1;
      detiknyala1 = 59;
    }


  }
  if (menitnyala1 > 0 && detiknyala1 > 0)
  {
    if (detiknyala1 == 0)
    {
      menitnyala1 -= 1;
      detiknyala1 = 59;
    }


  }
  if (detiknyala1 > 0)
  {
    currenttime1 = millis();
    //motor_stepper_on();

    if (currenttime1 - currenttimenyala1 >=  1000)
    {

      currenttimenyala1 = currenttime1;

      detiknyala1 --;
      //cleartampilan();

      if (detiknyala1 <= 0)
      {
        detiknyala1 = 0;
        if (jamnyala1 > 0)
        {
          nyala1 = true;
        }
        if (menitnyala1 > 0)
        {
          nyala1 = true;
        }
        else
        {
          cleartampilan();
          //cleartampilan();
          display_valve_close();
          //readeep();
          nyala1 = false;
          tutup = true;
          jamnyala1 = EEPROM.read(addres1);
          menitnyala1 = EEPROM.read(addres5);
          detiknyala1 = EEPROM.read(addres9);
          //Serial.println("read eep nyala");
          //readeep();
          // nyala1=false;


          //readeep();


        }


      }


    }

  }

}

void countingdownnyala2()
{
  //Serial.println("nyala2");
  if (jamnyala2 > 0 && menitnyala2 == 0 && detiknyala2 > 0 )
  {
    if (menitnyala2 == 0)
    {
      jamnyala2 -= 1;
      menitnyala2 = 59;
    }


  }
  if (jamnyala2 > 0 && menitnyala2 == 0 && detiknyala2 == 0 )
  {
    if (menitnyala2 == 0)
    {
      jamnyala2 -= 1;
      menitnyala2 = 60;
    }


  }

  if (menitnyala2 > 0 && detiknyala2 == 0)
  {
    if (detiknyala2 == 0)
    {
      menitnyala2 -= 1;
      detiknyala2 = 59;
    }


  }
  if (menitnyala2 > 0 && detiknyala2 > 0)
  {
    if (detiknyala2 == 0)
    {
      menitnyala2 -= 1;
      detiknyala2 = 59;
    }


  }
  if (detiknyala2 > 0)
  {
    currenttime2 = millis();

    if (currenttime2 - currenttimenyala2 >=  1000)
    {

      currenttimenyala2 = currenttime2;

      detiknyala2 --;

      if (detiknyala2 <= 0)
      {
        detiknyala2 = 0;
        if (jamnyala2 > 0)
        {
          nyala2 = true;
        }
        if (menitnyala2 > 0)
        {
          nyala2 = true;
        }
        else
        {
          cleartampilan();
          jamnyala2 = EEPROM.read(addres2);
          menitnyala2 = EEPROM.read(addres6);
          detiknyala2 = EEPROM.read(addres10);
          nyala2 = false;
          //readeep();
        }
      }
    }
  }
}

void countingdownnyala3()
{
  // Serial.println("nyala3");
  if (jamnyala3 > 0 && menitnyala3 == 0 && detiknyala3 > 0 )
  {
    if (menitnyala3 == 0)
    {
      jamnyala3 -= 1;
      menitnyala3 = 59;
    }


  }
  if (jamnyala3 > 0 && menitnyala3 == 0 && detiknyala3 == 0 )
  {
    if (menitnyala3 == 0)
    {
      jamnyala3 -= 1;
      menitnyala3 = 60;
    }


  }

  if (menitnyala3 > 0 && detiknyala3 == 0)
  {
    if (detiknyala3 == 0)
    {
      menitnyala3 -= 1;
      detiknyala3 = 59;
    }


  }
  if (menitnyala3 > 0 && detiknyala3 > 0)
  {
    if (detiknyala3 == 0)
    {
      menitnyala3 -= 1;
      detiknyala3 = 59;
    }


  }
  if (detiknyala3 > 0)
  {
    currenttime3 = millis();

    if (currenttime3 - currenttimenyala3 >=  1000)
    {

      currenttimenyala3 = currenttime3;

      detiknyala3 --;

      if (detiknyala3 <= 0)
      {
        detiknyala3 = 0;
        if (jamnyala3 > 0)
        {
          nyala3 = true;
        }
        if (menitnyala3 > 0)
        {
          nyala3 = true;
        }
        else
        {
          cleartampilan();
          jamnyala3 = EEPROM.read(addres3);
          menitnyala3 = EEPROM.read(addres7);
          detiknyala3 = EEPROM.read(addres11);
          nyala3 = false;
          //readeep();

        }
      }
    }
  }
}

void countingdownnyala4()
{
  //Serial.println("nyala4");
  if (jamnyala4 > 0 && menitnyala4 == 0 && detiknyala4 > 0 )
  {
    if (menitnyala4 == 0)
    {
      jamnyala4 -= 1;
      menitnyala4 = 59;
    }


  }
  if (jamnyala4 > 0 && menitnyala4 == 0 && detiknyala4 == 0 )
  {
    if (menitnyala4 == 0)
    {
      jamnyala4 -= 1;
      menitnyala4 = 60;
    }


  }

  if (menitnyala4 > 0 && detiknyala4 == 0)
  {
    if (detiknyala4 == 0)
    {
      menitnyala4 -= 1;
      detiknyala4 = 59;
    }


  }
  if (menitnyala4 > 0 && detiknyala4 > 0)
  {
    if (detiknyala4 == 0)
    {
      menitnyala4 -= 1;
      detiknyala4 = 59;
    }


  }
  if (detiknyala4 > 0)
  {
    currenttime4 = millis();

    if (currenttime4 - currenttimenyala4 >=  1000)
    {

      currenttimenyala4 = currenttime4;

      detiknyala4 --;

      if (detiknyala4 <= 0)
      {
        detiknyala4 = 0;
        if (jamnyala4 > 0)
        {
          nyala4 = true;
        }
        if (menitnyala4 > 0)
        {
          nyala4 = true;
        }
        else
        {
          cleartampilan();
          jamnyala4 = EEPROM.read(addres4);
          menitnyala4 = EEPROM.read(addres8);
          detiknyala4 = EEPROM.read(addres12);
          nyala4 = false;
          //readeep();

        }
      }
    }
  }
}

void countingdownmati1()
{
  //Serial.println("mati1");
  if (jammati1 > 0 && menitmati1 == 0 && detikmati1 > 0 )
  {
    if (menitmati1 == 0)
    {
      jammati1 -= 1;
      menitmati1 = 59;
    }


  }
  if (jammati1 > 0 && menitmati1 == 0 && detikmati1 == 0 )
  {
    if (menitmati1 == 0)
    {
      jammati1 -= 1;
      menitmati1 = 60;
    }


  }

  if (menitmati1 > 0 && detikmati1 == 0)
  {
    if (detikmati1 == 0)
    {
      menitmati1 -= 1;
      detikmati1 = 60;
    }


  }
  if (menitmati1 > 0 && detikmati1 > 0)
  {
    if (detikmati1 == 0)
    {
      menitmati1 -= 1;
      detikmati1 = 59;
    }


  }
  if (detikmati1 > 0)
  {
    currenttime1 = millis();

    if (currenttime1 - currenttimemati1 >=  1000)
    {

      currenttimemati1 = currenttime1;
      //cleartampilan();
      detikmati1 --;

      if (detikmati1 <= 0)
      {
        detikmati1 = 0;
        if (jammati1 > 0)
        {
          nyala1 = false;
        }
        if (menitmati1 > 0)
        {
          nyala1 = false;
        }
        else
        {


          cleartampilan();
          display_valve_open();
          //readeep();
          nyala1 = true;
          buka = true;
          jammati1 = EEPROM.read(addres13);
          menitmati1 = EEPROM.read(addres17);
          detikmati1 = EEPROM.read(addres21);
          counterstep++;
          //currentimenyalastepper = millis();


          //noInterrupts();
          //timer0_millis = 0;
          //interrupts();
          //Serial.print(currenttimemati1);




        }


      }


    }

  }

}

void countingdownmati2()
{
  //Serial.println("mati2");
  if (jammati2 > 0 && menitmati2 == 0 && detikmati2 > 0 )
  {
    if (menitmati2 == 0)
    {
      jammati2 -= 1;
      menitmati2 = 59;
    }


  }
  if (jammati2 > 0 && menitmati2 == 0 && detikmati2 == 0 )
  {
    if (menitmati2 == 0)
    {
      jammati2 -= 1;
      menitmati2 = 60;
    }


  }

  if (menitmati2 > 0 && detikmati2 == 0)
  {
    if (detikmati2 == 0)
    {
      menitmati2 -= 1;
      detikmati2 = 60;
    }


  }
  if (menitmati2 > 0 && detikmati2 > 0)
  {
    if (detikmati2 == 0)
    {
      menitmati2 -= 1;
      detikmati2 = 59;
    }


  }
  if (detikmati2 > 0)
  {
    currenttime2 = millis();

    if (currenttime2 - currenttimemati2 >=  1000)
    {

      currenttimemati2 = currenttime2;

      detikmati2 --;

      if (detikmati2 <= 0)
      {
        detikmati2 = 0;
        if (jammati2 > 0)
        {
          nyala2 = false;
        }
        if (menitmati2 > 0)
        {
          nyala2 = false;
        }
        else
        {
          cleartampilan();
          nyala2 = true;
          jammati2 = EEPROM.read(addres14);
          menitmati2 = EEPROM.read(addres18);
          detikmati2 = EEPROM.read(addres22);
          //readeep();

        }

      }

    }

  }

}

void countingdownmati3()
{
  //Serial.println("mati3");
  if (jammati3 > 0 && menitmati3 == 0 && detikmati3 > 0 )
  {
    if (menitmati3 == 0)
    {
      jammati3 -= 1;
      menitmati3 = 59;
    }


  }
  if (jammati3 > 0 && menitmati3 == 0 && detikmati3 == 0 )
  {
    if (menitmati3 == 0)
    {
      jammati3 -= 1;
      menitmati3 = 60;
    }


  }

  if (menitmati3 > 0 && detikmati3 == 0)
  {
    if (detikmati3 == 0)
    {
      menitmati3 -= 1;
      detikmati3 = 60;
    }


  }
  if (menitmati3 > 0 && detikmati3 > 0)
  {
    if (detikmati3 == 0)
    {
      menitmati3 -= 1;
      detikmati3 = 59;
    }


  }
  if (detikmati3 > 0)
  {
    currenttime3 = millis();

    if (currenttime3 - currenttimemati3 >=  1000)
    {

      currenttimemati3 = currenttime3;

      detikmati3 --;

      if (detikmati3 <= 0)
      {
        detikmati3 = 0;
        if (jammati3 > 0)
        {
          nyala3 = false;
        }
        if (menitmati3 > 0)
        {
          nyala3 = false;
        }
        else
        {
          cleartampilan();
          jammati3 = EEPROM.read(addres15);
          menitmati3 = EEPROM.read(addres19);
          detikmati3 = EEPROM.read(addres23);
          nyala3 = true;
          //readeep();

        }

      }

    }

  }

}

void countingdownmati4()
{
  //Serial.println("mati4");
  if (jammati4 > 0 && menitmati4 == 0 && detikmati4 > 0 )
  {
    if (menitmati4 == 0)
    {
      jammati4 -= 1;
      menitmati4 = 59;
    }


  }
  if (jammati4 > 0 && menitmati4 == 0 && detikmati4 == 0 )
  {
    if (menitmati4 == 0)
    {
      jammati4 -= 1;
      menitmati4 = 60;
    }


  }

  if (menitmati4 > 0 && detikmati4 == 0)
  {
    if (detikmati4 == 0)
    {
      menitmati4 -= 1;
      detikmati4 = 60;
    }


  }
  if (menitmati4 > 0 && detikmati4 > 0)
  {
    if (detikmati4 == 0)
    {
      menitmati4 -= 1;
      detikmati4 = 59;
    }


  }
  if (detikmati4 > 0)
  {
    currenttime4 = millis();

    if (currenttime4 - currenttimemati4 >=  1000)
    {

      currenttimemati4 = currenttime4;

      detikmati4 --;

      if (detikmati4 <= 0)
      {
        detikmati4 = 0;
        if (jammati4 > 0)
        {
          nyala4 = false;
        }
        if (menitmati4 > 0)
        {
          nyala4 = false;
        }
        else
        {
          cleartampilan();
          jammati4 = EEPROM.read(addres16);
          menitmati4 = EEPROM.read(addres20);
          detikmati4 = EEPROM.read(addres24);
          nyala4 = true;
          // readeep();

        }

      }

    }

  }

}

void runningcountdown()
{
  if (nyala1)
  {
    nyala = true;
    aktifpin1 = 1;
    //countingdown(jamnyala1, menitnyala1, detiknyala1,updatecountdetik1, nyala,addres1,addres5,addres9);
    countingdownnyala1();
  }

  if (!nyala1)
  {
    nyala = false;
    aktifpin1 = 0;
    //countingdown(jammati1, menitmati1, detikmati1,updatecountdetik1, nyala,addres13,addres17,addres21);
    countingdownmati1();
  }

  if (nyala2)
  {
    nyala = true;
    aktifpin2 = 1;
    //countingdown(jamnyala1, menitnyala1, detiknyala1,updatecountdetik1, nyala,addres1,addres5,addres9);
    countingdownnyala2();
  }

  if (!nyala2)
  {
    nyala = false;
    aktifpin2 = 0;
    //countingdown(jammati1, menitmati1, detikmati1,updatecountdetik1, nyala,addres13,addres17,addres21);
    countingdownmati2();
  }

  if (nyala3)
  {
    nyala = true;
    aktifpin3 = 1;
    //countingdown(jamnyala1, menitnyala1, detiknyala1,updatecountdetik1, nyala,addres1,addres5,addres9);
    countingdownnyala3();
  }

  if (!nyala3)
  {
    nyala = false;
    aktifpin3 = 0;
    //countingdown(jammati1, menitmati1, detikmati1,updatecountdetik1, nyala,addres13,addres17,addres21);
    countingdownmati3();
  }

  if (nyala4)
  {
    nyala = true;
    aktifpin4 = 1;
    //countingdown(jamnyala1, menitnyala1, detiknyala1,updatecountdetik1, nyala,addres1,addres5,addres9);
    countingdownnyala4();
  }

  if (!nyala4)
  {
    nyala = false;
    aktifpin4 = 0;
    //countingdown(jammati1, menitmati1, detikmati1,updatecountdetik1, nyala,addres13,addres17,addres21);
    countingdownmati4();
  }

}

void allcondition()
{
  if (save1)
  {
    kondisisave1 = "YA    ";
  }
  if (!save1)
  {
    kondisisave1 = "TIDAK";
  }
  if (save2)
  {
    kondisisave2 = "YA     ";
  }
  if (!save2)
  {
    kondisisave2 = "TIDAK";
  }
  if (save3)
  {
    kondisisave3 = "YA     ";
  }
  if (!save3)
  {
    kondisisave3 = "TIDAK";
  }
  if (save4)
  {
    kondisisave4 = "YA     ";
  }
  if (!save4)
  {
    kondisisave4 = "TIDAK";
  }

  //kondisi nyala
  if (nyala1)
  {
    kondisi1 = "ON";
  }
  if (!nyala1)
  {
    kondisi1 = "OFF";
  }
  if (nyala2)
  {
    kondisi2 = "ON";
  }
  if (!nyala2)
  {
    kondisi2 = "OFF";
  }
  if (nyala3)
  {
    kondisi3 = "ON";
  }
  if (!nyala3)
  {
    kondisi3 = "OFF";
  }
  if (nyala4)
  {
    kondisi4 = "ON";
  }
  if (!nyala4)
  {
    kondisi4 = "OFF";
  }
}
void readeep()
{

  jamnyala1 = EEPROM.read(addres1);
  jamnyala2 = EEPROM.read(addres2);
  jamnyala3 = EEPROM.read(addres3);
  jamnyala4 = EEPROM.read(addres4);

  menitnyala1 = EEPROM.read(addres5);
  menitnyala2 = EEPROM.read(addres6);
  menitnyala3 = EEPROM.read(addres7);
  menitnyala4 = EEPROM.read(addres8);

  detiknyala1 = EEPROM.read(addres9);
  detiknyala2 = EEPROM.read(addres10);
  detiknyala3 = EEPROM.read(addres11);
  detiknyala4 = EEPROM.read(addres12);

  jammati1 = EEPROM.read(addres13);
  jammati2 = EEPROM.read(addres14);
  jammati3 = EEPROM.read(addres15);
  jammati4 = EEPROM.read(addres16);

  menitmati1 = EEPROM.read(addres17);
  menitmati2 = EEPROM.read(addres18);
  menitmati3 = EEPROM.read(addres19);
  menitmati4 = EEPROM.read(addres20);

  detikmati1 = EEPROM.read(addres21);
  detikmati2 = EEPROM.read(addres22);
  detikmati3 = EEPROM.read(addres23);
  detikmati4 = EEPROM.read(addres24);
  // Serial.println("read ok");

  /*
    Serial.print(jamnyala1);
    Serial.print("------------");
    Serial.print(menitnyala1);
    Serial.print("------------");
    Serial.println(detiknyala1);

    Serial.print(jammati1);
    Serial.print("------------");
    Serial.print(menitmati1);
    Serial.print("------------");
    Serial.println(detikmati1);*/
  delay(300);


}
void writeeep()
{

  EEPROM.write(addres1, jamnyala1);
  EEPROM.write(addres2, jamnyala2);
  EEPROM.write(addres3, jamnyala3);
  EEPROM.write(addres4, jamnyala4);

  EEPROM.write(addres5, menitnyala1);
  EEPROM.write(addres6, menitnyala2);
  EEPROM.write(addres7, menitnyala3);
  EEPROM.write(addres8, menitnyala4);

  EEPROM.write(addres9, detiknyala1);
  EEPROM.write(addres10, detiknyala2);
  EEPROM.write(addres11, detiknyala3);
  EEPROM.write(addres12, detiknyala4);

  EEPROM.write(addres13, jammati1);
  EEPROM.write(addres14, jammati2);
  EEPROM.write(addres15, jammati3);
  EEPROM.write(addres16, jammati4);

  EEPROM.write(addres17, menitmati1);
  EEPROM.write(addres18, menitmati2);
  EEPROM.write(addres19, menitmati3);
  EEPROM.write(addres20, menitmati4);

  EEPROM.write(addres21, detikmati1);
  EEPROM.write(addres22, detikmati2);
  EEPROM.write(addres23, detikmati3);
  EEPROM.write(addres24, detikmati4);
  //Serial.println("write ok");
  delay(300);

}


void motor_stepper_on()
{

  digitalWrite(DIR, HIGH);
  digitalWrite(PUL, HIGH);
  delayMicroseconds(1000);
  digitalWrite(PUL, LOW);
  delayMicroseconds(1000);
  // }
  // if ( currentimenyalastepper > 110000  )
  //{
  // nyala1=true;
  // counterstep =0;
  //}

}


void reset_millis()
{
  if (millis() > 86400000)
  {
    noInterrupts();
    timer0_millis = 0;
    interrupts();
    currenttime1 = 0 , currenttime2 = 0 , currenttime3 = 0, currenttime4 = 0;
    currenttimenyala1 = 0, currenttimenyala2 = 0, currenttimenyala3 = 0 , currenttimenyala4 = 0;
    currenttimemati1 = 0, currenttimemati2 = 0, currenttimemati3 = 0, currenttimemati4 = 0;
    detikmati1count = 0, detikmati2count = 0, detikmati3count = 0, detikmati4count = 0;

    currentimenyala = 0, currenttimemati = 0, currenttimeflow = 0, resettimeflow = 0, currenttimebutton = 0, timebutton = 0;
    currentimenyalastepper = 0 , currenttiming = 0 ;
    //Serial.print(millis());
    //Serial.print("reset");
    //Serial.println (currenttimebutton);


  }
}

void lcd_nobacklight()
{
  if (triglight == 0 && selectcount == 0)
  {
    currenttimelcd ++;
    if (currenttimelcd >= 200)
    {
      cleartampilan();
      // Serial.println("masuk");

      turnoff();
      triglight = 1;
      currenttimelcd = 0;

    }
  }

}
