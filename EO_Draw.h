
typedef int (*__cdecl RegisterShader_t)(char* name);
static RegisterShader_t RegisterShader = (RegisterShader_t)0x734B50;

typedef void* (*__cdecl RegisterFont_t)(char* name);
static RegisterFont_t RegisterFont = (RegisterFont_t)0x557D80;

typedef int (*__cdecl DrawEngineText_t )(char* Text, int NumOfChars, void* Font, float X, float Y, float scaleX, float scaleY, float unk1, float* Color, int unk2 );
static DrawEngineText_t DrawEngineText = ( DrawEngineText_t )0x710FE0;

typedef void (*__cdecl DrawShaderStreched_t)(float x,float y,float w,float h,float TileX,float shaderwidth,float shaderheight,float TileY,float *color,int pShader);
static DrawShaderStreched_t DrawShaderStreched = (DrawShaderStreched_t)0x710BF0;

typedef float Color[4];

static Color RED = {1,0,0,1};

static Color WHITE = {1,1,1,1};
static Color BLUE = {0,0,1,1};
static Color GREEN = {0,1,0,1};
static Color MENUBG = {0,0,0,0.7};
static Color GRAY = {0.65, 0.65, 0.65, 1};
static Color BLACK = {0,0,0,1};

struct EO_Draw
{
	void* normalfont;
	void* bigfont;
	void* consolefont;
	void* smallfont;

	int WhiteShader;

	void Init();

	void DrawString(float X,float Y,float Size,void* Font,Color col,char* text);
	void DrawRect(float X,float Y,float w,float h,Color col);
	void DrawBox(float X,float Y,float w,float h,float size,Color col);

};extern EO_Draw Draw;