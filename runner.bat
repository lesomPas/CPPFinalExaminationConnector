@echo off
chcp 65001 >nul

:: 设置工作目录 (使用引号保护路径，并去除末尾反斜杠以避免歧义)
set "WORK_DIR=%~dp0src"

:: 去除路径末尾可能存在的反斜杠，并确保格式正确 (这能有效防止空格产生)
:: 这一步利用了 for 变量修饰符来规范化路径
for %%I in ("%WORK_DIR%") do set "WORK_DIR=%%~fI"

:: 执行
echo [Info] 使用工作目录: "%WORK_DIR%"
(
    echo %WORK_DIR%
    echo all
    echo exit
) | .\main.exe

echo.
echo [Info] 评测流程结束。
