#include <iostream>
#include <time.h>
#include "systemCall.h"

 using namespace std;

 
void populate (int arr[], int siz);

int searchVal (int arr[], int siz, int input);

void updateCache (int arr[], int brr[], int index);

 
int
main () 
{
  
int cache1[5], cache2[10], ram[20];
  
srand (time (0));
  
int val, locIndex = -1, mem;
  
 
  do
    {
      
	///Populating  memories
	populate (cache1, sizeof (cache1) / 4);
      
populate (cache2, sizeof (cache2) / 4);
      
populate (ram, sizeof (ram) / 4);
      
 
val = acceptInput ();
      
if (val == -1)
	continue;
      
 
 
	///Locating the input
	if (searchVal (cache1, sizeof (cache1) / 4, val) > -1)
	mem = 1;
      
 
      else if (searchVal (cache2, sizeof (cache2) / 4, val) > -1)
	
	{
	  
locIndex = searchVal (cache2, sizeof (cache2) / 4, val);
	  
updateCache (cache1, cache2, locIndex);
	  
mem = 2;
	
}
      
 
      else if (searchVal (ram, sizeof (ram) / 4, val) > -1)
	
	{
	  
locIndex = searchVal (ram, sizeof (ram) / 4, val);
	  
updateCache (cache1, ram, locIndex);
	  
mem = 3;
	
}
      
 
      else
	{
	  
cache1[0] = val;
	  
mem = 0;
	
}
      
 
informMemory (mem, val, cache1, cache2, ram);
    
 
 
}
  while (repeatProgram ());
  
return 0;

}


void
populate (int arr[], int siz) 
{
  
for (int i = 0; i < siz; i++)
    
    {
      
arr[i] = (rand () % 20) + 1;

} 
 
} 
 
int

searchVal (int arr[], int siz, int val) 
{
  
for (int i = 0; i < siz; i++)
    {
      
if (arr[i] == val)
	{
	  
return i;
	
}
    
}
  
return -1;

}


 
void
updateCache (int arr[], int brr[], int index)
{
  
arr[0] = brr[index];

} 
