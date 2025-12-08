@echo off
chcp 65001 >nul

:: 设置工作目录
set "WORK_DIR=%~dp0src"
for %%I in ("%WORK_DIR%") do set "WORK_DIR=%%~fI"

:: 使用临时文件代替管道，避免管道导致的退出码问题
echo %WORK_DIR% > input.tmp
echo all >> input.tmp
echo exit >> input.tmp

:: 从文件读取输入，并将输出打印到屏幕
checker.exe < input.tmp

:: 获取退出码
set EXIT_CODE=%ERRORLEVEL%

:: 清理临时文件
del input.tmp

:: 显式退出，传递退出码
exit /b %EXIT_CODE%
