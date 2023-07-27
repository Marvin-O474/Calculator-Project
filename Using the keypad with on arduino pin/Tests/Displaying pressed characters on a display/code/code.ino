//intilizing the LCD display 
#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs, en, d4, d5,d6,d7);
 
//for the keypad 
int keyIn =0;
//creating an array for values read from the analog pin
int keyVals [16] = {561,465,330,611,536,436,651,592,515,635,684,574,48,246,378,470};
//creating an array for characters on the keypad
char keys[16]= {'1','2','3','4','5','6','7','8','9','0','*','-','+','B','/','='};


void setup(){
  lcd.begin(16,2);
}
void loop(){
  //read form analog pin of keypad
  keyIn= analogRead(A0);
  delay(100);
  /*using the value gotten from the analog read, scan through the "keyVals" array and  
   print out the respective key character in the "keys" array.  
   */
  for(int i=0; i<=15; i++){
   if(abs(keyIn-keyVals[i])<5){
    lcd.print(keys[i]);
   delay(1000); 
    
   }
  }

}
