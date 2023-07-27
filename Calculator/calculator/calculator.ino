#include <Keypad.h>
#include<LiquidCrystal.h>
// functions that take the character type as input and return an integer
double CalculateNumberFromInput(char Input);
double CalculateOperationFromInput(char Input);
double CalculateNumberFromArray(double Array[], int Length); 
 
 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte ROWS = 4;
const byte COLS = 4;

char hexKeys[ROWS][COLS] ={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','='},
  {'*','0','C','/'}, 
};
byte rowPins[ROWS]={6,7,8,9};
byte colPins[COLS]={10,A0,A1,A2};

typedef enum CalcEntrySeq_t{
  FirstNumber = 0,
  SecondNumber = 1,
  ResetCalculator =2,
};
CalcEntrySeq_t CalcEntry = FirstNumber;

typedef enum Operation_t{
  Addition = 0,
  Subtraction,
  Multiplication,
  Division,
  No_Operation,  
};
Operation_t InputOperation = No_Operation;

const int MaxNumLength = 7;
double FirstNumberArray[MaxNumLength] = {0};
double SecondNumberArray[MaxNumLength] = {0}; 
static double FinalFirstNumber = 0;
static double FinalSecondNumber = 0;
static int PositionPointerFirstNum = 0;
static int PositionPointerSecondNum = 0;
//intialize an instance of Keypad class
Keypad customKeypad = Keypad(makeKeymap(hexKeys), rowPins, colPins, ROWS, COLS);
  
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600); 
}
void loop(){
   char customKey = customKeypad.getKey();

   if((NO_KEY != customKey) && ('C' != customKey))
   {
    switch(CalcEntry)
    {
      case FirstNumber:
      {
        if((PositionPointerFirstNum < MaxNumLength) && (customKey != '+') && (customKey != '-') && (customKey != '*') && (customKey != '/'))
        {
         if(PositionPointerFirstNum == 0)
         {
          lcd.clear();
          lcd.setCursor(0, 0);   
         }
         FirstNumberArray[PositionPointerFirstNum]= CalculateNumberFromInput(customKey);
         lcd.print(customKey);
         PositionPointerFirstNum++;
        }
        else if((customKey == '+') || (customKey == '-') || (customKey == '*') || (customKey == '/'))
        {
         InputOperation = (Operation_t)CalculateOperationFromInput(customKey);
          lcd.print(customKey);
          CalcEntry = SecondNumber;      
        }
        break;
      }
      case SecondNumber: 
      {
        if((PositionPointerSecondNum < MaxNumLength) && (customKey != '='))
        {
          SecondNumberArray[PositionPointerSecondNum]= CalculateNumberFromInput(customKey);
          lcd.print(customKey);
          PositionPointerSecondNum++;
         }
         else if (customKey == '=') 
         {
           double FinalCalculation = 0;
           FinalFirstNumber= CalculateNumberFromArray(FirstNumberArray,PositionPointerFirstNum);
           FinalSecondNumber= CalculateNumberFromArray(SecondNumberArray,PositionPointerSecondNum);

           if(InputOperation == Addition)
           {
            FinalCalculation = FinalFirstNumber + FinalSecondNumber; 
           }
           else if(InputOperation == Subtraction)
           {
            FinalCalculation = FinalFirstNumber - FinalSecondNumber; 
           }
           else if(InputOperation == Multiplication)
           {
            FinalCalculation = FinalFirstNumber * FinalSecondNumber; 
           } 
           else if(InputOperation == Division)
           {
            FinalCalculation = FinalFirstNumber / FinalSecondNumber; 
           }
           lcd.setCursor(0, 1);
           lcd.print("Ans=");
           lcd.print(FinalCalculation);
           PositionPointerFirstNum = 0;
           PositionPointerSecondNum = 0;
           CalcEntry = FirstNumber;
           InputOperation = No_Operation; 
           
         }  
         break;
      }
      default:
      {
        break;
      }
      
    }
   }
    else if (customKey == 'C')
    {
      PositionPointerFirstNum = 0;
      PositionPointerSecondNum = 0;
      CalcEntry = FirstNumber;
      InputOperation = No_Operation;
      lcd.clear(); 
            
    }
}


double CalculateNumberFromInput(char Input)
{
 double Result;
 switch(Input)
 {

   case '0':
   {
    Result = 0;
    break; 
   }
   case '1':
   {
    Result = 1;
    break; 
   }
   case '2':
   {
    Result = 2;
    break; 
   }
   case '3':
   {
    Result = 3;
    break; 
   }
   case '4':
   {
    Result = 4;
    break; 
   }
   case '5':
   {
    Result = 5;
    break; 
   }
   case '6':
   {
    Result = 6;
    break; 
   }
   case '7':
   {
    Result = 7;
    break; 
   }
   case '8':
   {
    Result = 8;
    break; 
   }
   case '9':
   {
    Result = 9;
    break; 
   }
  
   
 }
 return Result;
}
double CalculateOperationFromInput(char Input){
    double Result;
   switch(Input)
   {
    case '+':
    {
      Result= double(Addition);
      break;
    }
    case '-':
    {
      Result= double(Subtraction);
      break;
    }
    case '*':
    {
      Result= double(Multiplication);
      break;
    }
    case '/':
    {
      Result= double(Division);
      break;
    } 
   }
   return Result; 
}

double CalculateNumberFromArray(double Array[], int Length)
{
 double Result =0;
 float MultiplierFact = 0;  
 for(int cnt = 0; cnt < Length; cnt++)
 {
  MultiplierFact = float(Length - 1 - cnt);
  Result = Result + (double)(Array[cnt] * pow((float)10, MultiplierFact));   
 }
 return Result;
}

 
