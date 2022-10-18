/*
 * button.h
 *
 *  Created on: 2022. 10. 18.
 *      Author: kccistc
 */

#ifndef SRC_HW_BUTTON_H_
#define SRC_HW_BUTTON_H_


#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"



#define FALSE		0
#define TRUE		1

#define RELEASED	0
#define PUSHED		1

#define BUTTON_0	0
#define BUTTON_1	1
#define BUTTON_2	2
#define BUTTON_3	3

#define CHANNEL_1 	1
#define OUTPUT 		0x00
#define INPUT 		0x0f

typedef struct _buttonInst {
	int prevState;
	int buttomNum;
}buttonInst;



int Button_GetState(buttonInst *button);
void Button_MakeInst(buttonInst *button, int buttonNum);
void Button_Init();


#endif /* SRC_HW_BUTTON_H_ */
