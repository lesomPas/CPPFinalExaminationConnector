@echo off
chcp 65001 >nul
setlocal EnableDelayedExpansion

:: 1. 取脚本所在目录（末尾带 \）
set "WORKDIR=%~dp0"

:: 2. 生成两行指令的临时文件
set "INPUT=%temp%\%~n0_%random%.tmp"
(
    echo %WORKDIR%
    echo all
) > "%INPUT%"

:: 3. 一次性喂给 main.exe（只启动一次）
echo 工作目录: %WORKDIR%
echo 开始自动化评测 (All Mode)...
"<MAIN_PATH>\main.exe" < "%INPUT%"

:: 4. 清理
del "%INPUT%" 2>nul

:: 5. 结果展示
echo.
echo 评测完成！
dir /b *.zip 2>nul && (echo 生成的打包文件:) && dir /b *.zip
pause
