@echo off

call :is_palindrome %1
if %ERRORLEVEL% == 0 (
    echo %1 is a palindrome
) else (
    echo %1 is NOT a palindrome
)
exit /B 0

:is_palindrome
    set word=%~1
    set reverse=
    call :reverse_chars "%word%"
    set return=1
    if "$%word%" == "$%reverse%" (
        set return=0
    )
exit /B %return%

:reverse_chars
    set chars=%~1
    set reverse=%chars:~0,1%%reverse%
    set chars=%chars:~1%
    if "$%chars%" == "$" (
        exit /B 0
    ) else (
        call :reverse_chars "%chars%"
    )
exit /B 0