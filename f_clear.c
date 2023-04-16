#include "f_clear.h"

void clear(sensor **a_sensors, int *dim)
{
	for (int i = 0; i < *dim; ++i) {
		sensor sen = (*a_sensors)[i];
		if (sen.sensor_type == 0) {
			tire_sensor *tire = (tire_sensor *)sen.sensor_data;
			if (!tire_check(tire)) {
				remove_sensor(a_sensors, dim, i);
				--i;
			}

		} else if (sen.sensor_type == 1) {
			power_management_unit
			*pmu = (power_management_unit *)sen.sensor_data;
			if (!pmu_check(pmu)) {
				remove_sensor(a_sensors, dim, i);
				--i;
			}
		} else {
			fprintf(stderr, "wrong value of sensor type\n");
		}
	}
}

int tire_check(tire_sensor *tire)
{
	if (tire->pressure < 19 || tire->pressure > 28)
		return 0;

	if (tire->temperature < 0 || tire->temperature > 120)
		return 0;

	if (tire->wear_level < 0 || tire->wear_level > 100)
		return 0;

	return 1;
}

int pmu_check(power_management_unit *pmu)
{
	if (pmu->voltage < 10 || pmu->voltage > 20)
		return 0;

	if (pmu->current < -100 || pmu->current > 100)
		return 0;

	if (pmu->power_consumption < 0 || pmu->power_consumption > 1000)
		return 0;

	if (pmu->energy_regen < 0 || pmu->energy_regen > 100)
		return 0;

	if (pmu->energy_storage < 0 || pmu->energy_storage > 100)
		return 0;

	return 1;
}

void remove_sensor(sensor **a_sensors, int *dim, int ind)
{
	if (ind < 0 || ind >= *dim)
		return;

	free((*a_sensors)[ind].sensor_data);
	free((*a_sensors)[ind].operations_idxs);

	for (int i = ind; i < *dim - 1; ++i)
		(*a_sensors)[i] = (*a_sensors)[i + 1];

	*dim -= 1;

	sensor *tmp = realloc(*a_sensors, (*dim) * sizeof(sensor));
	if (!tmp) {
		fprintf(stderr, "tmp realloc failed\n");
		return;
	}

	*a_sensors = tmp;
}
