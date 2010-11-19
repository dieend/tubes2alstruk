@echo off
gcc -o "tes" main.c global/variable.c ^
 commandProcessing/commandProcessing.c ^
 modusDocument/modusDocument.c ^
 modusDocument/delete/delete.c ^
 modusDocument/exit/exit.c ^
 modusDocument/find/find.c ^
 modusDocument/list/list.c ^
 modusDocument/new/new.c ^
 modusFile/modusFile.c ^
 modusFile/strukturData/worksheet.c ^
 -Wall
pause
