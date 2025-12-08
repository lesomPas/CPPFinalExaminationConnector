chcp 65001 >nul
setlocal EnableDelayedExpansion

echo ===== 自动化评测脚本 (备用方案) =====

:: 1. 设置工作目录
set "WORKDIR=%~dp0src\"
echo 工作目录: %WORKDIR%

:: 2. 检查必要文件
if not exist "main.exe" (
    echo 错误: 找不到 main.exe
    exit /b 1
)

if not exist "%WORKDIR%\config.json" (
    echo 错误: 找不到 %WORKDIR%\config.json
    exit /b 1
)

:: 3. 创建输入序列文件（关键！）
set "INPUT_FILE=%temp%\judge_input_%RANDOM%.tmp"
echo 创建输入文件: %INPUT_FILE%

:: 写入输入序列：
:: 第一行：工作目录
:: 等待程序处理
:: 第二行：all 命令
(
    echo %WORKDIR%
    timeout /t 2 /nobreak >nul
    echo all
    echo exit
) > "%INPUT_FILE%"

echo 输入文件内容:
type "%INPUT_FILE%"
echo.

:: 4. 运行程序并捕获输出
echo 启动 main.exe...
echo ================================
main.exe < "%INPUT_FILE%"
set "EXIT_CODE=%ERRORLEVEL%"
echo ================================
echo 程序退出代码: %EXIT_CODE%

:: 5. 清理和结果展示
if exist "%INPUT_FILE%" del "%INPUT_FILE%"

echo.
echo 生成的文件:
dir /b *.zip 2>nul && (
    echo 找到结果文件:
    dir /b *.zip
) || (
    echo 未找到结果文件
)

echo.
pause
exit /b %EXIT_CODE