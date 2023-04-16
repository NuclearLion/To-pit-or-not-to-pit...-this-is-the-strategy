//Copyright Dan-Dominic Staicu 311CA (dando.ds11@gmail.com) 2023
#include "f_analyze.h"

void analyze(sensor *a_sensors, int dim)
{
	int index = 0;
	scanf("%d", &index);

	if (index >= dim || index < 0) {
		printf("Index not in range!\n");
		return;
	}

	void (**operations)(void *) =
	(void (**)(void *))malloc(OP_CNT * sizeof(void (*)(void *)));
	if (!operations) {
		fprintf(stderr, "operations malloc failed\n");
		exit(-1);
	}

	get_operations((void **)operations);

	sensor curr_sens = a_sensors[index];

	for (int i = 0; i < curr_sens.nr_operations; ++i)
		operations[curr_sens.operations_idxs[i]](curr_sens.sensor_data);

	free(operations);
}
