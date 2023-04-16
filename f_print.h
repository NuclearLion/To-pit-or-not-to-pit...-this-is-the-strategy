//Copyright Dan-Dominic Staicu 311CA (dando.ds11@gmail.com) 2023
#ifndef _F_PRINT_H_
#define _F_PRINT_H_

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"

void print(sensor *a_sensors, int dim);

void print_tire_sens(tire_sensor sens);

void print_pmu_sens(power_management_unit sens);

#endif
