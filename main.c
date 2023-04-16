//Copyright Dan-Dominic Staicu 311CA (dando.ds11@gmail.com) 2023
#include "utils.h"
#include "input_data.h"
#include "f_print.h"
#include "f_analyze.h"
#include "f_clear.h"
#include "free_all.h"

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

	a_sensors = read_data(data_file, &sensor_cnt);

	free(file_name);
	fclose(data_file);

	while (scanf("%s", command)) {
		switch (hash(command)) {
		case 0:
			print(a_sensors, sensor_cnt);
			break;
		case 1:
			analyze(a_sensors, sensor_cnt);
			break;
		case 2:
			clear(&a_sensors, &sensor_cnt);
			break;
		case 3:
			free_all(&a_sensors, sensor_cnt);
			return 0;
		default:
			fprintf(stderr, "wrong command\n");
			break;
		}
	}

	return 0;
}
