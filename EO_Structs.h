typedef float vec3[3];

#define ANGLE2SHORT(x)((int)((x)*65536/360) & 65535)

#define ET_ZOMBIE 16
#define ET_GENERAL 0
#define ET_PLAYER 1
#define ET_PLAYER_CORPSE 2
#define ET_ITEM 3
#define ET_MISSILE 4
#define ET_INVISIBLE 5
#define ET_SCRIPTMOVER 6
#define ET_SOUND_BLEND 7
#define ET_FX 8
#define ET_LOOP_FX 9
#define ET_PRIMARY_LIGHT 10
#define ET_TURRET 11
#define ET_HELICOPTER 12
#define ET_PLANE 13
#define ET_VEHICLE 14
#define ET_VEHICLE_CORPSE 15
#define ET_ACTOR 16
#define ET_ACTOR_SPAWNER 17
#define ET_ACTOR_CORPSE 18
#define ET_STREAMER_HINT 19
#define ET_ZBARRIER 20



class PlayerActor_t
{
public:
	__int32 ServerTime; //0x0000 
	char _0x0004[36];
	vec3 Origin; //0x0028 
	vec3 Velocity; //0x0034 
	char _0x0040[76];
	__int32 Gravity; //0x008C 
	char _0x0090[4];
	__int32 Speed; //0x0094 
	char _0x0098[352];
	vec3 ViewAngles; //0x01F8 
	__int32 PlayerHeightInt; //0x0204 
	float PlayerHeightFloat; //0x0208 
	char _0x020C[44];
	__int32 iHealth; //0x0238 
	char _0x023C[4];
	__int32 iMaxHealth; //0x0240 
	char _0x0244[32];
	__int32 PrimaryWeaponID; //0x0264 
	char _0x0268[24];
	__int32 LethalWeaponID; //0x0280 
	char _0x0284[24];
	__int32 SecondaryWeaponID; //0x029C 
	char _0x02A0[24];
	__int32 TacticalWeaponID; //0x02B8 
	char _0x02BC[308];
	__int32 PrimaryAmmoStock; //0x03F0 
	char _0x03F4[4];
	__int32 SecondaryAmmoStock; //0x03F8 
	char _0x03FC[48];
	__int32 PrimaryAmmoClip; //0x042C 
	__int32 LethalAmmo; //0x0430 
	__int32 SecondaryAmmoClip; //0x0434 
	__int32 TacticalAmmo; //0x0438 
	char _0x043C[272];
	__int32 PerkFlags; //0x054C 0x10 = Reduced Spread, 0x80000 = Faster Knife
	char _0x0550[20316];
	char Name2[16]; //0x54AC 
	char _0x54BC[16];
	__int32 MaxHealth; //0x54CC 
	char _0x54D0[100];
	char Name[16]; //0x5534 Writable
	char _0x5544[132];
	__int32 Money; //0x55C8 
	char _0x55CC[556];
};//Size=0x045C

class TeamInfo_t
{
public:
	char _0x0000[4];
	__int32 iTeam; //0x0004 
	char _0x0008[56];

};//Size=0x0040

class centity_t
{
public:
	__int32 ClientNum; //0x0000 
	__int32 eFlag; //0x0004 
	char _0x0008[16];
	vec3 vOrigin; //0x0018 
	char _0x0024[24];
	float vAngles[2]; //0x003C 
	char _0x0044[28];
	__int32 iCurrentWeapon; //0x0060 
	char _0x0064[116];
	WORD eType; //0x00D8 
	char _0x00DA[66];
	vec3 vNewOrigin; //0x011C 
	char _0x0128[44];
	PlayerActor_t* PlayerActor; //0x0154 
	char _0x0158[4];
	TeamInfo_t* TeamInfo; //0x015C 
	char _0x0160[12];
	__int32 ModelIndex; //0x016C Model ID = 44 (Top of Tranzit Bus)
	char _0x0170[56];
	__int32 iHealth; //0x01A8 
	char _0x01AC[29320];
};//Size=0x7434

typedef struct
{
	char *szModel;
	char _0x0000[740];
	int iWeaponType; //0x02E8 
	int iWeaponClass; //0x02EC 
	int iPenetrateType; //0x02F0 
	int iImpactType; //0x02F4 
	char _0x02F8[4];
	int iFireType; //0x02FC 
	int iClipType; //0x0300 
}weapon_t;//Size=0x0304


class cg_t
{
public:
 __int32 clientNum; //0x0000 
char _0x0004[408];
 __int32 Time; //0x019C 
char _0x01A0[96];

};//Size=0x0200

typedef struct
{
	int iClientNum; //0x0000 
	char _0x0004[20];
	int iIngame; //0x0018 
	char _0x001C[104];
	int iPing; //0x0084 
	int iNewTime; //0x0088 
	int iTime; //0x008C 
	int iOldTime; //0x0090 
	char _0x0094[36];
	vec3 vOrigin; //0x00B8 
	char _0x00C4[88];
	int iGravity; //0x011C 
	char _0x0120[60];
	int iMoveType; //0x015C 
	char _0x0160[44];
	int iMoveFlag; //0x018C 
	char _0x0190[184];
	int iWeaponID; //0x0248 
	char _0x024C[28];
	int iInAttach; //0x0268 
	char _0x026C[4];
	float flZoomProgress; //0x0270 
	char _0x0274[84];
	int iHealth; //0x02C8 
	char _0x02CC[4];
	int iMaxHealth; //0x02D0 
	char _0x02D4[116];
	int iSecondaryWeaponID; //0x0348 
	char _0x034C[24];
	int iPrimaryWeaponID; //0x0364 
	char _0x0368[292];
	int iSecondaryClip; //0x048C 
	int iPrimaryClip; //0x0490 
	char _0x0494[52];
	int iSecondaryAmmo; //0x04C8 
	int iPrimaryAmmo; //0x04CC 
	int iLethalAmmo; //0x04D0 
	int iTacticalAmmo; //0x04D4 
}cgs_t;
typedef struct
{
	char _0x0000[8];
	int iWidth; //0x0008 
	int iHeight; //0x000C 
	char _0x0010[16];
	float flFOVX; //0x0020 
	float flFOVY; //0x0024 
	float flFOVZ; //0x0028 
	char _0x002C[4];
	float flFOV; //0x0030 
	vec3 vViewOrg; //0x0034 
	char _0x0040[4];
	vec3 vViewAxis[3]; //0x0044 
}refdef_t;//Size=0x0048

typedef struct
{
	int serverTime; //0x0000 
	int buttons; //0x0004 
	char _0x0008[4];
	int viewangles[3]; //0x000C 
	char _0x0018[36];
}usercmd_t;//Size=0x003C

typedef struct
{
	char unknown01[273576];
	usercmd_t usercmds[128]; // 0x42CA8
	int currentCmdNum; // 0x44AA8

	usercmd_t *GetUserCmd(int cmdNum)
	{
		int iCmdID=cmdNum&0x7F;
		return &usercmds[iCmdID];
	}
}input_t;
typedef struct
{
	__int32 iWorldEntNum; //0x0000 
	__int32 iEntityNum; //0x0004 
	float fDamageMultiplier; //0x0008 
	__int32 iBulletType; //0x000C 
	vec3 viewOrigin; //0x0010 
	vec3 vStart; //0x001C 
	vec3 vEnd; //0x0028 
	vec3 vDirection; //0x0034 
}bulletTrace_t;

typedef struct
{
	char _0x0000[16];
	float fraction; //0x0010 
	char _0x0014[56];
	int materialType; //0x004C 
}trace_t;

typedef struct
{
	char _0x0000[4];
	short iUsedForPlayerMesh_0; //0x0004 
	char _0x0008[38];
	vec3 vOrigin; //0x002C 
	char _0x0038[296];
	int eFlags; //0x0160 
	char _0x0164[16];
	vec3 vOldOrigin; //0x0174 
	char _0x0180[60];
	int iPlayerWeaponID; //0x01BC 
	int iPlayerPrevWeaponID; //0x01C0 
	char _0x01C4[24];
	int iClientNum; //0x01DC 
	int iFlags; //0x01E0 
	char _0x01E4[16];
	vec3 vNewOrigin; //0x01F4 
	char _0x0200[60];
	int iWeaponID2; //0x023C 
	char _0x0240[116];
	short bEntityType; //0x02B4 
	char _0x02B5[10];
	int iWeaponID; //0x02C0 
	char _0x02C4[180];
	BYTE bAlive; //0x0378 
	char _0x0379[7];
}centity;//Size=0x0380

typedef struct 
{
	char _0x0000[940];
	int pShader; //0x03AC 
	char _0x03B0[12];
	int pShader2; //0x03BC 
}weapon2_t;//Size=0x03C0
typedef struct
{
	char _0x0000[12];
	char szName[32]; //0x000C 
	int iTeam; //0x002C 
	int iTeam2; //0x0030 
	char _0x0034[44];
	int iRank; //0x0060 
	char _0x0064[48];
	int iScore; //0x0094 
	char _0x0098[72];
	char szModel[64]; //0x00E0 
	char _0x0120[932];
	vec3 ViewAngleY; //0x04C4 
	char _0x04D0[192];
	int N2399ED54; //0x0590 
	char _0x0594[48];
	int iWeaponID; //0x05C4 
	char _0x05C8[448];
	weapon2_t *pCurrentWeapon; //0x0788 
	char _0x078C[12];
	weapon2_t *pPrimaryWeapon; //0x0798 
	char _0x079C[108];
}CLient_t;//Size=0x0808

extern centity* Entities;
extern CLient_t* clientinfo;
extern cg_t* cg;
//extern cgs_t* cgs;
extern refdef_t* RefDef;

extern float* RefDefViewAngles;