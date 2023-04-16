//Copyright Dan-Dominic Staicu 311CA (dando.ds11@gmail.com) 2023
#ifndef _F_CLEAR_H_
#define _F_CLEAR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"

//execute the clear command
void clear(sensor **a_sensors, int *dim);

//check parameters of tire sensors
int tire_check(tire_sensor *tire);

//check parameters of pmu sensors
int pmu_check(power_management_unit *pmu);

//remove a sensor from the array regardless of whether it is pmu or tire
void remove_sensor(sensor **a_sensors, int *dim, int ind);

#endif
