#include "free_and_exit.h"

void free_and_exit(sensor *a_sensors, int dim)
{
    for (int i = 0; i < dim; ++i) {
        //free(a_sensors[i]->operations_idxs);
        //free(a_sensors[i]->sensor_data);
        free(a_sensors[i].operations_idxs);
        free(a_sensors[i].sensor_data);
    }

    free(a_sensors);
}
