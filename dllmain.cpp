// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "EO_Main.h"





LONG CALLBACK pVEH_Hook( PEXCEPTION_POINTERS pInfo )
{
	if( pInfo->ContextRecord->Eip == 0x0047046B )
	{
		if(pInfo->ContextRecord->Eax == 1)
		{
			CG_PredictedPlayerState();
			pInfo->ContextRecord->Eax = vPPS;
		}


		return EXCEPTION_CONTINUE_EXECUTION;
	}
	if(pInfo->ContextRecord->Eip == 0x0058A489)
	{
		CG_DrawFPS();
		pInfo->ContextRecord->Eax = vDFPS;

		return EXCEPTION_CONTINUE_EXECUTION;
	}

	return EXCEPTION_CONTINUE_SEARCH;
}


void HookThread()
{
	vPPS = *(int*)0x1140A24;
	vDFPS = *(int*)0x10AA228;

	Sleep(2000);

	AddVectoredExceptionHandler( TRUE,pVEH_Hook );

	while(true)
	{
		*(int*)0x1140A24 = 1;
		*(int*)0x10AA228 = 1;
		Sleep(2000);
	}
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0,0,(LPTHREAD_START_ROUTINE)HookThread,0,0,0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

