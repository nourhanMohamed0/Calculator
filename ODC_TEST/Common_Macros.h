/*
 * Common_Macros.h
 *
 * Created: 8/10/2024 8:09:52 PM
 *  Author: Nourhan Mohamed Hassan
 */


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* Macro: SET_BIT
 * This macro sets a specific bit in a register.
 * It achieves this by performing a bitwise OR operation between the register (REG) and 1 shifted left by the bit position (BIT).
 */
#define SET_BIT(REG,BIT)  REG|=(1<<BIT)
/* Macro: CLR_BIT
 * This macro resets a specific bit in a register.
 * Clearing a bit is often used to deactivate or disable a specific function or feature in hardware programming.
 */
#define CLR_BIT(REG,BIT)  REG&=(~(1<<BIT))

/* Macro: READ_BIT
 * This macro retrieves the state (0 or 1) of a specific bit in a register.
 * It isolates the desired bit by AND-ing the register (REG) shifted right by BIT, then ANDing with 0x01.
 * This moves the desired bit to the least significant bit position for easy evaluation.
 */

#define READ_BIT(REG,BIT) ((REG>>BIT)&(1))

/* Macro: READ_REG
 * This macro retrieves the value of a specific register.
 * It return the given register .
 */
#define READ_REG(REG)     (REG)
/* Macro: TOGGLE_BIT
 * This macro toggles (flips) a specific bit in a register.
 * It uses XOR operation on the register (REG) with 1 shifted left by the bit position (BIT).
 * Toggling is useful for switching the state of a bit between 0 and 1 repeatedly.
 */

#define TOGGLE_BIT(REG,BIT) ((REG)^=(1<<(BIT)))

#endif /* COMMON_MACROS_H_ */
