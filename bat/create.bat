@echo off
mkdir %1
mkdir %1\\ALGEBRA_GEOMETRY
mkdir %1\\CALCULUS
mkdir %1\\PROGRAMMING
mkdir %1\\DISCRETEMATH
echo Лекции: Погожев Сергей Владимирович. > %1\\ALGEBRA_GEOMETRY\\readme.txt
echo Практика: Балыкина Юлия Ефимовна >> %1\\ALGEBRA_GEOMETRY\\readme.txt 
echo Начало занятий: %date% >> %1\\ALGEBRA_GEOMETRY\\readme.txt
rem 1
echo Лекции: Платонов А. В. > %1\\CALCULUS\\readme.txt 
echo Практика: Мышков С. К. >> %1\\CALCULUS\\readme.txt
echo Начало занятий: %date% >> %1\\CALCULUS\\readme.txt
rem 2
echo Лекции: Погожев С. В. > %1\\PROGRAMMING\\readme.txt 
echo Начало занятий: %date% >> %1\\PROGRAMMING\\readme.txt
rem 3
echo Лекции: Погожев С. В. > %1\\DISCRETEMATH\\readme.txt 
echo Практика: Воронкова Е. Б. >> %1\\DISCRETEMATH\\readme.txt
echo Начало занятий: %date% >> %1\\DISCRETEMATH\\readme.txt
rem 4
copy op.bat %1\\PROGRAMMING
rem 5
copy algem.bat %1\\ALGEBRA_GEOMETRY