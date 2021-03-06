CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -Wextra -O2 -march=native

all:
	mkdir -p bin
	#$(CC) $(CFLAGS) -o bin/admin src/admin.c
	#$(CC) $(CFLAGS) -o bin/alias src/alias.c
	#$(CC) $(CFLAGS) -o bin/ar src/ar.c
	#$(CC) $(CFLAGS) -o bin/asa src/asa.c
	#$(CC) $(CFLAGS) -o bin/at src/at.c
	#$(CC) $(CFLAGS) -o bin/awk src/awk.c
	$(CC) $(CFLAGS) -o bin/basename src/basename.c
	#$(CC) $(CFLAGS) -o bin/batch src/batch.c
	#$(CC) $(CFLAGS) -o bin/bc src/bc.c
	#$(CC) $(CFLAGS) -o bin/bg src/bg.c
	#$(CC) $(CFLAGS) -o bin/break src/break.c
	#$(CC) $(CFLAGS) -o bin/c99 src/c99.c
	$(CC) $(CFLAGS) -o bin/cal src/cal.c
	$(CC) $(CFLAGS) -o bin/cat src/cat.c
	#$(CC) $(CFLAGS) -o bin/cd src/cd.c
	#$(CC) $(CFLAGS) -o bin/cflow src/cflow.c
	#$(CC) $(CFLAGS) -o bin/chgrp src/chgrp.c
	#$(CC) $(CFLAGS) -o bin/chmod src/chmod.c
	#$(CC) $(CFLAGS) -o bin/chown src/chown.c
	#$(CC) $(CFLAGS) -o bin/cksum src/cksum.c
	#$(CC) $(CFLAGS) -o bin/cmp src/cmp.c
	#$(CC) $(CFLAGS) -o bin/colon src/colon.c
	#$(CC) $(CFLAGS) -o bin/comm src/comm.c
	#$(CC) $(CFLAGS) -o bin/command src/command.c
	#$(CC) $(CFLAGS) -o bin/compress src/compress.c
	#$(CC) $(CFLAGS) -o bin/continue src/continue.c
	#$(CC) $(CFLAGS) -o bin/cp src/cp.c
	#$(CC) $(CFLAGS) -o bin/crontab src/crontab.c
	#$(CC) $(CFLAGS) -o bin/csplit src/csplit.c
	#$(CC) $(CFLAGS) -o bin/ctags src/ctags.c
	#$(CC) $(CFLAGS) -o bin/cut src/cut.c
	#$(CC) $(CFLAGS) -o bin/cxref src/cxref.c
	#$(CC) $(CFLAGS) -o bin/date src/date.c
	#$(CC) $(CFLAGS) -o bin/dd src/dd.c
	#$(CC) $(CFLAGS) -o bin/delta src/delta.c
	#$(CC) $(CFLAGS) -o bin/df src/df.c
	#$(CC) $(CFLAGS) -o bin/diff src/diff.c
	$(CC) $(CFLAGS) -o bin/dirname src/dirname.c
	#$(CC) $(CFLAGS) -o bin/dot src/dot.c
	#$(CC) $(CFLAGS) -o bin/du src/du.c
	$(CC) $(CFLAGS) -o bin/echo src/echo.c
	#$(CC) $(CFLAGS) -o bin/ed src/ed.c
	#$(CC) $(CFLAGS) -o bin/env src/env.c
	#$(CC) $(CFLAGS) -o bin/eval src/eval.c
	#$(CC) $(CFLAGS) -o bin/ex src/ex.c
	#$(CC) $(CFLAGS) -o bin/exec src/exec.c
	#$(CC) $(CFLAGS) -o bin/exit src/exit.c
	#$(CC) $(CFLAGS) -o bin/expand src/expand.c
	#$(CC) $(CFLAGS) -o bin/export src/export.c
	#$(CC) $(CFLAGS) -o bin/expr src/expr.c
	$(CC) $(CFLAGS) -o bin/false src/false.c
	#$(CC) $(CFLAGS) -o bin/fc src/fc.c
	#$(CC) $(CFLAGS) -o bin/fg src/fg.c
	#$(CC) $(CFLAGS) -o bin/file src/file.c
	#$(CC) $(CFLAGS) -o bin/find src/find.c
	#$(CC) $(CFLAGS) -o bin/fold src/fold.c
	#$(CC) $(CFLAGS) -o bin/fort77 src/fort77.c
	#$(CC) $(CFLAGS) -o bin/fuser src/fuser.c
	#$(CC) $(CFLAGS) -o bin/gencat src/gencat.c
	#$(CC) $(CFLAGS) -o bin/get src/get.c
	#$(CC) $(CFLAGS) -o bin/getconf src/getconf.c
	#$(CC) $(CFLAGS) -o bin/getopts src/getopts.c
	#$(CC) $(CFLAGS) -o bin/grep src/grep.c
	#$(CC) $(CFLAGS) -o bin/hash src/hash.c
	$(CC) $(CFLAGS) -o bin/head src/head.c
	#$(CC) $(CFLAGS) -o bin/iconv src/iconv.c
	#$(CC) $(CFLAGS) -o bin/id src/id.c
	#$(CC) $(CFLAGS) -o bin/ipcrm src/ipcrm.c
	#$(CC) $(CFLAGS) -o bin/ipcs src/ipcs.c
	#$(CC) $(CFLAGS) -o bin/jobs src/jobs.c
	#$(CC) $(CFLAGS) -o bin/join src/join.c
	$(CC) $(CFLAGS) -o bin/kill src/kill.c
	#$(CC) $(CFLAGS) -o bin/lex src/lex.c
	$(CC) $(CFLAGS) -o bin/link src/link.c
	#$(CC) $(CFLAGS) -o bin/ln src/ln.c
	#$(CC) $(CFLAGS) -o bin/locale src/locale.c
	#$(CC) $(CFLAGS) -o bin/localedef src/localedef.c
	#$(CC) $(CFLAGS) -o bin/logger src/logger.c
	#$(CC) $(CFLAGS) -o bin/logname src/logname.c
	#$(CC) $(CFLAGS) -o bin/lp src/lp.c
	#$(CC) $(CFLAGS) -o bin/ls src/ls.c
	#$(CC) $(CFLAGS) -o bin/m4 src/m4.c
	#$(CC) $(CFLAGS) -o bin/mailx src/mailx.c
	#$(CC) $(CFLAGS) -o bin/make src/make.c
	#$(CC) $(CFLAGS) -o bin/man src/man.c
	#$(CC) $(CFLAGS) -o bin/mesg src/mesg.c
	#$(CC) $(CFLAGS) -o bin/mkdir src/mkdir.c
	#$(CC) $(CFLAGS) -o bin/mkfifo src/mkfifo.c
	#$(CC) $(CFLAGS) -o bin/more src/more.c
	#$(CC) $(CFLAGS) -o bin/mv src/mv.c
	#$(CC) $(CFLAGS) -o bin/newgrp src/newgrp.c
	#$(CC) $(CFLAGS) -o bin/nice src/nice.c
	#$(CC) $(CFLAGS) -o bin/nl src/nl.c
	#$(CC) $(CFLAGS) -o bin/nm src/nm.c
	#$(CC) $(CFLAGS) -o bin/nohup src/nohup.c
	#$(CC) $(CFLAGS) -o bin/od src/od.c
	#$(CC) $(CFLAGS) -o bin/paste src/paste.c
	#$(CC) $(CFLAGS) -o bin/patch src/patch.c
	#$(CC) $(CFLAGS) -o bin/pathchk src/pathchk.c
	#$(CC) $(CFLAGS) -o bin/pax src/pax.c
	#$(CC) $(CFLAGS) -o bin/pr src/pr.c
	#$(CC) $(CFLAGS) -o bin/printf src/printf.c
	#$(CC) $(CFLAGS) -o bin/prs src/prs.c
	#$(CC) $(CFLAGS) -o bin/ps src/ps.c
	#$(CC) $(CFLAGS) -o bin/pwd src/pwd.c
	#$(CC) $(CFLAGS) -o bin/qalter src/qalter.c
	#$(CC) $(CFLAGS) -o bin/qdel src/qdel.c
	#$(CC) $(CFLAGS) -o bin/qhold src/qhold.c
	#$(CC) $(CFLAGS) -o bin/qmove src/qmove.c
	#$(CC) $(CFLAGS) -o bin/qmsg src/qmsg.c
	#$(CC) $(CFLAGS) -o bin/qrerun src/qrerun.c
	#$(CC) $(CFLAGS) -o bin/qrls src/qrls.c
	#$(CC) $(CFLAGS) -o bin/qselect src/qselect.c
	#$(CC) $(CFLAGS) -o bin/qsig src/qsig.c
	#$(CC) $(CFLAGS) -o bin/qstat src/qstat.c
	#$(CC) $(CFLAGS) -o bin/qsub src/qsub.c
	#$(CC) $(CFLAGS) -o bin/read src/read.c
	#$(CC) $(CFLAGS) -o bin/readonly src/readonly.c
	#$(CC) $(CFLAGS) -o bin/renice src/renice.c
	#$(CC) $(CFLAGS) -o bin/return src/return.c
	#$(CC) $(CFLAGS) -o bin/rm src/rm.c
	#$(CC) $(CFLAGS) -o bin/rmdel src/rmdel.c
	#$(CC) $(CFLAGS) -o bin/rmdir src/rmdir.c
	#$(CC) $(CFLAGS) -o bin/sact src/sact.c
	#$(CC) $(CFLAGS) -o bin/sccs src/sccs.c
	#$(CC) $(CFLAGS) -o bin/sed src/sed.c
	#$(CC) $(CFLAGS) -o bin/set src/set.c
	#$(CC) $(CFLAGS) -o bin/sh src/sh.c
	#$(CC) $(CFLAGS) -o bin/shift src/shift.c
	$(CC) $(CFLAGS) -o bin/sleep src/sleep.c
	#$(CC) $(CFLAGS) -o bin/sort src/sort.c
	#$(CC) $(CFLAGS) -o bin/split src/split.c
	#$(CC) $(CFLAGS) -o bin/strings src/strings.c
	#$(CC) $(CFLAGS) -o bin/strip src/strip.c
	#$(CC) $(CFLAGS) -o bin/stty src/stty.c
	#$(CC) $(CFLAGS) -o bin/tabs src/tabs.c
	#$(CC) $(CFLAGS) -o bin/tail src/tail.c
	#$(CC) $(CFLAGS) -o bin/talk src/talk.c
	$(CC) $(CFLAGS) -o bin/tee src/tee.c
	#$(CC) $(CFLAGS) -o bin/test src/test.c
	#$(CC) $(CFLAGS) -o bin/time src/time.c
	#$(CC) $(CFLAGS) -o bin/times src/times.c
	#$(CC) $(CFLAGS) -o bin/touch src/touch.c
	#$(CC) $(CFLAGS) -o bin/tput src/tput.c
	#$(CC) $(CFLAGS) -o bin/tr src/tr.c
	#$(CC) $(CFLAGS) -o bin/trap src/trap.c
	$(CC) $(CFLAGS) -o bin/true src/true.c
	#$(CC) $(CFLAGS) -o bin/tsort src/tsort.c
	#$(CC) $(CFLAGS) -o bin/tty src/tty.c
	#$(CC) $(CFLAGS) -o bin/type src/type.c
	#$(CC) $(CFLAGS) -o bin/ulimit src/ulimit.c
	#$(CC) $(CFLAGS) -o bin/umask src/umask.c
	#$(CC) $(CFLAGS) -o bin/unalias src/unalias.c
	#$(CC) $(CFLAGS) -o bin/uname src/uname.c
	#$(CC) $(CFLAGS) -o bin/uncompress src/uncompress.c
	#$(CC) $(CFLAGS) -o bin/unexpand src/unexpand.c
	#$(CC) $(CFLAGS) -o bin/unget src/unget.c
	#$(CC) $(CFLAGS) -o bin/uniq src/uniq.c
	$(CC) $(CFLAGS) -o bin/unlink src/unlink.c
	#$(CC) $(CFLAGS) -o bin/unset src/unset.c
	#$(CC) $(CFLAGS) -o bin/uucp src/uucp.c
	#$(CC) $(CFLAGS) -o bin/uudecode src/uudecode.c
	#$(CC) $(CFLAGS) -o bin/uuencode src/uuencode.c
	#$(CC) $(CFLAGS) -o bin/uustat src/uustat.c
	#$(CC) $(CFLAGS) -o bin/uux src/uux.c
	#$(CC) $(CFLAGS) -o bin/val src/val.c
	#$(CC) $(CFLAGS) -o bin/vi src/vi.c
	#$(CC) $(CFLAGS) -o bin/wait src/wait.c
	#$(CC) $(CFLAGS) -o bin/wc src/wc.c
	#$(CC) $(CFLAGS) -o bin/what src/what.c
	#$(CC) $(CFLAGS) -o bin/who src/who.c
	#$(CC) $(CFLAGS) -o bin/write src/write.c
	#$(CC) $(CFLAGS) -o bin/xargs src/xargs.c
	#$(CC) $(CFLAGS) -o bin/yacc src/yacc.c
	#$(CC) $(CFLAGS) -o bin/zcat src/zcat.c

clean:
	rm -rf bin/*

