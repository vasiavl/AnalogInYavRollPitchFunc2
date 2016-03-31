void calibration()// запускается при подаче питания с зажатой кнопкой
{ int n=0; 
  
 if(But1==1 ) 
  { delay(10);
   if(But1==1 ){ 
   while(n<100){ n++;   delay(10);
 
     if (n>10)       {Yaw = analogRead(analogInYawPin) / 4;// перевести значение  0-1023 к одному байту 0 до 255. 
                      Roll = analogRead(analogInRollPin) / 4; 
                      Pitch = analogRead(analogInPitchPin) / 4;// качаем джой возле нейтрали
      if (minVariationPitch>Pitch) minVariationPitch=Pitch;
      if (maxVariationPitch<Pitch) maxVariationPitch=Pitch;
      if (minVariationRoll>Roll)   minVariationRoll= Roll;
      if (maxVariationRoll<Roll)   maxVariationRoll=Roll;
      if (minVariationYaw>Yaw)     minVariationYaw=Yaw;
      if (maxVariationYaw<Yaw)     maxVariationYaw=Yaw;
      
      if ((minPitch>Pitch)&&(Pitch<200)) minPitch=Pitch;
      if  ((maxPitch<Pitch)&&(Pitch>700)) maxPitch=Pitch;
      if  ((minRoll>Roll)&&(Roll<200))   minRoll= Roll;
      if  ((maxRoll<Roll)&&(Roll>700))   maxRoll=Roll;
      if  ((minYaw>Yaw)&&(Yaw<200))     minYaw=Yaw;
      if  ((maxYaw<Yaw)&&(Yaw>700))     maxYaw=Yaw;
                     } 
      }
                                                           {
  EEPROM.write( 2 , minPitch );// записываем значение / 4 в энергонезависимую память
  EEPROM.write( 3 , maxPitch );
  EEPROM.write( 4 ,minRoll  );
  EEPROM.write( 5 ,maxRoll  );
  EEPROM.write( 6 ,minYaw  );
  EEPROM.write( 7 , maxYaw  );
  EEPROM.write( 8 ,minVariationPitch  );
  EEPROM.write( 9 ,maxVariationPitch  );// записываем значение в энергонезависимую память
  EEPROM.write( 10 ,minVariationRoll  );
  EEPROM.write(11  ,maxVariationRoll  );
  EEPROM.write( 12 ,minVariationYaw  );
  EEPROM.write(13  , maxVariationYaw );
   delay(100);
                                                              }
            
  }
   if (But1==0 ) 
     
                        { n=0;
  
  //value = EEPROM.read(1);// считываем значение по текущему адресу EEPROM
  minPitch=          (EEPROM.read(2))*4;// считываем значение по текущему адресу EEPROM
  maxPitch=          (EEPROM.read(3))*4;
  minRoll=           (EEPROM.read(4))*4;
  maxRoll =           (EEPROM.read(5))*4;
  minYaw =            (EEPROM.read(6))*4;
  maxYaw  =            (EEPROM.read(7))*4;
  minVariationPitch  = (EEPROM.read(8))*4;
  maxVariationPitch  = (EEPROM.read(9))*4;
  minVariationRoll   =  (EEPROM.read(10))*4;
  maxVariationRoll   =  (EEPROM.read(11))*4;
  minVariationYaw    =   (EEPROM.read(12))*4;
  maxVariationYaw    =   (EEPROM.read(13))*4;
  
  
  Serial.print("\t minPitch");
  Serial.print(minPitch, DEC);
  Serial.print("\t maxPitch  ");
  Serial.print( maxPitch );
   Serial.print("\t minRoll ");
  Serial.print( minRoll );
   Serial.print("\t   maxRoll");
  Serial.print( maxRoll  );
   Serial.print("\t minYaw ");
  Serial.print( minYaw );
   Serial.print("\t maxYaw  ");
  Serial.print( maxYaw  );
   Serial.print("\t minVariationPitch  ");
  Serial.print( minVariationPitch  );
   Serial.print("\t maxVariationPitch ");
  Serial.print( maxVariationPitch );
  Serial.print("\t minVariationRoll ");
  Serial.print( minVariationRoll );
  Serial.print("\t maxVariationRoll ");
  Serial.print( maxVariationRoll );
  Serial.print("\t  minVariationYaw ");
  Serial.print(  minVariationYaw );
  Serial.print("\t maxVariationYaw ");
  Serial.print( maxVariationYaw );
  
  Serial.println( );
  
    
  delay(500);
                         }
}    

}  

  
  
  
  




             
















