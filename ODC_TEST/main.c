// 1M Hz -> 1million instruction per second
#include "HAL/H_LCD_Driver/H_LCD.h"
#include "HAL/H_KeyPad_Driver/H_KeyPad.h"
void delay() {
	//for loop consists of 5 instruction assembly
	//5 *65535 /1000000 -> 1/3 second
	for (u16 i = 0; i < 65535; i++)
		;
}
int main() {
	u8 op1, op2, operator, op2_flag = 0, result = 0;
	H_LCD_Init();
	H_keyPad_Init();
	volatile u8 value = NOT_PRESSED;
	while (1) {
		H_GetKeyPadPressed(&value);
		if (value != NOT_PRESSED) {
			if (result == 1) {
				result = 0;
				H_LCD_sendCommand(CLEAR_DISPLAY);
			}
			H_LCD_sendData(value); //2 + 5  =
			if (value == 'A') {
				H_LCD_sendCommand(CLEAR_DISPLAY);
				op2_flag = 0;
			} else if ((value >= '0') && (value <= '9')) //2 5
					{
				if (op2_flag == 0) { //operand 1 is not assigned ->0
					op1 = value - '0'; //op1=2
					op2_flag = 1; //1
				} else if (op2_flag == 1) {
					op2 = value - '0'; //5
					op2_flag = 0; //0
				}
			} else if (value == '=') {
				switch (operator) { //H_sendNumber
				case '+':
					H_sendNumber((op1 + op2));
					result = 1;
					break;
				case '-':
					if((op1 - op2)<0)
					H_LCD_sendData('-');
					H_sendNumber((op2 - op1));
					result = 1;
					break;
				case '*':
					H_sendNumber((op1 * op2));
					result = 1;
					break;
				case '/':
					if((operator=='/')&&(op2==0))
						H_LCD_sendString("Not Allowed");
					else
					H_sendNumber((op1 / op2));
					result = 1;
					break;
				default:
					break;
				}
			}

			else {
				operator = value; //'+'
			}
		}

		_delay_ms(160);

	}

	return 0;
}

