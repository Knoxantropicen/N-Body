#include <stdio.h>
#include "config.h"
#include "nbodies.h"
#include "wtime.c"

int main(int argc, char* argv[]) {

	double t1, t2, t3;
	t1 = wtime();

	initBodies(N);

	t2 = wtime();

	runBodies(N);

	t3 = wtime();

	printf("Initialize bodies: %-5.4f seconds\n", t2 - t1);
	printf("Simulation: %-5.4f seconds\n", t3 - t2);
	return 0;
}