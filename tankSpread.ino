
 void tankSpread ()
{
if ((maxVariationPitch>Pitch)&& (Pitch >minVariationPitch))
    {  outputPitch=outputPitchD =0; //
    if (   Yaw>maxVariationYaw)//left
               {   forwardL= HIGH; forwardR= LOW; flagY= LOW;
 
                                                        L = 0;
                                                        R= outputYawL;
                                if (Yaw>(maxVariationYaw+300))            L= outputYawL;                                        
              }           
         if (minVariationYaw>Yaw)//rait
               { forwardL=LOW  ; forwardR=HIGH ; flagY= HIGH;
                                                        R= 0;  
                                                        L= outputYawR;
                                if ((minVariationYaw-300)>Yaw)           R= outputYawR;   
               }                                                      
          if ((maxVariationYaw>=Yaw)&& (Yaw >=minVariationYaw))   R=L=Ldriv=Rdriv =0;    
     }  }
 
