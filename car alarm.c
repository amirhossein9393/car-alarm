#include <io.h>
#include <delay.h>


unsigned int high,low;
char remote[24];
unsigned char lockk=1, code,  x, khold;
//char mainremote[20]={'1','0','0','0','0','0','1','1','0','0','1','0','1','0','1','0','0','0','0','1'};
//char mainremote[20] = {'0','1','1','0','0','0','1','1','1','1','1','0','1','1','1','0','1','1','1','0'};
eeprom char mainremote[20];

void digit();
void timerconfig();
void keyread();
void remoteread();
void set();
void san();
void decode();
void lock();
void rlearn();
void unlock();
void siren();
void silent();
void sensoer();
//void win();
void WDT_Turn_on();
void WDT_Turn_off();


interrupt[TIM1_CAPT] void timer1_capt_vect(void)
{
digit();
 }

void main(void)
{
    DDRC = 0;
    PORTC = 0xff;
    //PORTC &= ~(1 << PC1);  write down
    PORTC.1 = 0;

    DDRD = 0xff;
    PORTD = 0;

    TCCR1B = (1 << ICES1);          // timer1
    TIMSK = (1 << TICIE1);
    #asm("sei")
   WDT_Turn_on();

  // PORTD.2 = 1;

    while (1)
    {
       sensoer();
      // rlearn();
    }
}

void digit(void)
{
     set();
    TIFR |= (1 << ICF1);
    TCCR1B |= (1 << CS10) | (1 << ICES1);

    while((TIFR&(1 << ICF1)) == 0)      #asm("wdr")

    TCCR1B = (1 << CS11) | (0 << ICES1);
    TIFR = (1 << ICF1);
    ICR1 = 0;
    TCNT1 = 0;

    while((TIFR&(1 << ICF1)) == 0)      #asm("wdr")

    high = ICR1;
    TCCR1B = (1 << CS11) | (1 << ICES1);
    TIFR = (1 << ICF1);

    while((TIFR&(1 << ICF1)) == 0)      #asm("wdr")

    low = ICR1 - high;


    if( (high > 140) & (high < 310) & (low > high*20) &  (low < high*60) & (PINC.4 == 1) ) decode();
            else if( (high > 140) & (high < 310) & (low > high*20) &  (low < high*60) & (PINC.4 == 0) )   rlearn();

//sensoer();

}

void decode(void)
{
    //sensoer();
     WDT_Turn_off();

     remoteread();

     WDT_Turn_on();


     // sensoer();

       if( (remote[0] == mainremote[0]) & (remote[1] == mainremote[1]) & (remote[2] == mainremote[2]) & (remote[3] == mainremote[3]) & (remote[4] == mainremote[4])
             & (remote[5] == mainremote[5]) & (remote[6] == mainremote[6]) & (remote[7] == mainremote[7]) & (remote[8] == mainremote[8]) & (remote[9] == mainremote[9])
             &(remote[10] == mainremote[10]) & (remote[11] == mainremote[11]) & (remote[12] == mainremote[12]) & (remote[13] == mainremote[13]) & (remote[14] == mainremote[14])
             &(remote[15] == mainremote[15]) & (remote[16] == mainremote[16]) & (remote[17] == mainremote[17]) & (remote[18] == mainremote[18]) & (remote[19] == mainremote[19]) ) keyread();

             else khold = 0;

sensoer();
x=0;
 }

void remoteread()
{
 timerconfig();
     if (high > low)   remote[0] = '1';
     else if (high < low)   remote[0] = '0';

       timerconfig();
     if (high > low)   remote[1] = '1';
     else if (high < low)   remote[1] = '0';

       timerconfig();
     if (high > low)   remote[2] = '1';
     else if (high < low)   remote[2] = '0';

       timerconfig();
     if (high > low)   remote[3] = '1';
     else if (high < low)   remote[3] = '0';

       timerconfig();
     if (high > low)   remote[4] = '1';
     else if (high < low)   remote[4] = '0';

       timerconfig();
     if (high > low)   remote[5] = '1';
     else if (high < low)   remote[5] = '0';

       timerconfig();
     if (high > low)   remote[6] = '1';
     else if (high < low)   remote[6] = '0';

       timerconfig();
     if (high > low)   remote[7] = '1';
     else if (high < low)   remote[7] = '0';

       timerconfig();
     if (high > low)   remote[8] = '1';
     else if (high < low)   remote[8] = '0';

       timerconfig();
     if (high > low)   remote[9] = '1';
     else if (high <  low)   remote[9] = '0';

       timerconfig();
     if (high > low)   remote[10] = '1';
     else if (high < low)   remote[10] = '0';

       timerconfig();
     if (high > low)   remote[11] = '1';
     else if (high < low)   remote[11] = '0';

       timerconfig();
     if (high > low)   remote[12] = '1';
     else if (high < low)   remote[12] = '0';

       timerconfig();
     if (high > low)   remote[13] = '1';
     else if (high < low)   remote[13] = '0';

       timerconfig();
     if (high > low)   remote[14] = '1';
     else if (high < low)   remote[14] = '0';

       timerconfig();
     if (high > low)   remote[15] = '1';
     else if (high < low)   remote[15] = '0';

       timerconfig();
     if (high > low)   remote[16] = '1';
     else if (high < low)   remote[16] = '0';

       timerconfig();
     if (high > low)   remote[17] = '1';
     else if (high < low)   remote[17] = '0';

       timerconfig();
     if (high > low)   remote[18] = '1';
     else if (high < low)   remote[18] = '0';

       timerconfig();
     if (high > low)   remote[19] = '1';
     else if (high < low)   remote[19] = '0';

       timerconfig();
     if (high > low)   remote[20] = '1';
     else if (high < low)   remote[20] = '0';

       timerconfig();
     if (high > low)   remote[21] = '1';
     else if (high < low)   remote[21] = '0';

       timerconfig();
     if (high > low)   remote[22] = '1';
     else if (high < low)   remote[22] = '0';

       timerconfig();
     if (high > low)   remote[23] = '1';
     else if (high < low)   remote[23] = '0';

}

void keyread(void)
{
    #asm("wdr")
        if(( remote[20] == '1') & (remote[21] == '0') & (remote[22] == '0') & (remote[23] == '0'))  // lock
        {
          lock();
        }

        else if(( remote[20] == '0') & (remote[21] == '0') & (remote[22] == '0') & (remote[23] == '1'))  // unlock
        {
           unlock();
        }

        else if((remote[20] == '0') & (remote[21] == '1') & (remote[22] == '0') & (remote[23] == '0'))   //  silent
        {
            silent();
        }

        else if((remote[20] == '0') & (remote[21] == '0') & (remote[22] == '1') & (remote[23] == '0'))    //siren
        {
            siren();
        }
               #asm("wdr")
}

void timerconfig(void)
{
     TCCR1B = (1 << CS11) | (0 << ICES1);
     TIFR = (1 << ICF1);
     ICR1 = 0;
     TCNT1 = 0;

     while((TIFR&(1 << ICF1)) == 0);
     high = ICR1;
     TCCR1B = (1 << CS11) | (1 << ICES1);
     TIFR = (1 << ICF1);


     while((TIFR&(1 << ICF1)) == 0);
     low = ICR1 - high;
}

 void lock(void)
 {
     lockk = 1;

      PORTD.4 = 1; // close door

     //siren
       PORTD.1 = 1;         //  siren
       PORTD.5 = 1;         //  flasher
       delay_ms(150);
       PORTD.1 = 0;
       delay_ms(400);
       PORTD.4 = 0;
       PORTD.5 = 0;
       delay_ms(400);
 }

 void unlock(void)
 {

if(lockk == 1)
 {
     lockk = 0;

     PORTD.3 = 1; // open door
     PORTD.0 = 1; // gas pump on

      // siren
     PORTD.1 = 1;   //  siren
     PORTD.5 = 1;  // flasher
            delay_ms(150);
     PORTD.1 = 0;
            delay_ms(150);
     PORTD.1 = 1;
            delay_ms(150);
     PORTD.1 = 0;
     PORTD.0 = 0;
            delay_ms(200);
      PORTD.3 = 0;
     delay_ms(500);
     }
        else
          {
               khold++;
               delay_ms(200);
                if(khold == 7)     san();
                else if(khold >= 8)  khold = 0;
                }
     }

 void silent(void)
 {
     PORTD.1 = 0;  // siren off
    // PORTD.0 = 0;
 }

 void siren(void)
 {
     PORTD.1 = 1;
 }

 void sensoer(void)
 {
      #asm("wdr")

     if( (PINC.1 == 0) | (PINC.2 == 0) & (lockk == 1))  siren();     //     door

    // if( (PINC.2 == 1) & (lockk == 1))  siren();

 }

void set(void)
{
     high = 0;
     low = 0;
     ICR1 = 0;
     TCNT1 = 0;
       #asm("wdr")
 }

/* void win(void)     // win close
 {
            //          PORTC.3 for feedback of windows            //

    PORTD.6 = 1;    // win right close
         if(PINC.3 == 0)   PORTD.6 = 0;

 delay_ms(500);

      PORTD.7 = 1;      // win left close
        if(PINC.3 == 0)   PORTD.7 = 0;
 }*/

 void san(void)
 {
   PORTD.2 = 1;
   delay_ms(500);
   PORTD.2 = 0;
  }

void rlearn(void)
 {
   siren();

     WDT_Turn_off();

     for( code=0 ; code <= 23 ; code++)
	 {
	 TCCR1B = (1 << CS11) | (0 << ICES1);
	 TIFR = (1 << ICF1);
	 ICR1 = 0;
	 TCNT1 = 0;

	 while((TIFR&(1 << ICF1)) == 0);
	 high = ICR1;
	 TCCR1B = (1 << CS11) | (1 << ICES1);
	 TIFR = (1 << ICF1);


	 while((TIFR&(1 << ICF1)) == 0);
	 low = ICR1 - high;


	 if (high >= low)   eeprom mainremote[code]='1';
	 else if (high <= low)   eeprom mainremote[code]='0';


	 }
     WDT_Turn_on();
 }

 void WDT_Turn_on(void)
{
    // Watchdog Timer initialization
    // Watchdog Timer Prescaler: OSC/2048k - 2.2(s)
    WDTCR = (0<<WDTOE) | (1<<WDE) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0);
}

void WDT_Turn_off(void)
{
    //Reset WDT
    #asm("wdr")
    //Write logical one to WDTOE and WDE
    WDTCR |= (1<<WDTOE) | (1<<WDE);
    //Turn off WDT
    //WDTCR |= (0<<WDE);
    WDTCR = 0x00;
}