@echo off
chcp 65001 >nul
setlocal EnableDelayedExpansion

:: 0. 诊断信息
echo ======================
echo 脚本所在目录=%~dp0
echo 当前工作目录=%cd%
echo 是否存在 src 目录: exist "%~dp0src\" && echo 是 || echo 否
echo ======================
pause

:: 1. 强制切换到脚本目录
cd /d "%~dp0"
set "WORKDIR=%~dp0"

:: 2. 检查 src
if not exist "%WORKDIR%src\" (
    echo [ERROR] 找不到 src 目录: %WORKDIR%src\
    dir "%WORKDIR%"
    pause
    exit /b 1
)

:: 3. 生成输入
set "INPUT=%temp%\%~n0_%random%.tmp"
(
    echo %WORKDIR%src\
    echo all
) > "%INPUT%"

:: 4. 检查 main.exe
if not exist "main.exe" (
    echo [ERROR] 找不到 main.exe
    dir *.exe
    pause
    exit /b 1
)

:: 5. 运行并捕获返回值
echo 开始自动化评测 (All Mode)...
main.exe < "%INPUT%"
if errorlevel 1 (
    echo [ERROR] main.exe 异常退出，返回码=%errorlevel%
    pause
    exit /b %errorlevel%
)

:: 6. 清理
del "%INPUT%" 2>nul

:: 7. 结果
echo.
echo 评测完成！
dir /b *.zip 2>nul && (
    echo 生成的打包文件:
    dir /b *.zip
) || (
    echo 未找到打包文件
)
pause
