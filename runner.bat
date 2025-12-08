@echo off
chcp 65001 >nul
setlocal

:: 1. 定位工作目录
set "WORKDIR=%~dp0src"
echo 工作目录: %WORKDIR%

:: 2. 等待 10 秒
timeout /t 10 /nobreak >nul

:: 3. 一次性输入 all
echo all | main.exe

:: 4. 停住看一眼结果
echo 评测结束。
pause
