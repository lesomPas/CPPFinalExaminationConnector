@echo off
chcp 65001 >nul

set "WORKDIR=%~dp0src\"

:: 使用管道一次性传递所有输入
(echo %WORKDIR% & echo all) | main.exe