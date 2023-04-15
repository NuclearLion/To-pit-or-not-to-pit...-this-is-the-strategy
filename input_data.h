#ifndef _INPUT_DATA_H_
#define _INPUT_DATA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structs.h"

sensor *read_data(FILE *data_f, int *sens_cnt);

#endif