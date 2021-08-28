#define PITCH 0
#define YAW 1
#define ROLL 2
#define M_PI 3.14159265358979323846f

#define POW(x)((x)*(x))
#define VectorLength(a)         sqrt(POW((a)[0])+POW((a)[1])+POW((a)[2]))
#define DotProduct(x,y)			((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define VectorSubtract(a,b,c)	((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)		((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define VectorCopy4(a,b)		((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2],(b)[3]=(a)[3])
#define	VectorScale(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define	VectorMA(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define VectorCmp(a,b)			(((a)[0]==(b)[0])&&((a)[1]==(b)[1])&&((a)[2]==(b)[2]))
#define VectorDistance(a,b)		(sqrt(POW(a[0]-b[0]) + POW(a[1]-b[1]) + POW(a[2]-b[2])))
#define	CMD_BACKUP	128	
#define	CMD_MASK (CMD_BACKUP - 1)
#define IN_ATTACK ( 1<<0 )
#define VectorLength(a)         sqrt(POW((a)[0])+POW((a)[1])+POW((a)[2]))
#define VectorDivide			(v, s, o)((o)[0]=(v)[0]/=(s),(o)[1]=(v)[1]/=(s),(o)[2]=(v)[2]/=(s))
#define VectorNormalize(a)      {vec_t l=VectorLength(a);(a)[0]/=l;(a)[1]/=l;(a)[2]/=l;}

struct EO_Math
{
	float GetDistance( float* A, float* B );
	float Get2dDistance( float A[2], float B[2] );
	void AngleVectors( const float* angles, float* forward, float* right, float* up);
	void vectoangles( const float* value1, float* angles );
	float AngleNormalize360 ( float angle ) ;
	float AngleNormalize180 ( float angle ) ;
	void VectorViewAngles(float *flLocation,float *flOut);
	void GetAngleToOrigin(float* vOrigin, float &flOutX, float &flOutY);
	void GetAngleToOrigin(float* vOrigin,float* ViewAngle , float &flOutX, float &flOutY);
};
extern EO_Math Math;