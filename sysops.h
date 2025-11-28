#ifndef SYSOPS_H
#define SYSOPS_H

void sysops_init();
void register_sysops_commands(void);

void cmd_time(int argc, char **argv);
void cmd_date(int argc, char **argv);
void cmd_timestamp(int argc, char **argv);
void cmd_uptime(int argc, char **argv);

void cmd_banner(int argc, char **argv);
void cmd_cls(int argc, char **argv);
void cmd_about(int argc, char **argv);
void cmd_rand(int argc, char **argv);

#endif
