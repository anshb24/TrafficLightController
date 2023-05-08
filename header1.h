#define DELAY 2000
#define ON 0x01
#define OFF 0x00

#define PUSH_BUTTON (1U<<10) //pin 16 offset - PUSH BUTTON PIN 16
// #define NS2 (1U<<11) //pin 17 offset
// #define ES1 (1U<<12) //pin 18 offset
// #define ES2 (1U<<13) //pin 19 offset

#define NSR (1U<<1)       //pin 9 offset        
#define NSY (1U<<2)       //pin 10 offset
#define NSG (1U<<18)       //pin 2 offset
#define EWR (1U<<19)       //pin 3 offset    
#define EWY (1U<<20)       //pin 4 offset
#define EWG (1U<<21)       //pin 5 offset 
#define PR  (1U<<22)       //pin 6 offset
#define PG  (1U<<23)       //pin 7 offset

void setupGPIO();
int setLED(int color, int state);
void delay(int milliseconds);
int checkBot(); 
