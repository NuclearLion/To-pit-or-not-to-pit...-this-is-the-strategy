#include "input_data.h"

void read_data(FILE *data_f, sensor *a_sensors, int *sens_cnt)
{
    *sens_cnt = 0;
    fread(sens_cnt, sizeof(int), 1, data_f);
    printf("SENS CNT: %d\n", *sens_cnt);

    a_sensors = calloc(*sens_cnt, sizeof(sensor));
    if (!a_sensors) {
        fprintf(stderr, "a_sensors calloc failed\n");
        exit(-1);
    }

    for (int i = 0; i < *sens_cnt; ++i) {
        if (i > 10)
            break;
        enum sensor_type type = 0;
        fread(&type, sizeof(enum sensor_type), 1, data_f);
        printf("type of i%d: %d\n", i, type);

        a_sensors[i].sensor_type = type;

        if (type == 1) {
            power_management_unit *pmu = (power_management_unit *)calloc(1, sizeof(power_management_unit));
            if (!pmu) {
                fprintf(stderr, "calloc of pmu failed\n");
                exit(-1);
            }

            fread(&pmu->voltage, sizeof(float), 1, data_f);
            fread(&pmu->current, sizeof(float), 1, data_f);
            fread(&pmu->power_consumption, sizeof(float), 1, data_f);
            fread(&pmu->energy_regen, sizeof(int), 1, data_f);
            fread(&pmu->energy_storage, sizeof(int), 1, data_f);
            // fread(pmu, sizeof(power_management_unit), 1, data_f);
            

            
            printf("pmu voltage: %f\n", pmu->voltage);
            printf("pmu current: %f\n", pmu->current);
            printf("pmu power cons: %f\n", pmu->power_consumption);
            printf("pmu energy regen: %d\n", pmu->energy_regen);
            printf("pmu energy storage: %d\n", pmu->energy_storage);
            // printf("pmu voltage: %f\n", pmu->voltage);

            //memcpy(a_sensors[i].sensor_data, pmu, sizeof(power_management_unit));
            a_sensors[i].sensor_data = pmu;
        } else if (type == 0) {
            tire_sensor *tire = (tire_sensor *)calloc(1, sizeof(tire_sensor));
            if (!tire) {
                fprintf(stderr, "tire alloc failed\n");
                exit(-1);
            }
            fread(tire, sizeof(tire_sensor), 1, data_f);

            a_sensors[i].sensor_data = tire;
        } else {
            printf("unknown type\n");
        }

        int nr_op = 0;
            fread(&nr_op, sizeof(int), 1, data_f);
            a_sensors[i].nr_operations = nr_op;

            int *op_idxs = calloc(nr_op, sizeof(int));
            if (!op_idxs) {
                fprintf(stderr, "op idxs alloc failend\n");
                exit(-1);
            }
            fread(&op_idxs, sizeof(int), nr_op, data_f);

            a_sensors[i].operations_idxs = op_idxs;
    }

}
