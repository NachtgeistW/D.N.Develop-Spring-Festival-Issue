@echo off

set suf= Uploaded
for /f %%i in ('date /T') do set date=%%i
set cmsg=%date%%suf%
::echo %cmsg%

git add .
git commit -m "%cmsg%"
git push origin master

pause
