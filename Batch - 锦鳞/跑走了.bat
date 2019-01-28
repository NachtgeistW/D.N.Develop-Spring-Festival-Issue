@echo off
cls
set turn=1
:loop
if not exist %turn%.txt (
    echo 夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！>%turn%.txt
    echo 跑到%turn%.txt去了
    ping 0.0.0.0 -n 3 >nul
)
set /a turn+=1
goto loop