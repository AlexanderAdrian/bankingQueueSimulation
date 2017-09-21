
#include<iostream>
#include<cstdlib>
#include "queuea.h"
#include "customer.h"
#include "teller.h"
#include <ctime>
using namespace std;






//Bank Process Function
void process(Queue<customer>& line, int time, int& lineTime, int tellerCount, teller tellerArray[] );




//--Begin Main()--
int main()
{
    
    //(I) - - V a r i a b l e s - - ---------------------------------------------------
    
    //Object and header based variables
   
    srand(time(0));
    customer customer1; //customer header type declaration
    Queue<customer> line;  //queue
    const int tellerCount = 2;  //teller number variable
    teller tellerArray[tellerCount];
    
    //Time and count based variables
    int time;
    int totalCustomers;
    int lineTime;
    
    
    
    
    
    
    
    
    
    
    //(II) - - B a n k  S c e n a r i o s  &  Q u e u e  I m p l e m e n t a t i o n -
    
    //Bank Service Runtime Loop (1 - 100) clock
    for(time = 0; time <= 100; time++)
    {
        
        
        
        
        
        //Customer Arrival Scenario
        if( (float( rand() )  / float(RAND_MAX)  )   <=   0.2  &&       (float( rand() )   /  float(RAND_MAX)   >=  0.0  )  )
        {
            cout << "Time Start: " << time << ":00" << "__Bank Proc Below__" << endl;
            
            totalCustomers++;   //increment customer time
            customer1.timing = time;   //set customer1.timing to time value
            line.enqueue(customer1);
            cout << "Customer: " << customer1.customerNumber << "is now added." << endl;
            cout << endl;
        }

            
        
        //In Line Customer Scenario
        if(!line.IsEmpty())
        {
            process(line, time, lineTime, tellerCount, tellerArray);
        }
        
    }
    
    
    
    
    
    
    
    
    //(III) - - F i n a l  T o t a l  S u m m a r y  O u t p u t
    cout << "- - - - - End Simulation, bank is now closed - - - - - " << endl;
    cout << "- - - - - - - - -  Averages and Totals - - - - - - - - " << endl;
    
    cout << "Average customer wait time is: " << lineTime / totalCustomers << " minutes" << endl;
    
}










//(IV) - - - B a n k  P r o c e d u r e  F u n c t i o n - - -
// EDITED FROM ORIGINAL VERSION, redef from group



void process(Queue<customer>& line, int time, int& lineTime, int tellerCount, teller tellerArray[])
{
    for(int i = 0; i < tellerCount; i++)
    {
        if(!tellerArray[i].busy() && !line.IsEmpty() )
        {
            tellerArray[i].custService( time, lineTime, line,  i+1    );
        }
    
        tellerArray[i].inService();
    }
}





/*
 
 
 
 Time Start: 4:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 4:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 0
 Time Start: 5:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 5:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 0
 Time Start: 11:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time Start: 13:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 14:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 3
 Time is: 15:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 2
 Time Start: 20:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time Start: 23:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 28:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 8
 Time Start: 33:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 34:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 11
 Time is: 39:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 6
 Time Start: 52:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time Start: 55:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 55:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 3
 Time Start: 56:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 56:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 1
 Time Start: 57:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 61:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 5
 Time Start: 66:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 66:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 9
 Time Start: 68:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time Start: 69:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 70:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 4
 Time is: 71:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 3
 Time Start: 76:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 76:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 7
 Time is: 80:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 4
 Time Start: 82:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time Start: 85:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 86:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 4
 Time is: 91:00
 Customer Number is: 1 approaches teler number: 1
 Customer waited: 6
 Time Start: 95:00__Bank Proc Below__
 Customer: 1is now added.
 
 Time is: 95:00
 Customer Number is: 1 approaches teler number: 2
 Customer waited: 0
 - - - - - End Simulation, bank is now closed - - - - -
 - - - - - - - - -  Averages and Totals - - - - - - - -
 Average customer wait time is: 4 minutes
 Program ended with exit code: 0
 
 */













