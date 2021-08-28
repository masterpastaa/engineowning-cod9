#include "EO_Main.h"

usercmd_t* GetUsercmd(int num)
{
	return (usercmd_t*)((*(DWORD*)0x11C7D84) + 60 * (num & 0x7F) + 273576);
}


int vPPS;

int vDFPS;

bool Once = false;
void CG_DrawFPS()
{
	if(!Once)
	{
		Draw.Init();
		Engine.Init();
		Once = true;
	}
	Draw.DrawString(20,20,1,Draw.consolefont,WHITE,"EngineOwning - CoD9");
	ESP.DoESP();
	Aimbot.DoAimbot();


	//char Buffer[100];
	//sprintf(Buffer,"%lx",(DWORD)RefDefViewAngles);
	//Draw.DrawString(500,500,1,Draw.normalfont,RED,Buffer);
	


	if(GetAsyncKeyState(VK_F1) & 1)
	{
		char Buffer[100];
		sprintf(Buffer,"cmd mr %d 9 axis",*(int*)0x11D0ADC);
		Engine.SendCmd(0,Buffer);
	}

}




void CG_PredictedPlayerState()
{
	if(!(Entities[cg->clientNum].bAlive & 2))
		return;
	if(Aimbot.BestTarget == -1)
		return;

	int CmdNum = *(int*)((*(DWORD*)0x11C7D84) + 281256);

	usercmd_t* OldCmd = GetUsercmd(CmdNum - 1);
	usercmd_t* CurCmd = GetUsercmd(CmdNum);

	int OldTime = OldCmd->serverTime;

	memcpy(OldCmd,CurCmd,sizeof(usercmd_t));

	OldCmd->serverTime = OldTime + 1;
	//OldCmd->buttons |= IN_ATTACK; //autoshoot

	float AimAt[2];
	Math.GetAngleToOrigin(Aimbot.AimAtPos,AimAt[0],AimAt[1]);

	OldCmd->viewangles[0] += ANGLE2SHORT(AimAt[1]);
	OldCmd->viewangles[1] += ANGLE2SHORT(AimAt[0]);
}

