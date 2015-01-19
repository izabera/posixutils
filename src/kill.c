/*
 *  kill.c
 *  This file is part of posixutils.
 *
 *  Copyright (C) 2015 izabera
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <getopt.h>
#include <libgen.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
/* kill */

char *signames[] = {
  /* mostly from i686 linux kernel headers, bash and gnu kill */
  "0",
  "HUP",    /*  1 */
  "INT",    /*  2 */
  "QUIT",   /*  3 */
  "ILL",    /*  4 */
  "TRAP",   /*  5 */
  "ABRT",   /*  6 */
  "BUS",    /*  7 */
  "FPE",    /*  8 */
  "KILL",   /*  9 */
  "USR1",   /* 10 */
  "SEGV",   /* 11 */
  "USR2",   /* 12 */
  "PIPE",   /* 13 */
  "ALRM",   /* 14 */
  "TERM",   /* 15 */
  "STKFLT", /* 16 */
  "CHLD",   /* 17 */
  "CONT",   /* 18 */
  "STOP",   /* 19 */
  "TSTP",   /* 20 */
  "TTIN",   /* 21 */
  "TTOU",   /* 22 */
  "URG",    /* 23 */
  "XCPU",   /* 24 */
  "XFSZ",   /* 25 */
  "VTALRM", /* 26 */
  "PROF",   /* 27 */
  "WINCH",  /* 28 */
  "IO",     /* 29 */
  "PWR",    /* 30 */
  "SYS",    /* 31 */
  "32",     /* 32 - used internally by glibc (?) */
  "33",     /* 33 - used internally by glibc (?) */
  "RT0",    /* 34 - RTMIN */
  "RT1",    /* 35 */
  "RT2",    /* 36 */
  "RT3",    /* 37 */
  "RT4",    /* 38 */
  "RT5",    /* 39 */
  "RT6",    /* 40 */
  "RT7",    /* 41 */
  "RT8",    /* 42 */
  "RT9",    /* 43 */
  "RT10",   /* 44 */
  "RT11",   /* 45 */
  "RT12",   /* 46 */
  "RT13",   /* 47 */
  "RT14",   /* 48 */
  "RT15",   /* 49 */
  "RT16",   /* 50 */
  "RT17",   /* 51 */
  "RT18",   /* 52 */
  "RT19",   /* 53 */
  "RT20",   /* 54 */
  "RT21",   /* 55 */
  "RT22",   /* 56 */
  "RT23",   /* 57 */
  "RT24",   /* 58 */
  "RT25",   /* 59 */
  "RT26",   /* 60 */
  "RT27",   /* 61 */
  "RT28",   /* 62 */
  "RT29",   /* 63 */
  "RT30"    /* 64 */
};

/* print signal names, return -1 for unknown signals */
int siglist (int sig) {
  if (sig == -1) {
    for (sig = 0; sig < 64; sig++) printf("%s ", signames[sig]);
    printf("%s\n", signames[sig]);
    sig = 0;
  }
  else if (sig > 0 && sig % 128 < 65 && sig != 128 && sig < 255)
    printf("%s\n", signames[sig%128]);
  else sig = -1;
  return sig;
}

int findsig(char *sig) {
  int ret;
  unsigned i;
  for (i = 0; i < strlen(sig); i++) sig[i] = toupper(sig[i]);
  for (ret = 0; ret < 65; ret++)
    if (strcmp(sig, signames[ret]) == 0) return ret;
  return -2;
}

int main (int argc, char *argv[]) {
  int sig = 15, opt;
  bool got = false;
  pid_t pid;
  /* i suck at parsing options */
  while ((opt = getopt(argc, argv, ":s:l:")) != -1) {
    switch (opt) {
      case 's': 
        if ((sig = findsig(optarg)) < 0) {
          fprintf(stderr, "%s: Invalid signal: %s\n", argv[0], optarg);
          exit(EXIT_FAILURE);
        }
        break;
      case 'l':
        sig = atoi(optarg);
        if (siglist(sig) < 0) {
          fprintf(stderr, "%s: Invalid signal: %d\n", argv[0], sig);
          exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS); 
      case ':':
        if (optopt == 'l') {
          siglist(-1);
          exit(EXIT_SUCCESS); 
        }
        else {
          fprintf(stderr, "%s: Option -%c requires a parameter\n", argv[0], optopt);
          exit(EXIT_FAILURE);
        }
      case '?':
        /* cheating
         * assuming the string is in argv[1]
         * which may or may not be true, but anyway it seems ok with posix */
        argv[1]++;
        if (isalpha(argv[1][0])) sig = findsig(argv[1]);
        else sig = atoi(argv[1]);
        if (sig > 0 && sig % 128 < 65 && sig != 128 && sig < 255) {
          got = true;
          goto outside;
        }
        else {
          fprintf(stderr, "%s: Invalid signal: %s\n", argv[0], argv[1]);
          exit(EXIT_FAILURE);
        }
    }
  }
outside:
  if (optind != argc - 1 && !got) {
    fprintf(stderr, "Usage: %s [-l|-s] [-signal] pid\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  pid = atoi(argv[argc-1]);
  if (kill(pid, sig) < 0) {
    fprintf(stderr, "%s: Error %d: %s\n", argv[0], errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  return 0;
}

