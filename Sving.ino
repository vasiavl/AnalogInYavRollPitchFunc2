  int Sving(void)
{if  (Roll>580)//   right
  { tvistFlag= LOW;   tvist=240 ;
    if ( tvistRoll- sensorSwing <=60)tvist=0 ;
   }      
  if  (580>Roll&& Roll>440)//timeY=0 ;
   { if  ( 580 > sensorSwing && sensorSwing >440) tvist=0 ; 
     if  ( 580 < sensorSwing){tvistFlag= HIGH; tvist= map(sensorSwing ,560,1023,100,200) ; }
     if  ( 440 >sensorSwing){tvistFlag= LOW; tvist= map(sensorSwing ,460,0,100,200); }
   }  
  
  if  (440>Roll)//left
   {   tvistFlag= HIGH;  tvist=240 ;
   if (sensorSwing-tvistRoll<=20 )tvist=0 ;   
   }}
