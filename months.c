#include <stdio.h>

int main() {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    double sales[] = {
        23458.01, 40112.00, 56011.85, 37820.88, 37904.67,
        60200.22, 72400.31, 56210.89, 67230.84, 68233.12,
        80950.34, 95225.22
    };
    int MONTHS = sizeof(sales) / sizeof(sales[0]);
    double sum = 0, min = sales[0], max = sales[0];
    int min_index = 0, max_index = 0;

    printf("Monthly Sales Report:\n");
    for (int i = 0; i < MONTHS; ++i) {
        printf("%s: $%.2f\n", months[i], sales[i]);
        sum += sales[i];
        if (sales[i] < min) {
            min = sales[i];
            min_index = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            max_index = i;
        }
    }

    printf("\nSales Summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[min_index]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[max_index]);
    printf("Average sales: $%.2f\n", sum / MONTHS);

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; ++i) {
        double avg = 0;
        for (int j = i; j < i + 6; ++j) {
            avg += sales[j];
        }
        avg /= 6;
        printf("%s - %s: $%.2f\n", months[i], months[i + 5], avg);
    }


    for (int i = 0; i < MONTHS - 1; ++i) {
        for (int j = i + 1; j < MONTHS; ++j) {
            if (sales[i] < sales[j]) {
                double temp_sale = sales[i];
                sales[i] = sales[j];
                sales[j] = temp_sale;

                const char *temp_month = months[i];
                months[i] = months[j];
                months[j] = temp_month;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    for (int i = 0; i < MONTHS; ++i) {
        printf("%s: $%.2f\n", months[i], sales[i]);
    }

    return 0;
}
