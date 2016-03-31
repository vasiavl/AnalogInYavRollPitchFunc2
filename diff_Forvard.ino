int differentialForward_ago()
{ 
   if (440>Pitch) // вперед-outputPitchD
   {    if (forwardR==HIGH ||forwardL==HIGH)
                                             {forwardR =forwardL=flag= LOW; R=L=Ldriv=Rdriv =0;}
       if (440>Roll)    {            R= outputPitchD;  //left
                                     L= outputPitchD -(outputPitchD*outputRoll)/150;
                        }
       if ((580>Roll)&& (Roll>440))  R=L=outputPitchD;                                                     
       if  (Roll>580)   {            L= outputPitchD;  
                                     R= outputPitchD-(outputPitchD*outputRollR)/150;
                        }
   }  
 if (Pitch > 580) //назад-outputPitch
  {   if (forwardR==LOW ||forwardL==LOW){forwardR =forwardL=flag= HIGH ; R=L=Ldriv=Rdriv = 0; }   //   пипец какой баг!!!
                                                                                
     if  (440>Roll)     {             R= outputPitch;  
                                      L= outputPitch-(outputPitch*outputRoll)/150;
                        }          
     if  ((580>Roll)&& (Roll>440))    R=L= outputPitch;   
     if  (Roll>580)     {             L= outputPitch;   
                                      R= outputPitch-(outputPitch*outputRollR/150);
                        }
    } 
 }
