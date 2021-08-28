#include "EO_Main.h"

EO_Draw Draw;

void EO_Draw::Init()
{
	normalfont = RegisterFont("fonts/normalFont");
	bigfont = RegisterFont("fonts/bigfont");
	consolefont = RegisterFont("fonts/consolefont");
	smallfont = RegisterFont("fonts/smallfont");

	WhiteShader = RegisterShader("white");
}

void EO_Draw::DrawString(float X,float Y,float Size,void* Font,Color col,char* text)
{
	DrawEngineText(text,strlen(text),Font,X,Y,Size,Size,0,col,0);
}
void EO_Draw::DrawRect(float X,float Y,float w,float h,Color col)
{
	DrawShaderStreched(X,Y,w,h,0,1,1,0,col,WhiteShader);
}
void EO_Draw::DrawBox(float X,float Y,float w,float h,float size,Color col)
{
	DrawRect( X, Y, w, size, col );
	Y += size;
	DrawRect( X, Y, size, h - ( 2 * size ), col );
	Y += ( h - ( 2 * size ) );
	DrawRect( X, Y, w, size, col );
	Y -= ( h - ( 2 * size ) );
	X += ( w - size );
	DrawRect( X, Y, size, h - ( 2 * size ), col);
}