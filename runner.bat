@echo off
chcp 65001 >nul
setlocal EnableDelayedExpansion

:: 1. 取脚本所在目录（末尾带 \）
set "WORKDIR=%~dp0"

:: 2. 检查 src 目录是否存在
if not exist "%WORKDIR%src\" (
    echo [ERROR] 找不到 src 目录: %WORKDIR%src\
    dir "%WORKDIR%"
    exit /b 1
)

:: 3. 生成两行指令的临时文件
set "INPUT=%temp%\%~n0_%random%.tmp"
(
    echo %WORKDIR%src\
    echo all
) > "%INPUT%"

:: 4. 一次性喂给 main.exe（只启动一次）
echo 工作目录: %WORKDIR%src\
echo 开始自动化评测 (All Mode)...

:: 检查 main.exe 是否存在
if not exist "main.exe" (
    echo [ERROR] 找不到 main.exe
    dir *.exe
    exit /b 1
)

main.exe < "%INPUT%"

:: 5. 清理
if exist "%INPUT%" del "%INPUT%" 2>nul

:: 6. 结果展示
echo.
echo 评测完成！

dir /b *.zip 2>nul && (
    echo 生成的打包文件:
    dir /b *.zip
) || (
    echo 未找到打包文件
)

pause