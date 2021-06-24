#include<stdio.h>
#include<time.h>
#include"F:\Pavan Chavan\swadeshi VIIIT\Programming\Shakti program\functions.h"

main()
{
    int currTime , currCom, currWei, currSTime ,prevCurrTime,prevCurrSTime;
    int curFerStatus = 0, sandFilterStatus=0;
    while (1)
    {
        printf("Enter Time:");
        scanf("%d\n",&currTime);
        printf("Enter Compartment No:");
        scanf("%d\n",&currCom);
        printf("Enter Weight of fertilizer:");
        scanf("%d\n",&currWei);
        printf("Enter slot Time:");
        scanf("%d\n",&CurrSTime);
        //push on queue
        printf("Do u want to continue(y/n):");
        if(getche()!='n')
        break;
    }
    if (!isEmpty());
    {
        if(SandFilterStatus==1)
        {
            sandFilterStatus=0;
            
          //pop the element and store in currTime,currCom,currWei,currSTime

        }
        if(currTime-5==systemTime() && currFerStatus==0)
        {
            curFerStatus =1;
            digitalWrite(HIGH,WatePunp);
            setReturnValve();
            makeFertilizerReady(currCom,currWei);
            setFertilizerFlowRate(currSTime);
            //write code to set fertilizer

        }
        if(currTime==systemTime())
        {
            //write code for sand filter
            digitalWrite(HIGH,outletOfSandFilterMixer);
            prevCurrSTime=currSTime;
            prevCurrTime=currTime;
            curFerStatus=1;
        }
        if(preCurrTime+PrevcurrSTime==systemTime())
        {
            digitalWrite(HIGH,outletOfSandFilterMixer);
            //write code to turn off the outlet of fertilizer mixer
        }

    }
    else
    {
        printf("No more request left..\n");
        digitalWrite(LOW,outletOfSandFilterMixer);
        digitalWrite(LOW,WatePunp);
    }
    
    
    
    
}