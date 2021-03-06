#include<stdio.h>
#include "platform.h"
#include "gpio.h"
#include "utils.h"

#define HIGH 1
#define LOW 0
#define HIGH_outletOfFertilizerMixer
#define LOW_outletOfFertilizerMixer 
#define LOW_WaterPump 0x00000000
#define HIGH_WaterPump 0xFFFFFFFE
#define inletFlowSensor 0x41200//need to sent which pin is connected to which device
#define outletFlowSensor 0x41204
#define com1FlowSensor
#define HIGH_inletOfFertilizerMixer
#define LOW_inletOfFertilizerMixer
#define ON_MixerMotor 
#define OFF_MixerMotorOff
#define HIGH_inletSVOfMixer
#define LOW_ inletSVOfMixer
#define HIGH_Comp1SV
#define LOW_Comp1SV



struct Node *front=NULL,*rear=NULL;

struct Node
{
    int data;
    int* next;
};

void push(int s)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->next=NULL;
    if(front==NULL)
    {
        temp->data=s;
        front=rear=temp;
    }
    else
    {
        temp->data=s;
        rear->next=temp;
        rear=rear->next;
    }
}
int pop()
{
    struct Node *temp=front;
    front=front->next;
    return temp->data;
}
int isPumpOn()
{
    if((GPIO_DATA_REG & 0x00000001)==0x00000001)
    {
      return  1;
    }
    else 
    {
        return 0;
    }
    //return 1 is pump is on
    // return 0 if pump is off
}
int isEmpty()
{
    if(front==rear)
    {
      return 1;
    }
    else
    {
      return 0;
    }
    //return 1 is queue is empty
    //return 0 if queue is not empty
}
void setup()
{
    // this will set the system at ideal state
}
int systemTime()
{
    /*
    write code to return current time of system
    return time in interger varible
    if time is 10:20AM u have to return 1020
    ser varible name as per coding standard  */
}
void digitalWrite(int STATUS,int PinNo)
{
    if(STATUS==1)
     write_word(GPIO_DATA_REG, PinNo | GPIO_DATA_REG);
     else
     write_word(GPIO_DATA_REG, PinNo & GPIO_DATA_REG);
    /* write a code to turn on or turn off the pin
    first parameter is HIGH/LOW which indicate 1/0
    second parameter indicates pin no.
    STATUS is eigher HIGH or LOW
    PINNO is pin no where relay or SV is connected  */
}

int anologRead(int PINNO)
{
    /* Read the value of anolog sensor which is connected at pin given in parameter
    ser varible name as per coding standard  
    PINNO is pin no where relay or SV is connected  */
}
void setReturnValve()
{
    // this function will set the value of return value 
    // for that get the value of inletPressureSensor and outletPressureSensor
    // and accordingly set the value for return value 
    // we need to discuss on this for pressure values
}
void makeFertilizerReady(currCom,currWei)
{
    // this function will make fertilizer mixer ready with given ferilizer 
    // weight in currWei from compartment given in currCom
    // follow aprorite proccess
}
void setFertilizerFlowRate(currSTime)
{
    // this function will set the flow rate of fertilizer in oulet
    // write the code to set value of stepper motor value which connected at
    // ouletOfMixer
}


