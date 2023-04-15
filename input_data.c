#include "input_data.h"

void read_data(FILE *data_f, sensor *a_sensors, int *sens_cnt)
{
    *sens_cnt = 0;
    fread(&sens_cnt, sizeof(int), 1, data_f);

    a_sensors = calloc(sens_cnt, sizeof(sensor));
    if (!a_sensors) {
        fprintf(stderr, "a_sensors calloc failed\n");
        exit(-1);
    }

    for (int i = 0; i < *sens_cnt; ++i) {
        int type = 0;
        fread(&type, sizeof(int), 1, data_f);

        a_sensors[i].sensor_type = type;

        if (type == 0) {
            power_management_unit *pmu = calloc(1, sizeof(power_management_unit));
            if (!pmu) {
                fprintf(stderr, "calloc of pmu failed\n");
                exit(-1);
            }
            fread(&pmu, sizeof(pmu), 1, data_f);

            a_sensors[i].sensor_data = pmu;
        } else if (type == 1) {
            tire_sensor *tire = (tire_sensor *)calloc(1, sizeof(tire_sensor));
            if (!tire) {
                fprintf(stderr, "tire alloc failend\n");
                exit(-1);
            }
            fread(&tire, sizeof(tire_sensor), 1, data_f);

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