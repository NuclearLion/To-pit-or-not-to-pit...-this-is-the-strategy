#ifndef _F_CLEAR_H_
#define _F_CLEAR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"

void clear(sensor **a_sensors, int *dim);

int tire_check(tire_sensor *tire);

int pmu_check(power_management_unit *pmu);

void remove_sensor(sensor **a_sensors, int *dim, int ind);

#endif
