#include "free_all.h"

void free_all(sensor **a_sensors, int dim)
{
	for (int i = 0; i < dim; ++i) {
		free((*a_sensors)[i].operations_idxs);
		free((*a_sensors)[i].sensor_data);
	}

	free(*a_sensors);
}
