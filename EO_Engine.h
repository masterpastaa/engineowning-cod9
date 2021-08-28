
typedef bool ( __cdecl* CG_DObjGetWorldTagPos_t )( centity* pEnt, void* DObj, UINT Tag, float* vOut );
static CG_DObjGetWorldTagPos_t CG_DObjGetWorldTagPos = ( CG_DObjGetWorldTagPos_t )0x4A10D0;

typedef void* ( __cdecl* Com_GetClientDObj_t )( UINT ClientNum, UINT a2 );
static Com_GetClientDObj_t Com_GetClientDObj = ( Com_GetClientDObj_t )0x5FE980;

typedef int (*__cdecl AddCmdBuff_646BC0)(int a1, char* a2);

typedef bool (*__cdecl IsVisible_597DD0)(int a1,centity* Ent);


struct EO_Engine
{
	AddCmdBuff_646BC0 SendCmd;
	IsVisible_597DD0 IsVisible;

	void Init();
	bool GetPlayerTag( centity* pEnt, WORD SzBone, float* vOut );
	bool WorldToScreen( vec3 vWorldLocation, float * fScreenX, float * fScreenY );
};
extern EO_Engine Engine;