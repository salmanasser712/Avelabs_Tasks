--rom_model                        /* LINK USING C CONVENTIONS */
--stack_size=0x8000                /* SOFTWARE STACK SIZE */
--heap_size=0x2000                 /* HEAP AREA SIZE */
--unused_section_elimination=off

/* SPECIFY THE SYSTEM MEMORY MAP */
MEMORY
{
 P_MEM : org = 0x00000000 len = 0x00030000 /* PROGRAM MEMORY (ROM) */
 D_MEM : org = 0x00030000 len = 0x00050000 /* DATA MEMORY (RAM) */
}
/* SPECIFY THE SECTIONS ALLOCATION INTO MEMORY */
SECTIONS
{ 
 .intvecs : {} > 0x0 /* INTERRUPT VECTORS */
 .bss : {} > D_MEM /* GLOBAL & STATIC VARS */
 .sysmem : {} > D_MEM /* DYNAMIC MEMORY ALLOCATION AREA */
 .stack : {} > D_MEM /* SOFTWARE SYSTEM STACK */
 .text : {} > P_MEM /* CODE */
 .cinit : {} > P_MEM /* INITIALIZATION TABLES */
 .const : {} > P_MEM /* CONSTANT DATA */
 .pinit : {} > P_MEM /* TEMPLATE INITIALIZATION TABLES */
}