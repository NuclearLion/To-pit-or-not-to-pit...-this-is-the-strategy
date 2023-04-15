#ifndef _INPUT_DATA_H_
#define _INPUT_DATA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structs.h"

void read_data(FILE *data_f, sensor *a_sensors, int *sens_cnt);

#endif