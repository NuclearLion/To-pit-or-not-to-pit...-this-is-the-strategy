//Copyright Dan-Dominic Staicu 311CA (dando.ds11@gmail.com) 2023
#include "f_print.h"

void print(sensor *a_sensors, int dim)
{
	int index = 0;
	scanf("%d", &index);

	//check if index is inside
	if (index >= dim || index < 0) {
		printf("Index not in range!\n");
		return;
	}

	//check type of sensor and print accordingly
	sensor sen = a_sensors[index];
	if (sen.sensor_type == 0) {
		tire_sensor *sens = (tire_sensor *)sen.sensor_data;
		print_tire_sens(*sens);
	} else if (sen.sensor_type == 1) {
		power_management_unit *sens = (power_management_unit *)sen.sensor_data;
		print_pmu_sens(*sens);
	} else {
		//if for anuy reason the type is different from 0/1 print an error
		fprintf(stderr, "unknown sensor type\n");
	}
}

void print_tire_sens(tire_sensor sens)
{
	printf("Tire Sensor\n");
	printf("Pressure: %0.2f\n", sens.pressure);
	printf("Temperature: %0.2f\n", sens.temperature);
	printf("Wear Level: %d%%\n", sens.wear_level);

	if (sens.performace_score >= 1 && sens.performace_score <= 10)
		printf("Performance Score: %d\n", sens.performace_score);
	else
		printf("Performance Score: Not Calculated\n");
}

void print_pmu_sens(power_management_unit sens)
{
	printf("Power Management Unit\n");
	printf("Voltage: %0.2f\n", sens.voltage);
	printf("Current: %0.2f\n", sens.current);
	printf("Power Consumption: %0.2f\n", sens.power_consumption);
	printf("Energy Regen: %d%%\n", sens.energy_regen);
	printf("Energy Storage: %d%%\n", sens.energy_storage);
}
