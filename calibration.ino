void calibration()// запускается при подаче питания с зажатой кнопкой
{ int n=0; 
  
  
   while(n<100){ n++;
     
       minVariationPitch=minPitch=Pitch-50; maxVariationPitch=maxPitch=Pitch+50;
       minVariationRoll= minRoll=Roll-50; maxVariationRoll=maxRoll=Roll+50;
       minVariationYaw=minYaw=Yaw-50; maxVariationYaw=maxYaw=Yaw+50;}
                
      while((Pitch>=minPitch)&&(Pitch-minPitch<20)&&(20>=Roll-minRoll)&&(minRoll<=Roll)){
      if (minPitch>Pitch) minPitch=Pitch;
      if (minRoll>Roll)  minRoll= Roll;    delay(10) ;                                    }
      //blinc
      while((maxPitch>=Pitch)&&(maxPitch-Pitch<20)&& (maxRoll>=Roll)&& (maxRoll-Roll>20)){
      if (maxPitch<Pitch) maxPitch=Pitch;
      if(maxRoll<Roll)    maxRoll=Roll;          delay(10);                               }
          //blinc                                                                                     
      if  ((minYaw>Yaw)&&(Yaw<200))     minYaw=Yaw;
      if  ((maxYaw<Yaw)&&(Yaw>700))     maxYaw=Yaw;
                      
      
                                                           {
  EEPROM.write( 2 , minPitch/ 4 );// записываем значение / 4 в энергонезависимую память
  EEPROM.write( 3 , maxPitch/ 4 );
  EEPROM.write( 4 ,minRoll/ 4  );
  EEPROM.write( 5 ,maxRoll / 4 );
  EEPROM.write( 6 ,minYaw / 4 );
  EEPROM.write( 7 , maxYaw / 4 );
  EEPROM.write( 8 ,minVariationPitch/ 4  );
  EEPROM.write( 9 ,maxVariationPitch/ 4  );// записываем значение в энергонезависимую память
  EEPROM.write( 10 ,minVariationRoll/ 4  );
  EEPROM.write(11  ,maxVariationRoll/ 4  );
  EEPROM.write( 12 ,minVariationYaw/ 4  );
  EEPROM.write(13  , maxVariationYaw/ 4 );
   delay(100);
                                                              
            
  }
   
     
                        
  
  //value = EEPROM.read(1);// считываем значение по текущему адресу EEPROM
//  minPitch=          (EEPROM.read(2))*4;// считываем значение по текущему адресу EEPROM
//  maxPitch=          (EEPROM.read(3))*4;
//  minRoll=           (EEPROM.read(4))*4;
//  maxRoll =           (EEPROM.read(5))*4;
//  minYaw =            (EEPROM.read(6))*4;
//  maxYaw  =            (EEPROM.read(7))*4;
//  minVariationPitch  = (EEPROM.read(8))*4;
//  maxVariationPitch  = (EEPROM.read(9))*4;
//  minVariationRoll   =  (EEPROM.read(10))*4;
//  maxVariationRoll   =  (EEPROM.read(11))*4;
//  minVariationYaw    =   (EEPROM.read(12))*4;
//  maxVariationYaw    =   (EEPROM.read(13))*4;
//  
  
//  Serial.print("\t minPitch");
//  Serial.print(minPitch, DEC);
//  Serial.print("\t maxPitch  ");
//  Serial.print( maxPitch );
//   Serial.print("\t minRoll ");
//  Serial.print( minRoll );
//   Serial.print("\t   maxRoll");
//  Serial.print( maxRoll  );
//   Serial.print("\t minYaw ");
//  Serial.print( minYaw );
//   Serial.print("\t maxYaw  ");
//  Serial.print( maxYaw  );
//   Serial.print("\t minVariationPitch  ");
//  Serial.print( minVariationPitch  );
//   Serial.print("\t maxVariationPitch ");
//  Serial.print( maxVariationPitch );
//  Serial.print("\t minVariationRoll ");
//  Serial.print( minVariationRoll );
//  Serial.print("\t maxVariationRoll ");
//  Serial.print( maxVariationRoll );
//  Serial.print("\t  minVariationYaw ");
//  Serial.print(  minVariationYaw );
//  Serial.print("\t maxVariationYaw ");
//  Serial.print( maxVariationYaw );
//  
//  Serial.println( );
  
    
//  delay(500);
                         


}  

  
  
  
  




             
















