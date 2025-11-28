#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../UI/ui.h"
#include "../Util/util.h"
#include "sysops.h"
#include "../Command/command.h"

static time_t startTime;

// =======================================================
// Initialize SystemOps (record program start time)
// =======================================================
#if 0
void sysops_init() {
    startTime = time(NULL);
}
#endif

void sysops_init() {
    command_register("time",       "Show Current Time",cmd_time);
    command_register("date",  "Show today's Date",cmd_date);
    command_register("timestamp", "UNIX timestamp",cmd_timestamp);
    command_register("uptime", "seconds since program started",cmd_uptime);
    command_register("banner",     "set editable banner text",cmd_banner);
    command_register("cls",  "clear screen using ANSI codes",cmd_cls);
    command_register("about",  "Info",cmd_about);
    command_register("rand",  "random number 0 to n (enter rand n)",cmd_rand); 
}
// =======================================================
// time -> show current time
// =======================================================
void cmd_time(int argc, char **argv) {
    (void)argc; (void)argv;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Current time: %02d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);
}

// =======================================================
// date -> show date
// =======================================================
void cmd_date(int argc, char **argv) {
    (void)argc; (void)argv;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Date: %04d-%02d-%02d\n",
           t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}

// =======================================================
// timestamp -> UNIX timestamp
// =======================================================
void cmd_timestamp(int argc, char **argv) {
    (void)argc; (void)argv;
    printf("Timestamp: %ld\n", time(NULL));
}

// =======================================================
// uptime -> seconds since program started
// =======================================================
void cmd_uptime(int argc, char **argv) {
    (void)argc; (void)argv;

    time_t now = time(NULL);
    printf("Uptime: %ld seconds\n", now - startTime);
}

// =======================================================
// banner -> set editable banner text
// stored in filesystem/banner.txt
// =======================================================
void cmd_banner(int argc, char **argv) {
    if (argc < 2) {
        ui_warning("Usage: banner <text>");
        return;
    }

    FILE *fp = fopen("filesystem/banner.txt", "w");
    if (!fp) {
        ui_error("Cannot write banner file.");
        return;
    }

    // combine words back into a single string
    for (int i = 1; i < argc; i++) {
        fprintf(fp, "%s ", argv[i]);
    }

    fclose(fp);
    ui_success("Banner updated.");
}

// =======================================================
// cls -> clear screen using ANSI codes
// =======================================================
void cmd_cls(int argc, char **argv) {
    (void)argc; (void)argv;
    printf("\033[2J\033[H");
}

// =======================================================
// about -> info
// =======================================================
void cmd_about(int argc, char **argv) {
    (void)argc; (void)argv;

    printf("Nebula Terminal v1.0\n");
    printf("Modules: BasicOps, DirOps, TextOps, SearchOps, MathOps, SystemOps\n");
    printf("Authors: You\n");
}

// =======================================================
// rand <n> -> random number 0 to n
// =======================================================
void cmd_rand(int argc, char **argv) {
    if (argc != 2) {
        ui_warning("Usage: rand <n>");
        return;
    }

    if (!util_isNumber(argv[1])) {
        ui_error("Not a number.");
        return;
    }

    int n = atoi(argv[1]);
    printf("Random: %d\n", rand() % (n + 1));
}
