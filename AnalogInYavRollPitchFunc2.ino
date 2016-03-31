 #include <EEPROM.h>
 
//#define Button_1      5//че то какая то фигня с этим пином
// #define Button_2      13
// #define Button_3      12
const int analogInYawPin = A0;  // резистор джоя по Yaw
const int analogInRollPin = A2; // резистор джоя по Roll
const int analogInPitchPin = A4; // пин для резистора по Pitch
const int sensorSwingPin = A5; // датчик положения рулевых колес 
 #define forward_agoPinR         7// управляет реверсом правого двигателя
 #define forward_agoPinL         4// управляет реверсом левого двигателя
 #define analogWritePRYPinR      11// ШИМ на правый ходовой мотор
 #define analogWritePRYPinL      10 // ШИМ на левый  ходовой мотор
  #define analogWriteRPin        9  // ШИМ на рулевой мотор
 #define LRPin                   8// управляет реверсом мотора руля

int sensorSwing = 0;//значения датчика положение рулевых колес
int tvist=0;// ШИМ рулевого двигателя
int tvistFlag;//значение реверса рулевого мотора
int  Roll,tvistTrans, tvistRoll = 0; //преобразуем значения (приечем обрезанные 823-300) Roll в tvistRoll 1-1023
int  outputRoll,outputRollR = 0; // положение Roll через map в 0-255  для корректировки скорости бортовых двигателей  
int Yaw,outputYawL,outputYawR  = 0;
int flagY,flagYF; //флаг право -лево по Yaw и flagYF -предыдущего состояния
int Pitch = 0;        
int outputPitch = 0;
int outputPitchD = 0;
int L,Ldriv = 0; // шим левого двигателя
int R,Rdriv = 0;// шим правого двигателя

int But1=0;
int But2=0;   //20
int But3=0;
int forwardR,forwardL =0;//состояние реверса бортовых двигателей 
int flag,flagP; //flag "вперед-назад"  flagP-предыдущее состояние флага
int minVariationPitch=440; int minVariationRoll=440;  int minVariationYaw=440;
int maxVariationPitch=580; int maxVariationRoll=580; int maxVariationYaw=580;
int minPitch, minRoll, minYaw=0;
int maxPitch, maxRoll, maxYaw= 1023;
void setup() {
//    pinMode(Button_1, INPUT_PULLUP);
//    pinMode(Button_2, INPUT_PULLUP);
//    pinMode(Button_3, INPUT_PULLUP);
    pinMode(forward_agoPinR, OUTPUT);
    pinMode(forward_agoPinL, OUTPUT);
     pinMode(LRPin, OUTPUT);
  Serial.begin(9600); 
 // calibration();
}


void loop() {
  // read the analog in value:
  Yaw = analogRead(analogInYawPin); 
  Roll = analogRead(analogInRollPin); 
  Pitch = analogRead(analogInPitchPin);
  sensorSwing=analogRead(sensorSwingPin );
  forwardR=  digitalRead(forward_agoPinR);
  forwardL=  digitalRead(forward_agoPinL);
  outputRoll = constrain( map(Roll, 440, 300, 0, 100),0,100);//отклонение джоя в проценты
  outputRollR = constrain( map(Roll, 580, 723, 0, 100),0,100);//отклонение джоя в проценты
  tvistTrans =  map(Roll, 823, 300, 1023, 0);// зажимаем джой чтобы для поворота не надо было его отклонять на 100%
  tvistRoll = constrain(tvistTrans, 0, 1023);// фактически значение на которое колеса должны повернуть
  outputPitch = map(Pitch, 580, 1023, 0, 255); 
  outputPitchD = map(Pitch, 440, 0, 0, 255); 
  outputYawL = map(Yaw, 580, 1023, 0, 255); 
  outputYawR = map(Yaw, 440, 0, 0, 255);
 //=============== работа дифференциала при поворотах и движение впередх-назад ========================
 differentialForward_ago();
 
  //================танковый разворот================================================
  tankSpread ();
      
//=============================Swing===============================================
 Sving();

  // ==================плавная работа бортовых моторов=================================== 
   smoothRunning();
   // ====================  пишем значения в исполнительные выходы=============================        
     analogWrite(analogWriteRPin, tvist);  //tvist 
     digitalWrite( LRPin, tvistFlag);// tvistFlag  реверс руля
    digitalWrite(forward_agoPinL , forwardL );
     digitalWrite(forward_agoPinR ,  forwardR);//forwardR переключение реверса правого двигателя
    analogWrite(analogWritePRYPinR, Rdriv);//Rdriv
    analogWrite(analogWritePRYPinL, Ldriv); 
//   But1=    digitalRead(Button_1);
//    But2= digitalRead(Button_2);       
//    But3=  digitalRead(Button_3);
   //serialPrint();               
}

