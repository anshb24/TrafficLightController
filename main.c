#include <stdio.h>
#include "header1.h" 
int main()
{
int state = 1; 
int error = 0;
int count = 0;
setupGPIO();
while(1)
{
    switch(state)
        {

            case 1: //initial state - both ways red light
                setLED(NSR|EWR|PR, ON);
                delay(3000);
                if(checkBot(PUSH_BUTTON))
                {
                    setLED(PR,OFF);
                    setLED(PG,ON);
                    delay(15000);
                    setLED(PG,OFF);
                    state = 1;
                }
                else if(!checkBot(PUSH_BUTTON))
                {                
                    delay(10000); //after 10 seconds
                    state = 2;

                }
                break;
            
            case 2: // North South Green , East West Red
                   setLED(NSR, OFF);                   
                   setLED(NSG|PR, ON);
                   delay(3000); //
                   if(checkBot(PUSH_BUTTON))
                    {
                        setLED(NSG,OFF);
                        while(!error)
                        {
                            setLED(NSY,ON);
                            delay(500);
                            error = setLED(NSY,OFF);
                            delay(500);
                            count++;
                            if(count>10)
                            {
                            break;
                            }
                        }
                        setLED(PR,OFF);
                        setLED(NSR|PG,ON);
                        delay(15000);
                        setLED(PG,OFF);
                        state = 1;
                    }
                else if(!checkBot(PUSH_BUTTON))
                { 
                   delay(20000); //after 20 seconds
                   state = 3;
                }
                   break;
            
             case 3: // North South Yellow after 3 seconds, North South red, East west red
                   setLED(NSG|NSR, OFF);
                   setLED(NSY|PR, ON);
                   delay(3000); // 3 seconds
                   if(checkBot(PUSH_BUTTON))
                    {
                    setLED(PR|NSY,OFF);
                    setLED(PG|NSR,ON);
                    delay(15000);
                    setLED(PG,OFF);
                    state = 2;
                    }
                    else if(!checkBot(PUSH_BUTTON))
                    {
                   state = 4;
                    }
                   break;
            case 4:
                   setLED(NSY, OFF);
                   setLED(NSR|PR, ON);
                   delay(5000); // 5 seconds
                   if(checkBot(PUSH_BUTTON))
                    {
                    setLED(PR,OFF);
                    setLED(PG,ON);
                    delay(15000);
                    setLED(PG,OFF);
                    state = 3;
                    }
                    else if(!checkBot(PUSH_BUTTON))
                    {
                    state = 5;
                    }
                    break;
            
             case 5: // North South red, east west green
                   setLED(EWR, OFF);
                   setLED(EWG|PR, ON);
                   delay(3000); 
                    if(checkBot(PUSH_BUTTON))
                    {
                        setLED(EWG,OFF);
                        count=0;
                        while(!error)
                        {
                            setLED(EWY,ON);
                            delay(500);
                            error = setLED(EWY,OFF);
                            delay(500);
                            count++;
                            if(count>10)
                            {
                            break;
                            }
                        }
                        setLED(PR,OFF);
                        setLED(EWR|PG,ON);
                        delay(15000);
                        setLED(PG,OFF);
                        state = 4;
                    }
                    else if(!checkBot(PUSH_BUTTON))
                    {
                   delay(20000);
                   state = 6;
                    }
                   break;
            
             case 6: // after 20 seconds
                   setLED(EWG, OFF);
                   setLED(EWY, ON);
                   delay(3000);
                   if(checkBot(PUSH_BUTTON))
                    {
                    setLED(PR|EWY,OFF);
                    setLED(PG|EWR,ON);
                    delay(15000);
                    setLED(PG,OFF);
                    state = 5;
                    }
                    else if(!checkBot(PUSH_BUTTON))
                    {
                   setLED(EWY, OFF);
                   setLED(EWR, ON);
                   delay(5000);     
                   state = 1;
                    }
                   break;
            
        }
    }
  }
