#include "EO_Main.h"

EO_Math Math;

float EO_Math::GetDistance( vec3 A, vec3 B )
{
	float dx = A[0] - B[0];
	float dy = A[1] - B[1];
	float dz = A[2] - B[2];

	return (float)sqrt( ( dx * dx ) + ( dy * dy ) + ( dz * dz ) );
}

float EO_Math::Get2dDistance( float A[2], float B[2] )
{
	float dx = A[0] - B[0];
	float dy = A[1] - B[1];

	return (float)sqrt( ( dx * dx ) + ( dy * dy ) );
}

void EO_Math::AngleVectors( const vec3 angles, vec3 forward, vec3 right, vec3 up)
{
	float			angle;
	static float	sr, sp, sy, cr, cp, cy;

	angle = angles[YAW] * (M_PI*2 / 360);
	sy = sin(angle);
	cy = cos(angle);

	angle = angles[PITCH] * (M_PI*2 / 360);
	sp = sin(angle);
	cp = cos(angle);

	angle = angles[ROLL] * (M_PI*2 / 360);
	sr = sin(angle);
	cr = cos(angle);

	if (forward)
	{
		forward[0] = cp*cy;
		forward[1] = cp*sy;
		forward[2] = -sp;
	}
	if (right)
	{
		right[0] = (-1*sr*sp*cy+-1*cr*-sy);
		right[1] = (-1*sr*sp*sy+-1*cr*cy);
		right[2] = -1*sr*cp;
	}
	if (up)
	{
		up[0] = (cr*sp*cy+-sr*-sy);
		up[1] = (cr*sp*sy+-sr*cy);
		up[2] = cr*cp;
	}
}

void EO_Math::vectoangles( const vec3 value1, vec3 angles )
{
	float	forward;
	float	yaw, pitch;
	
	if( value1[1] == 0 && value1[0] == 0 )
	{
		yaw = 0;
		if ( value1[2] > 0 )
			pitch = 90;
		else
			pitch = 270;
	}
	else
	{
		if ( value1[0] )
			yaw = ( atan2 ( value1[1], value1[0] ) * ( 180.0f / M_PI ) );
		else if ( value1[1] > 0 )
			yaw = 90.0f;
		else
			yaw = 270.0f;

		if ( yaw < 0.0f )
			yaw += 360.0f;

		forward = sqrt ( ( value1[0] * value1[0] ) + ( value1[1] * value1[1] ) );
		pitch = ( atan2( value1[2], forward ) * ( 180.0f / M_PI ) );

		if ( pitch < 0.0f )
			pitch += 360;
	}

	angles[PITCH]	= -pitch;
	angles[YAW]		= yaw;
	angles[ROLL]	= 0;
}

float EO_Math::AngleNormalize360 ( float angle ) 
{
	return ((float)(360.0 / 65536) * ((int)(angle * (65536 / 360.0)) & 65535));
}

float EO_Math::AngleNormalize180 ( float angle ) 
{
	angle = AngleNormalize360( angle );
	if ( angle > 180.0 ) {
		angle -= 360.0;
	}
	return angle;
}
void EO_Math::VectorViewAngles(float *flLocation,float *flOut)
{
	vec3 vDelta,vAngles;
	VectorSubtract(flLocation,RefDef->vViewOrg,vDelta);
	vectoangles(vDelta,vAngles);

	if(vAngles[1]>180.0f)
		vAngles[1]-=360.0f;
	else if(vAngles[1]<-180.0f)
		vAngles[1]+=360.0f;
	
	if(vAngles[0]>180.0f)
		vAngles[0]-=360.0f;
	else if(vAngles[0]<-180.0f)
		vAngles[0]+=360.0f;

	vAngles[1]-=RefDefViewAngles[1];
	vAngles[0]-=RefDefViewAngles[0];

	if(vAngles[1]>180.0f)
		vAngles[1]-=360.0f;
	else if(vAngles[1]<-180.0f)
		vAngles[1]+=360.0f;

	if(vAngles[0]>180.0f)
		vAngles[0]-=360.0f;
	else if(vAngles[0]<-180.0f)
		vAngles[0]+=360.0f;

	VectorCopy(vAngles,flOut);
}
void EO_Math::GetAngleToOrigin(vec3 vOrigin, float &flOutX, float &flOutY)
{
	vec3 vEntity, vAngle;
	VectorSubtract(vOrigin, RefDef->vViewOrg, vEntity);
    vectoangles(vEntity, vAngle);

    if (vAngle[1] > 180.0f)           
        vAngle[1] -= 360.0f;
    else if (vAngle[1] < -180.0f)   
        vAngle[1] += 360.0f;

    if (vAngle[0] > 180.0f)        
        vAngle[0] -= 360.0f;
    else if (vAngle[0] < -180.0f)    
        vAngle[0] += 360.0f;

	
	vAngle[1] -= RefDefViewAngles[1];
	vAngle[0] -= RefDefViewAngles[0];

    if (vAngle[0] > 180.0f)          
        vAngle[0] -= 360.0f;
    else if (vAngle[0] < -180.0f)   
        vAngle[0] += 360.0f;

    if (vAngle[1] > 180.0f)      
        vAngle[1] -= 360.0f;
    else if (vAngle[1] < -180.0f)   
        vAngle[1] += 360.0f;

    flOutX = vAngle[1];
    flOutY = vAngle[0];
} 
void EO_Math::GetAngleToOrigin(vec3 vOrigin,vec3 ViewAngle , float &flOutX, float &flOutY)
{
	vec3 vEntity, vAngle;
	VectorSubtract(vOrigin, RefDef->vViewOrg, vEntity);
	vectoangles(vEntity, vAngle);

    if (vAngle[1] > 180.0f)           
        vAngle[1] -= 360.0f;
    else if (vAngle[1] < -180.0f)   
        vAngle[1] += 360.0f;

    if (vAngle[0] > 180.0f)        
        vAngle[0] -= 360.0f;
    else if (vAngle[0] < -180.0f)    
        vAngle[0] += 360.0f;

	vAngle[1] -= ViewAngle[1];
	vAngle[0] -= ViewAngle[0];

    if (vAngle[0] > 180.0f)          
        vAngle[0] -= 360.0f;
    else if (vAngle[0] < -180.0f)   
        vAngle[0] += 360.0f;

    if (vAngle[1] > 180.0f)      
        vAngle[1] -= 360.0f;
    else if (vAngle[1] < -180.0f)   
        vAngle[1] += 360.0f;

    flOutX = vAngle[1];
    flOutY = vAngle[0];
} 