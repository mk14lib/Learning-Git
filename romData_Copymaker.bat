@cls
@echo off
echo *********Running Binary Copy Maker**********
set /p var="Enter the checksum: "
set var=%var:~2,4% 
set prefix=0000
set suffix=.bin

set final=%prefix%%var%%suffix%
set final=%final: =%

@copy nul > %final%
set /p filepath="Provide the filepath with extension: "
echo Generated file: %final%
@copy %filepath% .\%final% 
echo ********************************************
echo.
echo ***********Running MVF Generator************

@.\MVF_Generator.exe