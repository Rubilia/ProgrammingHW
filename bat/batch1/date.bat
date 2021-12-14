@echo off
set /a nul = 0
set /a B = %1
set /a four=%B% %% 4
set /a fourh=%B% %% 400
set /a hund=%B% %% 100
if %four% equ %nul% (goto stage2) else (goto badend)
:stage2
if %hund% neq %nul% (goto goodend) else (goto stage3)

:goodend
echo %1 is leap year
goto break

:stage3
if %fourh% equ %nul% (goto goodend) else (goto badend)
:badend
echo %1 is NOT a leap year
:break