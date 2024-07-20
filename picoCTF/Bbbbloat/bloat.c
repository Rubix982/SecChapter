#include "out.h"



void _DT_INIT(void)

{
  __gmon_start__();
  return;
}



void FUN_00101020(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



void FUN_001010c0(void)

{
  __cxa_finalize();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void free(void *__ptr)

{
  free(__ptr);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = putchar(__c);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fputs(char *__s,FILE *__stream)

{
  int iVar1;
  
  iVar1 = fputs(__s,__stream);
  return iVar1;
}



void __isoc99_scanf(void)

{
  __isoc99_scanf();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * strdup(char *__s)

{
  char *pcVar1;
  
  pcVar1 = strdup(__s);
  return pcVar1;
}



void processEntry entry(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  __libc_start_main(FUN_00101307,param_2,&stack0x00000008,FUN_001015b0,FUN_00101620,param_1,
                    auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x001011a3)
// WARNING: Removing unreachable block (ram,0x001011af)

void FUN_00101190(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x001011e4)
// WARNING: Removing unreachable block (ram,0x001011f0)

void FUN_001011c0(void)

{
  return;
}



void _FINI_0(void) {
  if (DAT_00104018 != '\0') {
    return;
  }
  FUN_001010c0(PTR_LOOP_00104008);
  FUN_00101190();
  DAT_00104018 = 1;
  return;
}



void _INIT_0(void) {
  FUN_001011c0();
  return;
}

char * FUN_00101249(char *param_2) {
  char cVar1;
  char *__s;
  size_t sVar2;
  ulong local_20;
  
  __s = strdup(param_2);
  sVar2 = strlen(__s);
  for (local_20 = 0; local_20 < sVar2; local_20 = local_20 + 1) {
    if ((' ' < __s[local_20]) && (__s[local_20] != '\x7f')) {
      cVar1 = (char)(__s[local_20] + 0x2f);
      if (__s[local_20] + 0x2f < 0x7f) {
        __s[local_20] = cVar1;
      }
      else {
        __s[local_20] = cVar1 + -0x5e;
      }
    }
  }
  return __s;
}

undefined8 FUN_00101307(void) {
  long in_FS_OFFSET;
  int local_48;
  char *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = 0x4c75257240343a41;
  local_30 = 0x3062396630664634;
  local_28 = 0x68653066635f3d33;
  local_20 = 0x4e623665625f64;
  printf("What\'s my favorite number? ");
  __isoc99_scanf(&DAT_00102020,&local_48);
  if (local_48 == 0x86187) {
    local_40 = (char *)FUN_00101249(&local_38);
    fputs(local_40,stdout);
    putchar(10);
    free(local_40);
  }
  else {
    puts("Sorry, that\'s not it!");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return 0;
}



void FUN_001015b0(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  _DT_INIT();
  lVar1 = 0;
  do {
    (*(code *)(&__DT_INIT_ARRAY)[lVar1])(param_1,param_2,param_3);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}



void FUN_00101620(void)

{
  return;
}



void _DT_FINI(void) {
  return;
}
