#include "out.h"



int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void FUN_00101a00(void)

{
                    // WARNING: Treating indirect jump as call
  (*(code *)(undefined *)0x0)();
  return;
}



void interfaces__c___elabs(void)

{
  interfaces__c___elabs();
  return;
}



void system__finalization_root___elabs(void)

{
  system__finalization_root___elabs();
  return;
}



void __gnat_reraise_library_exception_if_any(void)

{
  __gnat_reraise_library_exception_if_any();
  return;
}



void ada__tags___elabb(void)

{
  ada__tags___elabb();
  return;
}



void __gnat_finalize(void)

{
  __gnat_finalize();
  return;
}



void system__os_lib___elabb(void)

{
  system__os_lib___elabb();
  return;
}



void system__secondary_stack___elabb(void)

{
  system__secondary_stack___elabb();
  return;
}



void system__soft_links___elabb(void)

{
  system__soft_links___elabb();
  return;
}



void ada__calendar___elabs(void)

{
  ada__calendar___elabs();
  return;
}



void ada__text_io___elabs(void)

{
  ada__text_io___elabs();
  return;
}



void system__exceptions___elabs(void)

{
  system__exceptions___elabs();
  return;
}



void system__exception_table___elabb(void)

{
  system__exception_table___elabb();
  return;
}



void system__standard_library__adafinal(void)

{
  system__standard_library__adafinal();
  return;
}



void ada__calendar___elabb(void)

{
  ada__calendar___elabb();
  return;
}



void __gnat_initialize(void)

{
  __gnat_initialize();
  return;
}



void __gnat_runtime_finalize(void)

{
  __gnat_runtime_finalize();
  return;
}



void ada__text_io___elabb(void)

{
  ada__text_io___elabb();
  return;
}



void system__soft_links___elabs(void)

{
  system__soft_links___elabs();
  return;
}



void ada__calendar__delays___elabb(void)

{
  ada__calendar__delays___elabb();
  return;
}



void system__file_io___elabb(void)

{
  system__file_io___elabb();
  return;
}



void ada__text_io__put__4(void)

{
  ada__text_io__put__4();
  return;
}



void ada__text_io__put_line__2(void)

{
  ada__text_io__put_line__2();
  return;
}



void ada__calendar__delays__delay_for(void)

{
  ada__calendar__delays__delay_for();
  return;
}



void system__file_io__finalize_body(void)

{
  system__file_io__finalize_body();
  return;
}



void ada__finalization___elabs(void)

{
  ada__finalization___elabs();
  return;
}



void ada__tags___elabs(void)

{
  ada__tags___elabs();
  return;
}



void ada__io_exceptions___elabs(void)

{
  ada__io_exceptions___elabs();
  return;
}



void ada__text_io__finalize_spec(void)

{
  ada__text_io__finalize_spec();
  return;
}



void ada__streams___elabs(void)

{
  ada__streams___elabs();
  return;
}



void __gnat_runtime_initialize(void)

{
  __gnat_runtime_initialize();
  return;
}



void system__file_control_block___elabs(void)

{
  system__file_control_block___elabs();
  return;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void processEntry entry(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  __libc_start_main(FUN_00101fcc,param_2,&stack0x00000008,FUN_00102a30,FUN_00102aa0,param_1,
                    auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x00101c57)
// WARNING: Removing unreachable block (ram,0x00101c63)

void FUN_00101c40(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00101ca8)
// WARNING: Removing unreachable block (ram,0x00101cb4)

void FUN_00101c80(void)

{
  return;
}



void _FINI_0(void)

{
  if (DAT_003041a2 != '\0') {
    return;
  }
  __cxa_finalize(PTR_LOOP_00304008);
  FUN_00101c40();
  DAT_003041a2 = 1;
  return;
}



void _INIT_0(void)

{
  FUN_00101c80();
  return;
}



void FUN_00101d1a(void)

{
  ada__text_io_E = ada__text_io_E + -1;
  ada__text_io__finalize_spec();
  system__file_io_E = system__file_io_E + -1;
  system__file_io__finalize_body();
  __gnat_reraise_library_exception_if_any();
  return;
}



void FUN_00101d52(void)

{
  if (DAT_00304012 == '\x01') {
    DAT_00304012 = '\0';
    __gnat_runtime_finalize();
    system__standard_library__adafinal();
  }
  return;
}



void FUN_00101d7c(void)

{
  if (DAT_00304012 == '\0') {
    DAT_00304012 = '\x01';
    __gl_main_priority = 0xffffffff;
    __gl_time_slice_val = 0xffffffff;
    __gl_wc_encoding = 0x62;
    __gl_locking_policy = 0x20;
    __gl_queuing_policy = 0x20;
    __gl_task_dispatching_policy = 0x20;
    __gl_priority_specific_dispatching = &DAT_00102c54;
    __gl_num_specific_dispatching = 0;
    __gl_main_cpu = 0xffffffff;
    __gl_interrupt_states = &DAT_00102c55;
    __gl_num_interrupt_states = 0;
    __gl_unreserve_all_interrupts = 0;
    __gl_detect_blocking = 0;
    __gl_default_stack_size = 0xffffffff;
    __gl_leap_seconds_support = 0;
    __gnat_runtime_initialize(1);
    __gnat_finalize_library_objects = FUN_00101d1a;
    system__soft_links___elabs();
    system__exception_table___elabb();
    system__exception_table_E = system__exception_table_E + 1;
    system__exceptions___elabs();
    system__exceptions_E = system__exceptions_E + 1;
    system__soft_links___elabb();
    system__soft_links_E = system__soft_links_E + 1;
    system__secondary_stack___elabb();
    system__secondary_stack_E = system__secondary_stack_E + 1;
    ada__io_exceptions___elabs();
    ada__io_exceptions_E = ada__io_exceptions_E + 1;
    interfaces__c___elabs();
    interfaces__c_E = interfaces__c_E + 1;
    system__os_lib___elabb();
    system__os_lib_E = system__os_lib_E + 1;
    ada__tags___elabs();
    ada__tags___elabb();
    ada__tags_E = ada__tags_E + 1;
    ada__streams___elabs();
    ada__streams_E = ada__streams_E + 1;
    system__file_control_block___elabs();
    system__file_control_block_E = system__file_control_block_E + 1;
    system__finalization_root___elabs();
    system__finalization_root_E = system__finalization_root_E + 1;
    ada__finalization___elabs();
    ada__finalization_E = ada__finalization_E + 1;
    system__file_io___elabb();
    system__file_io_E = system__file_io_E + 1;
    ada__calendar___elabs();
    ada__calendar___elabb();
    ada__calendar_E = ada__calendar_E + 1;
    ada__calendar__delays___elabb();
    ada__calendar__delays_E = ada__calendar__delays_E + 1;
    ada__text_io___elabs();
    ada__text_io___elabb();
    ada__text_io_E = ada__text_io_E + 1;
    DAT_00304014 = DAT_00304014 + 1;
  }
  return;
}



undefined4 FUN_00101fcc(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined local_10 [8];
  
  gnat_envp = param_3;
  gnat_argv = param_2;
  gnat_argc = param_1;
  __gnat_initialize(local_10);
  FUN_00101d7c();
  FUN_0010298a();
  FUN_00101d52();
  __gnat_finalize();
  return gnat_exit_status;
}



void FUN_00102032(void)

{
  ada__text_io__put_line__2(&DAT_00102c58,&DAT_00102c68);
  return;
}



void FUN_00102066(void)

{
  ada__text_io__put_line__2("In \'send_secret_1\'",&DAT_00102c88);
  return;
}



void FUN_0010209a(void)

{
  ada__text_io__put_line__2("In \'send_secret_2\'In \'send_secret_3\'0",&DAT_00102c88);
  return;
}



void FUN_001020ce(void)

{
  ada__text_io__put_line__2("In \'send_secret_3\'0",&DAT_00102c88);
  return;
}



void FUN_00102102(void)

{
  ada__text_io__put__4("0",&DAT_00102cb8);
  return;
}



void FUN_00102136(void)

{
  ada__text_io__put__4(&DAT_00102cc0,&DAT_00102cb8);
  return;
}



void FUN_0010216a(void)

{
  ada__text_io__put__4(&DAT_00102cc1,&DAT_00102cb8);
  return;
}



void FUN_0010219e(void)

{
  ada__text_io__put__4(&DAT_00102cc2,&DAT_00102cb8);
  return;
}



void FUN_001021d2(void)

{
  ada__text_io__put__4(&DAT_00102cc3,&DAT_00102cb8);
  return;
}



void FUN_00102206(void)

{
  ada__text_io__put__4(&DAT_00102cc4,&DAT_00102cb8);
  return;
}



void FUN_0010223a(void)

{
  ada__text_io__put__4(&DAT_00102cc5,&DAT_00102cb8);
  return;
}



void FUN_0010226e(void)

{
  ada__text_io__put__4(&DAT_00102cc6,&DAT_00102cb8);
  return;
}



void FUN_001022a2(void)

{
  ada__text_io__put__4(&DAT_00102cc7,&DAT_00102cb8);
  return;
}



void FUN_001022d6(void)

{
  ada__text_io__put__4(&DAT_00102cc8,&DAT_00102cb8);
  return;
}



void FUN_0010230a(void)

{
  ada__text_io__put__4(&DAT_00102cc9,&DAT_00102cb8);
  return;
}



void FUN_0010233e(void)

{
  ada__text_io__put__4(&DAT_00102cca,&DAT_00102cb8);
  return;
}



void FUN_00102372(void)

{
  ada__text_io__put__4(&DAT_00102ccb,&DAT_00102cb8);
  return;
}



void FUN_001023a6(void)

{
  ada__text_io__put__4(&DAT_00102ccc,&DAT_00102cb8);
  return;
}



void FUN_001023da(void)

{
  ada__text_io__put__4(&DAT_00102ccd,&DAT_00102cb8);
  return;
}



void FUN_0010240e(void)

{
  ada__text_io__put__4(&DAT_00102cce,&DAT_00102cb8);
  return;
}



void FUN_00102442(void)

{
  ada__text_io__put__4(&DAT_00102ccf,&DAT_00102cb8);
  return;
}



void FUN_00102476(void)

{
  ada__text_io__put__4(&DAT_00102cd0,&DAT_00102cb8);
  return;
}



void FUN_001024aa(void)

{
  ada__text_io__put__4(&DAT_00102cd1,&DAT_00102cb8);
  return;
}



void FUN_001024de(void)

{
  ada__text_io__put__4(&DAT_00102cd2,&DAT_00102cb8);
  return;
}



void FUN_00102512(void)

{
  ada__text_io__put__4(&DAT_00102cd3,&DAT_00102cb8);
  return;
}



void FUN_00102546(void)

{
  ada__text_io__put__4(&DAT_00102cd4,&DAT_00102cb8);
  return;
}



void FUN_0010257a(void)

{
  ada__text_io__put__4(&DAT_00102cd5,&DAT_00102cb8);
  return;
}



void FUN_001025ae(void)

{
  ada__text_io__put__4(&DAT_00102cd6,&DAT_00102cb8);
  return;
}



void FUN_001025e2(void)

{
  ada__text_io__put__4(&DAT_00102cd7,&DAT_00102cb8);
  return;
}



void FUN_00102616(void)

{
  ada__text_io__put__4(&DAT_00102cd8,&DAT_00102cb8);
  return;
}



void FUN_0010264a(void)

{
  ada__text_io__put__4(&DAT_00102cd9,&DAT_00102cb8);
  return;
}



void FUN_0010267e(void)

{
  ada__text_io__put__4(&DAT_00102cda,&DAT_00102cb8);
  return;
}



void FUN_001026b2(void)

{
  ada__text_io__put__4(&DAT_00102cdb,&DAT_00102cb8);
  return;
}



void FUN_001026e6(void)

{
  ada__text_io__put__4(&DAT_00102cdc,&DAT_00102cb8);
  return;
}



void FUN_0010271a(void)

{
  ada__text_io__put__4(&DAT_00102cdd,&DAT_00102cb8);
  return;
}



void FUN_0010274e(void)

{
  ada__text_io__put__4(&DAT_00102cde,&DAT_00102cb8);
  return;
}



void FUN_00102782(void)

{
  ada__text_io__put__4(&DAT_00102cdf,&DAT_00102cb8);
  return;
}



void FUN_001027b6(void)

{
  ada__text_io__put__4(&DAT_00102ce0,&DAT_00102cb8);
  return;
}



void FUN_001027ea(void)

{
  ada__text_io__put__4(&DAT_00102ce1,&DAT_00102cb8);
  return;
}



void FUN_0010281e(void)

{
  ada__text_io__put__4(&DAT_00102ce2,&DAT_00102cb8);
  return;
}



void FUN_00102852(void)

{
  ada__text_io__put__4(&DAT_00102ce3,&DAT_00102cb8);
  return;
}



void FUN_00102886(void)

{
  ada__text_io__put__4(&DAT_00102ce4,&DAT_00102cb8);
  return;
}



void FUN_001028ba(void)

{
  ada__text_io__put__4(&DAT_00102ce5,&DAT_00102cb8);
  return;
}



void FUN_001028ee(void)

{
  ada__text_io__put__4(&DAT_00102ce6,&DAT_00102cb8);
  return;
}



void FUN_00102922(void)

{
  ada__text_io__put__4(&DAT_00102ce7,&DAT_00102cb8);
  return;
}



void FUN_00102956(void)

{
  ada__text_io__put__4(&DAT_00102ce8,&DAT_00102cb8);
  return;
}



void FUN_0010298a(void)

{
  ada__calendar__delays__delay_for(1000000000000000);
  FUN_00102616();
  FUN_001024aa();
  FUN_00102372();
  FUN_001025e2();
  FUN_00102852();
  FUN_00102886();
  FUN_001028ba();
  FUN_00102922();
  FUN_001023a6();
  FUN_00102136();
  FUN_00102206();
  FUN_0010230a();
  FUN_00102206();
  FUN_0010257a();
  FUN_001028ee();
  FUN_0010240e();
  FUN_001026e6();
  FUN_00102782();
  FUN_001028ee();
  FUN_0010230a();
  FUN_001022a2();
  FUN_0010216a();
  FUN_0010223a();
  FUN_00102206();
  FUN_00102102();
  FUN_0010230a();
  FUN_00102956();
  return;
}



void FUN_00102a30(EVP_PKEY_CTX *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  _init(param_1);
  lVar1 = 0;
  do {
    (*(code *)(&__DT_INIT_ARRAY)[lVar1])((ulong)param_1 & 0xffffffff,param_2,param_3);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}



void FUN_00102aa0(void)

{
  return;
}



void _fini(void)

{
  return;
}




