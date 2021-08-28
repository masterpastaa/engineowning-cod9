#include "EO_Main.h"

EO_ESP ESP;

void EO_ESP::DoESP()
{


	if(!(Entities[cg->clientNum].bAlive & 2))
		return;
	
	for(int i = 0; i < 18; i++)
	{
		if(Entities[i].bEntityType != 1)
			continue;
		
		if(!(Entities[i].bAlive & 2))
			continue;
		if( i == cg->clientNum)
			continue;

		bool enemy = ! ( ( ( clientinfo[i].iTeam == 1 ) || ( clientinfo[i].iTeam == 2 ) ) && ( clientinfo[i].iTeam == clientinfo[cg->clientNum].iTeam ) );

		vec3 HeadPos;
		if(Engine.GetPlayerTag(&Entities[i],*(WORD*)0x24E4212,HeadPos))
		{
			float HeadScreen[2];
			float OrgScreen[2];
			if(Engine.WorldToScreen(HeadPos,&HeadScreen[0],&HeadScreen[1]) && Engine.WorldToScreen(Entities[i].vOrigin,&OrgScreen[0],&OrgScreen[1]))
			{
				float Height = OrgScreen[1] - HeadScreen[1];
				float Width = Height / 2;
				if(enemy)
				{
					Draw.DrawBox(HeadScreen[0] - Width/2,HeadScreen[1],Width,Height,1,RED);
					Draw.DrawString(HeadScreen[0],HeadScreen[1],1,Draw.bigfont,RED,clientinfo[i].szName);
				}
				else
				{
					Draw.DrawBox(HeadScreen[0] - Width/2,HeadScreen[1],Width,Height,1,GREEN);
					Draw.DrawString(HeadScreen[0],HeadScreen[1],1,Draw.bigfont,GREEN,clientinfo[i].szName);
				}
			}
		}
		
	}

}

EO_Aimbot Aimbot;


void EO_Aimbot::DoAimbot()
{
	if(!(Entities[cg->clientNum].bAlive & 2))
		return;
	AimAtPos[0] = 0;
	AimAtPos[1] = 0;
	AimAtPos[2] = 0;

	LastDistance = 999999999.f;
	BestTarget = -1;

	for(int i = 0; i < 18; i++)
	{
		if(Entities[i].bEntityType != 1)
			continue;
		
		if(!(Entities[i].bAlive & 2))
			continue;
		if( i == cg->clientNum)
			continue;

		bool enemy = ! ( ( ( clientinfo[i].iTeam == 1 ) || ( clientinfo[i].iTeam == 2 ) ) && ( clientinfo[i].iTeam == clientinfo[cg->clientNum].iTeam ) );

		if(enemy)
		{
			if(Engine.IsVisible(0,&Entities[i]) != 1)
				continue;
			vec3 HeadPos;
			if(Engine.GetPlayerTag(&Entities[i],*(WORD*)0x24E4214,HeadPos))
			{
				float NewDist = Math.GetDistance(HeadPos,RefDef->vViewOrg);
				if(NewDist < LastDistance)
				{
					LastDistance = NewDist;
					BestTarget = i;
					AimAtPos[0] = HeadPos[0];
					AimAtPos[1] = HeadPos[1];
					AimAtPos[2] = HeadPos[2];
				}

			}
		}

	}
	if(BestTarget != -1)
	{
		//if ! silent aim

		float AimAt[2];
		Math.GetAngleToOrigin(AimAtPos,AimAt[0],AimAt[1]);

		//viewangle += AimAt[0] ...
	}
}