#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "structs.h"
#include "input_data.h"
#include "f_print.h"

int main(int argc, char const *argv[])
{
	char command[20];
	sensor *a_sensors = NULL;
	int sensor_cnt = 0;

	if (argc != 2) {
		fprintf(stderr, "Please include filename!\n");
		return 2;
	}

	int len = strlen(argv[1]);
	char *file_name = (char *)calloc(len + 1, sizeof(char)); //+1 bcs of \0
	strncpy(file_name, argv[1], len + 1);

	FILE *data_file = fopen(file_name, "rb");
	if (!data_file) {
		fprintf(stderr, "%s could not be opened\n", file_name);
		free(file_name);
		return -1;
	}

	read_data(data_file, a_sensors, &sensor_cnt);

	fclose(data_file);

	while (scanf("%s", command)) {
		switch (hash(command))
		{
		case 0:
			f_print(a_sensors, sensor_cnt);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
	
	return 0;
}
