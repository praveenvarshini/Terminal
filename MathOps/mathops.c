#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../UI/ui.h"
#include "../Util/util.h"
#include "mathops.h"
#include "../Command/command.h" 

void cmd_add(int argc, char **argv) {
    if (argc != 3) { ui_warning("Usage: add <a> <b>"); return; }
    printf("%d\n", atoi(argv[1]) + atoi(argv[2]));
}
void cmd_sub(int argc, char **argv) {
    if (argc != 3) { ui_warning("Usage: sub <a> <b>"); return; }
    printf("%d\n", atoi(argv[1]) - atoi(argv[2]));
}
void cmd_mul(int argc, char **argv) {
    if (argc != 3) { ui_warning("Usage: mul <a> <b>"); return; }
    printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
}
void cmd_div(int argc, char **argv) {
    if (argc != 3) { ui_warning("Usage: div <a> <b>"); return; }
    int b = atoi(argv[2]);
    if (b == 0) { ui_error("Divide by zero."); return; }
    printf("%d\n", atoi(argv[1]) / b);
}
void cmd_mod(int argc, char **argv) {
    if (argc != 3) { ui_warning("Usage: mod <a> <b>"); return; }
    int b = atoi(argv[2]);
    if (b == 0) { ui_error("Divide by zero."); return; }
    printf("%d\n", atoi(argv[1]) % b);
}

void cmd_pow(int argc, char **argv) {
    if (argc != 3) { ui_warning("Usage: pow <a> <b>"); return; }
    printf("%g\n", pow(atof(argv[1]), atof(argv[2])));
}
void cmd_sqrt(int argc, char **argv) {
    if (argc != 2) { ui_warning("Usage: sqrt <num>"); return; }
    printf("%g\n", sqrt(atof(argv[1])));
}
void cmd_abs(int argc, char **argv) {
    if (argc != 2) { ui_warning("Usage: abs <num>"); return; }
    printf("%d\n", abs(atoi(argv[1])));
}

void cmd_maxn(int argc, char **argv) {
    if (argc < 2) { ui_warning("Usage: max <n1> <n2> ..."); return; }

    int max = atoi(argv[1]);
    for (int i = 2; i < argc; i++)
        if (atoi(argv[i]) > max) max = atoi(argv[i]);

    printf("Max = %d\n", max);
}

void cmd_minn(int argc, char **argv) {
    if (argc < 2) { ui_warning("Usage: min <n1> <n2> ..."); return; }

    int min = atoi(argv[1]);
    for (int i = 2; i < argc; i++)
        if (atoi(argv[i]) < min) min = atoi(argv[i]);

    printf("Min = %d\n", min);
}

void cmd_avgn(int argc, char **argv) {
    if (argc < 2) { ui_warning("Usage: avg <n1> <n2> ..."); return; }

    double sum = 0;
    for (int i = 1; i < argc; i++)
        sum += atof(argv[i]);

    printf("Average = %.3f\n", sum / (argc - 1));
}

void mathops_init() {
    command_register("add", "Add two numbers", cmd_add);
    command_register("sub", "Subtract two numbers", cmd_sub);
    command_register("mul", "Multiply two numbers", cmd_mul);
    command_register("div", "Divide two numbers", cmd_div);
    command_register("mod", "Modulo operation", cmd_mod);

    command_register("pow", "Power a^b", cmd_pow);
    command_register("sqrt", "Square root", cmd_sqrt);
    command_register("abs", "Absolute value", cmd_abs);

    command_register("max", "Maximum of N numbers", cmd_maxn);
    command_register("min", "Minimum of N numbers", cmd_minn);
    command_register("avg", "Average of N numbers", cmd_avgn);
}
