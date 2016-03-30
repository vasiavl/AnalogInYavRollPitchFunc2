
 void serialPrint()
 {
  Serial.print(" tvist = " );                       
  Serial.print(tvist); 
   Serial.print(" tvistFlag = ");      
  Serial.print(tvistFlag ); 
  Serial.println(" sensorSwing = " );                       
  Serial.println(sensorSwing );
 Serial.println("minVariationPitch = ");  
 Serial.println(minVariationPitch);
 Serial.println("miaxVariationPitch = ");  
 Serial.println(maxVariationPitch);
  Serial.print(" outputYawL = ");      
  Serial.print(outputYawL); 
  Serial.print(" outputYawR = ");      
  Serial.print(outputYawR ); 
  Serial.print(" Yaw = ");      
  Serial.print( Yaw); 
  Serial.print(" flagY=") ;            
  Serial.print(  flagY); 
 Serial.print(" flagYF=") ;            
  Serial.println( flagYF);

  Serial.print("\n Roll = " );                       
  Serial.print(Roll);      
  Serial.print("outputRoll = ");      
  Serial.print(outputRoll); 
   Serial.print("\t outputRollR = ");      
  Serial.print(outputRollR); 

       
  Serial.print("\n outputPitch = ");      
  Serial.print(outputPitch); 
  Serial.print("  R = " );                       
  Serial.print(R); 
  Serial.print(" Rdriv = " );                       
  Serial.print(Rdriv);
  Serial.print(" forwardR = ");            
  Serial.print(  forwardR); 
  Serial.print("\n outputPitchD = ");      
  Serial.print(outputPitchD); 
  Serial.print("  L = ");      
  Serial.print(L);
  Serial.print(" Ldriv = ");      
  Serial.print(Ldriv);
 Serial.print(" forwardL = ");            
  Serial.print(  forwardL); 
   Serial.print("\n Pitch = " );                       
  Serial.print(Pitch);
//     
 Serial.print("\t flag=") ;            
  Serial.print(  flag); 
 Serial.print("\t flagP=") ;            
  Serial.println(  flagP); 
 
   delay(2500);   }   
