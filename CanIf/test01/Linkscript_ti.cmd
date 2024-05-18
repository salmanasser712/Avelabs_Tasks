/*****************************************************************************/
/*** Specify Link Options ***/
/*****************************************************************************/
-c                                  /* LINK USING C CONVENTIONS      */
-stack  0x8000                             /* SOFTWARE STACK SIZE           */
-heap   0x2000                             /* HEAP AREA SIZE                */
--args  0x1000
--unused_section_elimination=off           /*to stop optimizing the linking process*/
--map_file=CanIf.map /* Create an output map file */
/*****************************************************************************/
/*** Specify the Input Files ***/
/*****************************************************************************/
CanIf.o
main.o
stubs.o
/*startup_stm32f10x.o*/  /*if using startup code*/
/*****************************************************************************/
/*** Specify the Memory Configurations ***/
/*****************************************************************************/
MEMORY
{
    P_MEM : org = 0x00000020 len = 0x00040000 /* DATA MEMORY (ROM) */
    D_MEM : org = 0x20000020 len = 0x00010000 /* PROGRAM MEMORY (RAM) */
   
}
/*****************************************************************************/
/* Specify the Output Sections */
/*****************************************************************************/
SECTIONS
{
 .intvecs    : {} > 0x0             /* INTERRUPT VECTORS                 */
    .bss        : {} > D_MEM           /* GLOBAL & STATIC VARS              */
    .data       : {} > D_MEM
    .sysmem     : {} > D_MEM           /* DYNAMIC MEMORY ALLOCATION AREA    */
    .stack      : {} > D_MEM           /* SOFTWARE SYSTEM STACK             */

    .text       : {} > P_MEM           /* CODE                              */
    .cinit      : {} > P_MEM           /* INITIALIZATION TABLES             */
    .const      : {} > P_MEM           /* CONSTANT DATA                     */
    .rodata     : {} > P_MEM
    .ARM.exidx  : {} > P_MEM
    .init_array : {} > P_MEM           /* C++ CONSTRUCTOR TABLES */
}
/*****************************************************************************/
/*** End of Command File ***/
/*****************************************************************************/