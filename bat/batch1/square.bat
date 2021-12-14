@echo off
set count=2

:loop

set /a count=%count%+2
set /a square = %count% * %count%
set /a rem=%square% %% 1000000
set /a wanted = 269696
if %rem% neq %wanted% goto :loop

@echo on
echo>> %square%