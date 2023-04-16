//Copyright Dan-Dominic Staicu 311CA (dando.ds11@gmail.com) 2023
#include "input_data.h"

sensor *read_data(FILE *data_f, int *sens_cnt)
{
	//read the count of sensors in binary
	*sens_cnt = 0;
	fread(sens_cnt, sizeof(int), 1, data_f);

	//alloc mem for the array of sensors
	sensor *a_sensors = calloc(*sens_cnt, sizeof(sensor));
	if (!a_sensors) {
		fprintf(stderr, "a_sensors calloc failed\n");
		exit(-1);
	}

	for (int i = 0; i < *sens_cnt; ++i) {
		//read the type and save it
		enum sensor_type type = 0;
		fread(&type, sizeof(enum sensor_type), 1, data_f);
		a_sensors[i].sensor_type = type;

		//read the sensors according to their type
		if (type == 1) {
			power_management_unit *pmu =
			(power_management_unit *)calloc(1, sizeof(power_management_unit));
			if (!pmu) {
				fprintf(stderr, "calloc of pmu failed\n");
				exit(-1);
			}

			//read the whole data at once inside the struct
			fread(pmu, sizeof(power_management_unit), 1, data_f);
			a_sensors[i].sensor_data = pmu;
		} else if (type == 0) {
			tire_sensor *tire = (tire_sensor *)calloc(1, sizeof(tire_sensor));
			if (!tire) {
				fprintf(stderr, "tire alloc failed\n");
				exit(-1);
			}

			//read the whole data at once inside the struct
			fread(tire, sizeof(tire_sensor), 1, data_f);
			a_sensors[i].sensor_data = tire;
		} else {
			printf("unknown type\n");
		}

		//read the count of operations of each sensor
		int nr_op = 0;
		fread(&nr_op, sizeof(int), 1, data_f);
		a_sensors[i].nr_operations = nr_op;

		//alloc mem for the array of indexes of operations
		a_sensors[i].operations_idxs = calloc(nr_op, sizeof(int));
		if (!a_sensors[i].operations_idxs) {
			fprintf(stderr, "op idxs alloc failend\n");
			exit(-1);
		}

		//read the whole array at once
		fread(a_sensors[i].operations_idxs, sizeof(int), nr_op, data_f);
	}

	//sort the array according to the type using the type field
	qsort(a_sensors, *sens_cnt, sizeof(sensor), cmp_enum);

	return a_sensors;
}

int cmp_enum(const void *a, const void *b)
{
	const sensor *sens_a = (const sensor *)a;
	const sensor *sens_b = (const sensor *)b;

	//sort so that pmu is above tire (1 above 0)
	if (sens_a->sensor_type < sens_b->sensor_type)
		return 1;
	else if (sens_a->sensor_type > sens_b->sensor_type)
		return -1;
	return 0;
}
