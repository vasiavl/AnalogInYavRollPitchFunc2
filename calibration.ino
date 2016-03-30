void calibration()// запускается при подаче питания с зажатой кнопкой
{ 
  
 if(But1==1 ) 
  { while(n<200) { n++;  delay(10);
 //  for (int i=0; i<= 25; i++)   {int n++;    }
     if (n>20) {// качаем джой возле нейтрали
      if (minVariationPitch>Pitch) minVariationPitch=Pitch;
      if (maxVariationPitch<Pitch) maxVariationPitch=Pitch;
      if (minVariationRoll>Roll)   minVariationRoll= Roll;
      if (maxVariationRoll<Roll)   maxVariationRoll=Roll;
      if (minVariationYaw>Yaw)     minVariationYaw=Yaw;
      if (maxVariationYaw<Yaw)     maxVariationYaw=Yaw;
      
      if (minPitch>Pitch<200) minPitch=Pitch;
      if (maxPitch<Pitch>700) maxPitch=Pitch;
      if (minRoll>Roll<200)   minRoll= Roll;
      if (maxRoll<Roll>700)   maxRoll=Roll;
      if (minYaw>Yaw<200)     minYaw=Yaw;
      if (maxYaw<Yaw>700)     maxYaw=Yaw;
       } 
     }
   if (But1==0 )  n=0;
     
 }     





             
















