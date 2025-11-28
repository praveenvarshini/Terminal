#ifndef MATHOPS_H
#define MATHOPS_H

void mathops_init();

/* Basic math */
void cmd_add(int argc, char **argv);
void cmd_sub(int argc, char **argv);
void cmd_mul(int argc, char **argv);
void cmd_div(int argc, char **argv);
void cmd_mod(int argc, char **argv);

/* Advanced */
void cmd_pow(int argc, char **argv);
void cmd_sqrt(int argc, char **argv);
void cmd_abs(int argc, char **argv);

/* Multi-number */
void cmd_maxn(int argc, char **argv);
void cmd_minn(int argc, char **argv);
void cmd_avgn(int argc, char **argv);

#endif
