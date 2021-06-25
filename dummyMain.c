#include<stdio.h>
#include<time.h>
#include"F:\Pavan Chavan\swadeshi VIIIT\Programming\Shakti program\functions.h"

main()
{
    int currTime , currCom, currWei, currSTime ,prevCurrTime,prevCurrSTime;
    int curFerStatus = 0, sandFilterStatus=0;
    while (1)
    {
        char x[6], y[7];
        puts("enter x and y");
        gets(x);                //these 4 lines going to replace with ESP8266 code
        gets(y);                // and we directly get x and y string 
        
        //following 4 line convert string in int
        currTime= 1000*(x[0]-'0')+ 100*(x[1]-'0') + 10*(x[2]-'0')+(x[3]-'0');
        currCom=(x[4]-'0');
        currWei=1000* (y[0]-'0')+100 * (y[1]-'0')+10 * (y[2]-'0')+ (y[3]-'0');
        currSTime=10*(y[4]-'0')+(y[5]-'0');

        push(currTime);
        push(currCom);
        push(currWei);
        push(currSTime);
        
        printf("Do u want to continue(y/n):");
        if(getche()!='n')
        break;
    }
    while(1)
    {
        if (!isEmpty());    // get the value from queue if it is not empty
        {
            if(SandFilterStatus==0)
            {
                sandFilterStatus=1;
                currTime=pop();
                currCom=pop();
                currWei=pop();
                currSTime=pop();
            }
        }
        else        //if fertilizer is empty the stop the processe
        {
            printf("No more request left..\n");
            digitalWrite(LOW,outletOfSandFilterMixer);
            digitalWrite(LOW,WatePunp);
            sandFilterStatus=curFerStatus=0;
            break;
        }
        // start making fertilizer mixer before 5 min
        if(currTime-5==systemTime() && currFerStatus==0)
        {
            curFerStatus =1;
            digitalWrite(HIGH,WatePunp);
            makeFertilizerReady(currCom,currWei);
            setFertilizerFlowRate(currSTime);
            //write code to set fertilizer
        }
        // start mixing in outlet at given time
        if(currTime==systemTime())
        {
            //write code for sand filter
            digitalWrite(HIGH,outletOfSandFilterMixer);
            prevCurrSTime=currSTime;
            prevCurrTime=currTime;
            sandFilterStatus=0;
        }
        //stop mixing in outlet when slot time is over
        if(preCurrTime+PrevcurrSTime==systemTime())
        {
            digitalWrite(HIGH,outletOfSandFilterMixer);
            if(systemTime-currTime>6)
            {
            digitalWrite(LOW,WaterPump);
            }
        }//end of if
        if(isPumpOn())
        {
            setReturnValve();
        }//end of if
    }//end of while  
    printf("Proccess is completed...\n");
}//end of main
