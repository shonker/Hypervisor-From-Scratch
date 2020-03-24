#pragma once
#include <ntddk.h>
#include  "Vmx.h"
#include  "Logging.h"
#include  "PoolManager.h"

/* Here we put global variables that are used more or less in all part of our hypervisor (not all of them) */

//////////////////////////////////////////////////
//				Global Variables				//
//////////////////////////////////////////////////


// Save the state and variables related to each to logical core
VIRTUAL_MACHINE_STATE* GuestState;

// Save the state and variables related to EPT
EPT_STATE* EptState;

// Because we may be executing in an arbitrary user-mode 
// process as part of the DPC interrupt we execute in
// We have to save Cr3, for HOST_CR3
UINT64 InitiateCr3;

// Save the state of the thread that waits for messages to deliver to user-mode
NOTIFY_RECORD* GlobalNotifyRecord;

// Support for execute-only pages (indicating that data accesses are not allowed while instruction fetches are allowed).
BOOLEAN ExecuteOnlySupport;

// Client Allowed to send IOCTL to the drive
BOOLEAN AllowIOCTLFromUsermode;
