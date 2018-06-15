#include <math.h>
#include <stdlib.h>
#include "nbodies.h"

BODY body[N];

double rrange(double low, double high) {

	// generate random number between low and high
	return double(rand() * (high - low)) / double(RAND_MAX) + low;
}

void initBodies(int n) {

	// initialize position, velocity and acceleration of n bodies
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < DIM; ++j) {
			body[i].pos[j] = rrange(MINPOS, MAXPOS);
			body[i].vel[j] = rrange(MINVEL, MAXVEL);
			body[i].acc[j] = 0.;
		}
		body[i].mass = rrange(MINMASS, MAXMASS);
	}
}

void addAcc(int i, int j) {

	// compute distance between two bodies
	double distsq = 0.;
	double dx[DIM];
	for (int k = 0; k < DIM; ++k) {
		dx[k] = body[i].pos[k] - body[j].pos[k];
		distsq += dx[k] * dx[k];
	}
	if (distsq < MINDIST) distsq = MINDIST;
	double dist = sqrt(distsq);

	// compute unit vector
	double ud[DIM];
	for (int k = 0; k < DIM; ++k) {
		ud[k] = dx[k] / dist;
	}

	// compute accleration: ai = G * mj / distsq
	double ai = GFORCE * body[j].mass / distsq;
	double aj = GFORCE * body[i].mass / distsq;

	// add accleration using unit vector
	for (int k = 0; k < DIM; ++k) {
		body[i].acc[k] += aj * ud[k];
		body[j].acc[k] -= ai * ud[k];
	}
}

void advanceBodies(int n) {

	// apply accleration and advance bodies
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < DIM; ++j) {
			body[i].vel[j] += body[i].acc[j] * TIMESTEP;
			body[i].pos[j] += body[i].vel[j] * TIMESTEP;
			body[i].acc[j] = 0.;
		}
	}
}

void runBodies(int n) {

	// run simulation over time steps
	for (double t = 0.; t < MAXSTEP; t += TIMESTEP) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				addAcc(i, j);
			}
		}
		advanceBodies(n);
	}
}