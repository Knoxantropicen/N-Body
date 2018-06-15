#pragma once
#include "config.h"

#define TIMESTEP 0.01
#define MAXSTEP (1000. * TIMESTEP)
#define DIM 2
#define MINDIST 0.00001
#define GFORCE 4.

#define MINPOS -10000.
#define MAXPOS 10000.
#define MINVEL -100.
#define MAXVEL 100.
#define MINMASS 10.
#define MAXMASS 100.


struct BODY {
	double pos[DIM];
	double vel[DIM];
	double acc[DIM];
	double mass;
};

extern BODY body[N];

void initBodies(int n);
void addAcc(int i, int j);
void advanceBodies(int n);
void runBodies(int n);