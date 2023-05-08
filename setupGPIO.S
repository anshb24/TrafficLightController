.section .text
.align 2
.globl setupGPIO
#include "memoryMap.inc"
#include "GPIO.inc"

setupGPIO:
addi sp, sp, -16
# allocate a stack frame, moves the stack up by 16 bits
sw ra, 12(sp)
li t0, GPIO_CTRL_ADDR # load GPIO base address
# INPUT PINS 
li t1, input_button # load address of input pins into t1
sw t1, GPIO_INPUT_EN(t0) # set input pins for input enable
sw t1, GPIO_INPUT_PULUP(t0) # enable pull up

# OUTPUT PINS
li t1, OUTPUT_PINS # get OUTPUT pins offset
sw t1, GPIO_OUTPUT_EN(t0) # write the output pins to GPIO Enable offset


; sw t1, GPIO_OUTPUT_VAL(t0) 
; sw x0, GPIO_OUTPUT_VAL(t0)

lw ra, 12(sp)
addi sp, sp, 16
ret