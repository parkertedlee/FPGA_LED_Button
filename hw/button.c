#include "button.h"

XGpio GPIO_BTN;

void Button_MakeInst(buttonInst *button, int buttonNum)
{
	button -> prevState = RELEASED;
	button -> buttonNum = buttonNum;
}

void Button_Init()
{
	XGpio_Initialize(&GPIO_BTN, XPAR_AXI_GPIO_1_DEVICE_ID);
	XGpio_SetDataDirection(&GPIO_BTN, CHANNEL_1, 0xff);
}

int Button_GetState(buttonInst *button)
{
	static int prevState =RELEASED;
	int curState = XGpio_DiscreteRead(&GPIO_BTN, CHANNEL_1) & (1<<button->buttonNum);

	if((curState != RELEASED) && (button -> prevState == RELEASED)) {
		usleep(20000);
		button -> prevState = PUSHED;
		return FALSE;
	}

	else if((curState = RELEASED) && (button ->prevState != RELEASED)) {
			usleep(20000);
			button ->prevState = RELEASED;
			return TRUE;
		}
	return FALSE;
}
