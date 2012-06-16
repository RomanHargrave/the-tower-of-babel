
#ifndef __GLC_DATA_H
#define __GLC_DATA_H

#include "doomtype.h"

struct GLRenderSettings
{

	SBYTE lightmode;
	bool nocoloredspritelighting;
	bool notexturefill;

	SBYTE map_lightmode;
	SBYTE map_nocoloredspritelighting;
	SBYTE map_notexturefill;

	FVector3 skyrotatevector;
	FVector3 skyrotatevector2;

};

extern GLRenderSettings glset;

#include "r_defs.h"
#include "a_sharedglobal.h"

void gl_RecalcVertexHeights(vertex_t * v);
FTextureID gl_GetSpriteFrame(unsigned sprite, int frame, int rot, angle_t ang, bool *mirror);

class AStackPoint;
struct GLSectorStackPortal;

struct FPortal
{
	fixed_t xDisplacement;
	fixed_t yDisplacement;
	int plane;
	GLSectorStackPortal *glportal;	// for quick access to the render data. This is only valid during BSP traversal!

	GLSectorStackPortal *GetGLPortal();
};

extern TArray<FPortal *> portals;
extern TArray<BYTE> currentmapsection;

void gl_InitPortals();
void gl_BuildPortalCoverage(FPortalCoverage *coverage, subsector_t *subsector, FPortal *portal);

#endif