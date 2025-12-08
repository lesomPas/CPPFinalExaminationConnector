@echo off
chcp 65001 >nul
setlocal

:: 1. 先定位工作目录（但不立刻传）
set "WORKDIR=%~dp0src"
echo 10 秒后将自动输入工作目录：%WORKDIR%
echo 等待中...
timeout /t 10 /nobreak >nul

:: 2. 10 秒后再生成输入内容
set "INPUT=%temp%\%~n0_%random%.tmp"
echo %WORKDIR% > "%INPUT%"
echo all >> "%INPUT%"

:: 3. 一次性喂给 main.exe
main.exe < "%INPUT%"

:: 4. 清理 & 结束
del "%INPUT%" 2>nul
echo 评测结束。
pause
