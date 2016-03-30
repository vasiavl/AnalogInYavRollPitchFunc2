void smoothRunning()
{
if (flag !=flagP){Rdriv=Ldriv=R=L=0; flagP=flag; }// если предыдущее состояние флага было иное бортовые двиг. стоп.
if (flagY !=flagYF){Rdriv=Ldriv=R=L=0; flagYF=flagY; }
   if  (Rdriv-R >10)  { Rdriv=Rdriv-5;} 
   else {if (R-Rdriv>10)Rdriv=Rdriv+5;
        else Rdriv=R;  }
    if (L-Ldriv>10) { Ldriv=Ldriv+5; }
    else {
      if (Ldriv-L >10) Ldriv=Ldriv-5;
          else Ldriv=L; } }
