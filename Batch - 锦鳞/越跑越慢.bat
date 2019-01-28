@echo off
cls
set time=1000
:loop
echo 夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！
ping 192.168.255.255 -n 1 -w %time% >nul
set /a time+=100
goto loop