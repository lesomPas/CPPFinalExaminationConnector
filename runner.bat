@echo off
chcp 65001 >nul

:: AutoJudge Runner - Final Mode
:: ======================================

:: 假设 runner.bat 放在项目根目录
:: 1. 设置工作目录为 "src" 文件夹 (根据你的实际情况修改)
set WORK_DIR=%~dp0src

:: 2. 按顺序传递输入：
::    第一行：工作目录路径 (对应 main.cpp 中的 dir.getline(std::cin))
::    第二行：all (对应 Checker::run() 中的指令)
::    第三行：exit (评测结束后退出程序，防止挂起)
(
    echo %WORK_DIR%
    echo all
    echo exit
) | main.exe

echo.
echo [Info] 评测流程结束。
