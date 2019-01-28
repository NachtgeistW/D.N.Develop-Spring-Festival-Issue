@echo off
cls
set /p turn=天使我们跑几圈？ 
if %turn% leq 0 (
    echo 那我们不跑了
)else (
    for /l %%i in (1,1,%turn%) do (
        echo 夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！
        ping 0.0.0.0 -n 2 >nul
    )
    echo 跑完了
)
pause >nul