extern volatile unsigned long timer0_millis;
volatile int flow_frequency;
unsigned int l_hour;
unsigned char flowsensor = 2;

#define pin_out1  9
#define pin_out2  10
#define pin_out3  11
#define pin_out4  12

#define PUL  A0 //define Pulse pin
#define DIR  A1 //define Direction pin
#define ENA  A2 //define Enable Pin

//#define buzzer A3

#define ledbutton 13
#define up       4
#define  down     5
#define select    7
#define cancel    6



//setting button
int upb = 0, downb = 0, selectb = 0, cancelb = 0;
//setting variable menu
int upcount = 0, downcount = 0, selectcount = 0, cancelcount = 0;

int jamnyala1 = 0, jamnyala2 = 0, jamnyala3 = 0, jamnyala4 = 0;
int menitnyala1 = 0, menitnyala2 = 0, menitnyala3 = 0, menitnyala4 = 0;
int detiknyala1 = 0, detiknyala2 = 0, detiknyala3 = 0, detiknyala4 = 0;

int detikmati1 = 0, detikmati2 = 0, detikmati3 = 0, detikmati4 = 0;
int menitmati1 = 0, menitmati2 = 0, menitmati3 = 0, menitmati4 = 0;
int jammati1 = 0, jammati3 = 0, jammati2 = 0,  jammati4 = 0;

//address jam nyala
int addres1 = 0, addres2 = 1, addres3 = 2, addres4 = 3;
// address menit nyala
int addres5 = 4, addres6 = 5, addres7 = 6, addres8 = 7;
//addres detik nyala
int addres9 = 8, addres10 = 9, addres11 = 10, addres12 = 11;
// addres jam mati
int addres13 = 12, addres14 = 13, addres15 = 14, addres16 = 15;
// addres menit mati
int addres17 = 16, addres18 = 17, addres19 = 18, addres20 = 19;
//addres detik mati
int addres21 = 20, addres22 = 21, addres23 = 22, addres24 = 23;





int setpilih = 0, set = 0, kondisinyala = 0, kondisisave = 0;

int aktifpin1 = 0, aktifpin4 = 0, aktifpin3 = 0, aktifpin2 = 0;

int counterstep = 0;
//bool stopcount= false;

/*int updatecountjam1, updatecountmenit1,updatecountdetik1;
  int updatecountjam2, updatecountmenit2,updatecountdetik2;
  int updatecountjam3, updatecountmenit3,updatecountdetik3;
  int updatecountjam4, updatecountmenit4,updatecountdetik4;*/

unsigned long  currenttime1, currenttime2, currenttime3, currenttime4;
unsigned long  currenttimenyala1, currenttimenyala2, currenttimenyala3, currenttimenyala4;
unsigned long  currenttimemati1, currenttimemati2, currenttimemati3, currenttimemati4;

unsigned long  detikmati1count, detikmati2count, detikmati3count, detikmati4count;

unsigned long  currentimenyala, currenttimemati, currenttimeflow, resettimeflow, currenttimebutton, timebutton ;
unsigned long  currentimenyalastepper, currenttiming, currenttimelcd, currenttimenobacklcd;


bool masuksetting = false, masukpilih = false;

bool  nyala = false, nyala1 = false, nyala2 = false,  nyala3 = false, nyala4 = false;

bool save1 = false, save4 = false, save3 = false, save2 = false;

String kondisi1 = "OFF", kondisi4 = "OFF", kondisi3 = "OFF", kondisi2 = "OFF";

String kondisisave1 = "OFF", kondisisave2 = "OFF", kondisisave3 = "OFF", kondisisave4 = "OFF";
int triglight = 0;
int trigstepper = 0;
bool buka = false;
bool tutup = false;



#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


void flow () // Interrupt function
{
  flow_frequency++;
}


void setuppin()
{
  pinMode(flowsensor, INPUT);
  pinMode(pin_out1 , OUTPUT);
  pinMode(pin_out2 , OUTPUT);
  pinMode(pin_out3 , OUTPUT);
  pinMode(pin_out4 , OUTPUT);
  // pinMode(ledbutton , OUTPUT);
  // pinMode(buzzer , OUTPUT);
  // digitalWrite(buzzer,LOW);


  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(select, INPUT_PULLUP);
  pinMode(cancel, INPUT_PULLUP);
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  digitalWrite(ENA, LOW);

  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING);
  sei(); // Enable interrupts


}
