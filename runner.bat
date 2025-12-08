@echo off
chcp 65001 >nul

:: 正确设置工作目录（去掉末尾空格）
for /f "delims=" %%A in ("%~dp0src") do set "WORKDIR=%%A\"

:: 调试：显示实际路径
echo 调试信息：
echo 工作目录实际值: "%WORKDIR%"
echo 检查目录是否存在:
if exist "%WORKDIR%" (echo ✓ 目录存在) else (echo ✗ 目录不存在)
if exist "%WORKDIR%config.json" (echo ✓ config.json存在) else (echo ✗ config.json不存在)
echo.

:: 运行程序
(echo %WORKDIR% & echo all) | main.exe

echo 执行完成