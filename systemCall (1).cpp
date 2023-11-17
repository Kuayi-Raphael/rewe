#include <iostream>
#include "systemCall.h"
#include <regex>
#include <string>
#include <stdlib.h>
#include <stdbool.h>
#include <sstream>

 using namespace std;

 
string uinput;

int num;

 
int
acceptInput ()
{
  
int input = 0;
  
cout << "Enter a value to be located in memory: ";
  
if (checkInput (input))
    {
      
return input;
    
}
  
  else
    {
      
cout << "Input Fail!!\n";
      
return -1;		//input = acceptInput();
    }
  
cout << "Enter a value to be located in memory: ";
  
cin >> uinput;
  
 
 
stringstream (uinput) >> num;
  
 
return num;

}


 
bool checkInput (int &input)
{
  
bool floatcheck = typeid (input) == typeid (int) ? false : true;
  
if (cin >> input && floatcheck)
    {
      
return true;
    
}
  
return false;
  
if (!regex_match (uinput, regex ("\\d")))
    
return false;
  
  else
    {
      
regex validInput ("0?[1-9]||1[0-9]||20");
      
bool isValid = regex_match (uinput, validInput);
      
return isValid;
    
}

}


 
void
informMemory (int mem, int val, int cache1[], int cache2[], int ram[]) 
{
  
switch (mem)
    {
    
case 1:
      
cout << val << " found in Cache 1\n";
      
break;
    
case 2:
      
cout << val << " found in Cache 2\n";
      
break;
    
case 3:
      
cout << val << " found in RAM\n";
      
break;
    
default:
      
cout << val << " not Found\n";
      
cout << val << " has been added to memory.\n";
      
break;
    
}
  
 
    ///Display memory contents
    cout << "\n";
  
cout << "Cache 1\tCache 2\tRAM\n";
  
for (int i = 0; i < 20; i++)
    {
      
if (i >= 0 && i < 5)
	printf ("  %d\t  %d\t  %d\n", cache1[i], cache2[i], ram[i]);
      
      else if (i > 4 && i < 10)
	printf ("\t  %d\t  %d\n", cache2[i], ram[i]);
      
      else
	printf ("\t\t  %d\n", ram[i]);
    
}

}


 
bool repeatProgram ()
{
  
int cont = 0;
  
cout << "Press 1 to Re-run or any other number to exit: ";
  
if (cin >> cont && cont == 1)
    
return true;
  
  else
    return false;

}


