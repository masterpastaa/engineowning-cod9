struct EO_ESP
{
	void DoESP();
};
extern EO_ESP ESP;


struct EO_Aimbot
{
	int BestTarget;
	float AimAtPos[3];
	float LastDistance;
	void DoAimbot();
};
extern EO_Aimbot Aimbot;