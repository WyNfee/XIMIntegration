
//**********************************************************************`
//* This is an include file generated by EtwPlusTool.                  *`
//*                                                                    *`
//* Copyright (c) Microsoft Corporation. All Rights Reserved.          *`
//**********************************************************************`
#pragma once
#pragma pack(push, 16)

#include "EtwPlus.h"

#if defined(__cplusplus)
extern "C" {
#endif

// Field Descriptors, used in the ETX_EVENT_DESCRIPTOR array below
//
EXTERN_C __declspec(selectany) ETX_FIELD_DESCRIPTOR XDKSampleFramework_FrameworkLoaded_Fields[2] = {{EtxFieldType_UnicodeString,0},{EtxFieldType_UnicodeString,0}};

// Event name mapping
//
#define FrameworkLoaded_value 1

// Event Descriptor array
//
EXTERN_C __declspec(selectany) ETX_EVENT_DESCRIPTOR XDKSampleFrameworkEvents[1] =  {
    {{ 1, 1, 0, 0, 0, 0, 0x0 }, "FrameworkLoaded", "0.7.0.1", XDKSampleFramework_FrameworkLoaded_Fields, 2, 0, EtxEventEnabledState_Undefined, EtxEventEnabledState_ProviderDefault, EtxPopulationSample_Undefined, 100, EtxEventLatency_Undefined, EtxEventLatency_ProviderDefault, EtxEventPriority_Undefined, EtxEventPriority_ProviderDefault }};

// Provider Descriptor for XDKSampleFramework
//
EXTERN_C __declspec(selectany) ETX_PROVIDER_DESCRIPTOR XDKSampleFrameworkProvider = {"XDKSampleFramework", {0xf3c9ec3f,0xf75c,0x4532,{0xa8,0x07,0x04,0xf3,0x0c,0x59,0x7a,0xa0}}, 1, (ETX_EVENT_DESCRIPTOR*)&XDKSampleFrameworkEvents, 0, EtxProviderEnabledState_Undefined, EtxProviderEnabledState_OnByDefault, 0, 100, EtxProviderLatency_Undefined, EtxProviderLatency_Normal, EtxProviderPriority_Undefined, EtxProviderPriority_Normal};

// ETW handle for XDKSampleFramework
//
EXTERN_C __declspec(selectany) REGHANDLE XDKSampleFrameworkHandle = (REGHANDLE)0;

/*++

Routine Description:

    Register the provider with ETW+.

Arguments:
    
    None

Remarks:

    ERROR_SUCCESS if success or if the provider was already registered. 
    Otherwise, an error code.

--*/
#define EventRegisterXDKSampleFramework() EtxRegister(&XDKSampleFrameworkProvider, &XDKSampleFrameworkHandle)

/*++

Routine Description:

    Unregister the provider from ETW+.

Arguments:
            None
Remarks:
    ERROR_SUCCESS if success or if the provider was not registered. 
    Otherwise, an error code.
--*/
#define EventUnregisterXDKSampleFramework() EtxUnregister(&XDKSampleFrameworkProvider, &XDKSampleFrameworkHandle)

#define EventEnabledFrameworkLoaded() (TRUE)

// Entry point to log the event FrameworkLoaded
//
__inline
ULONG
EventWriteFrameworkLoaded(__in_opt PCWSTR ExeName)
{
#define ARGUMENT_COUNT_XDKSampleFramework_FrameworkLoaded 2

    EVENT_DATA_DESCRIPTOR EventData[ARGUMENT_COUNT_XDKSampleFramework_FrameworkLoaded];
    UINT8 scratch[64];

    EtxFillCommonFields_v7(&EventData[0], scratch, 64);

    EventDataDescCreate(&EventData[1], (ExeName != NULL) ? ExeName : L"", (ExeName != NULL) ? (ULONG)((wcslen(ExeName) + 1) * sizeof(WCHAR)) : (ULONG)sizeof(L""));

    return EtxEventWrite(&XDKSampleFrameworkEvents[0], &XDKSampleFrameworkProvider, XDKSampleFrameworkHandle, ARGUMENT_COUNT_XDKSampleFramework_FrameworkLoaded, EventData);
}
#if defined(__cplusplus)
};
#endif

#pragma pack(pop)
