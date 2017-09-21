//
//  teller.h
//  Lab5 - Queue
//



#ifndef _Teller
#define _Teller
#include "queuea.h"
#include "customer.h"


// - - I - -  T e l l e r  C l a s s --------------------------------------------



//(1) Class definition
class teller
{
    
    //DATA MEMBERS
private:
    
    int upTime;
    int downTime;
    
    
    
    
    
    //__PROCEDURE HEADERS__
public:
    
    
    //Default Constructor
    teller()
    {
        upTime = 0;
        downTime = 0;
    }
    
    
    //bankProcedures: different service options from teller to customer
    void bankProcedures(int proc);
    bool busy();
    void inService();
    //CustService proc
    void custService(int time, int& total, Queue<customer>& line, int i );
    
    
    
    
    
    
    
    
    
    
    
    
    
};





//(2) Procedure Definitions-----------------------------------------------

void teller::inService()
{
    if(upTime > 0)
        --upTime;
    else
        downTime++;
    
}





bool teller::busy()
{
    if(upTime == 0)
        return 0;
    else
        return 1;
}




void teller::bankProcedures(int proc)
{
    
    
    if(proc == 1)
    {
        upTime = 5;
    }
    else if(proc == 2)
    {
        upTime = 10;
    }
    else
    {
        upTime = 15;
    }
    
    
}

/*
void teller::custService(int time, int& total, Queue<customer>& line, int i )

{
    cout << "Time: " << time << endl;
    
    cout << "Customer Number: " << line.Front().customerNumber << " approaches teller number: " << i << endl;
    
    int token = rand() % 3 + 1;
    
    bankProcedures(token);
    
    
    total += time - line.Front().timing;
    
    
    cout << "Customer waited: " << time - line.Front().timing << endl;
    
    
    line.dequeue(); // Customer exits bank
    
    
    
    
}


*/

void teller::custService(int time, int& total, Queue<customer>& line, int i)
{
    cout << "Time is: " << time << ":00 " <<  endl;
    
    cout << "Customer Number is: " << line.Front().customerNumber << " approaches teler number: " << i <<  endl;
   
    int service = rand() % 3 + 1;
    
    bankProcedures(service);
    total += time - line.Front().timing;
    cout << "Customer waited: " << time - line.Front().timing << endl;
    
    line.dequeue();
    
}







#endif /* teller_h */
