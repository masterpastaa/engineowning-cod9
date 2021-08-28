#include "EO_Main.h"

centity* Entities;
CLient_t* clientinfo;
cg_t* cg;
//cgs_t* cgs;
refdef_t* RefDef;

float* RefDefViewAngles;

EO_Engine Engine;

void EO_Engine::Init()
{
	IsVisible = (IsVisible_597DD0)0x597DD0;
	SendCmd = (AddCmdBuff_646BC0)0x646BC0;

	Entities = (centity*)*(DWORD*)0x1140888;
	clientinfo = (CLient_t*)0x234A488; //ok
	cg = (cg_t*)0x21EE440; // is ok
	//cgs = (cgs_t*)0x
	RefDef = (refdef_t*)((*(DWORD*)0x113F19C) + 0x4D890);

	RefDefViewAngles = (float*)((*(DWORD*)0x113F19C) + 0x482A0);
}
bool EO_Engine::GetPlayerTag( centity* pEnt, WORD SzBone, PFLOAT vOut ) {
	PVOID DObj = Com_GetClientDObj( pEnt->iClientNum , pEnt->iUsedForPlayerMesh_0  );   
                                                                           
    if( !DObj )
    {
        return FALSE;
    }

	return CG_DObjGetWorldTagPos( pEnt, DObj, SzBone , vOut ); 

   
}
bool EO_Engine::WorldToScreen( vec3 vWorldLocation, float * fScreenX, float * fScreenY )
{
	int iCenterX=RefDef->iWidth/2;
	int iCenterY=RefDef->iHeight/2;


	vec3 vLocal, vTransForm;
	
	vec3 vright;
	VectorCopy(RefDef->vViewAxis[1],vright);
    vec3 vup;
	VectorCopy(RefDef->vViewAxis[2],vup);
    vec3 vfwd;
	VectorCopy(RefDef->vViewAxis[0],vfwd);


	VectorSubtract(vWorldLocation, RefDef->vViewOrg, vLocal);


    vTransForm[0]  = DotProduct(vLocal,vright);
    vTransForm[1]  = DotProduct(vLocal,vup);
    vTransForm[2]  = DotProduct(vLocal,vfwd);


	if (vTransForm[2] < 0.01) 
    {
        return 0;
    }


    if(fScreenX&&fScreenY)
    {
		*fScreenX = iCenterX * (1-(vTransForm[0] / RefDef->flFOVX  / vTransForm[2]));
		*fScreenY = iCenterY * (1-(vTransForm[1] / RefDef->flFOVY / vTransForm[2]));
    }


	return  vTransForm[2] > 0;
}