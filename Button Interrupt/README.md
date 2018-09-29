# Button Interrupt
In this part of the lab, a button is implemented to switch an LED on and off. It is used in this case rather than by polling the status of the LEDs because it is more efficient with power. The following code designates an interrupt on Port 1. 
```c
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
}
```

When the interrupt is triggered, the code inside the interrupt function will run.
