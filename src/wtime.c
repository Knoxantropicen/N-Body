#include <sys/time.h>
#include <sys/resource.h>

double wtime() {
	struct timeval time;
	struct timezone zone;
	gettimeofday(&time, &zone);
	return double(time.tv_sec) + double(time.tv_usec) * 1e-6;
}