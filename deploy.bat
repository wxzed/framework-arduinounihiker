@echo off
setlocal enabledelayedexpansion

REM Framework Arduino UNIHIKER 部署脚本 (Windows)
REM 使用方法: deploy.bat [版本号]

set VERSION=%1
if "%VERSION%"=="" set VERSION=1.0.0
set REPO_NAME=framework-arduinounihiker

echo 🚀 开始部署 Framework Arduino UNIHIKER v%VERSION%

REM 检查 Git 是否已初始化
if not exist ".git" (
    echo 📁 初始化 Git 仓库...
    git init
    git add .
    git commit -m "Initial commit: %REPO_NAME% v%VERSION%"
    git branch -M main
    echo ⚠️  请手动添加远程仓库:
    echo    git remote add origin https://github.com/您的用户名/%REPO_NAME%.git
    echo    git push -u origin main
    pause
    exit /b 1
)

REM 检查是否有未提交的更改
git diff-index --quiet HEAD
if errorlevel 1 (
    echo 📝 提交更改...
    git add .
    git commit -m "Update: %REPO_NAME% v%VERSION%"
)

REM 创建标签
echo 🏷️  创建版本标签 v%VERSION%...
git tag -a "v%VERSION%" -m "Release version %VERSION%"

REM 推送到远程仓库
echo 📤 推送到远程仓库...
git push origin main
git push origin "v%VERSION%"

echo ✅ 部署完成！
echo.
echo 📋 下一步操作：
echo 1. 在 GitHub 上创建 Release v%VERSION%
echo 2. 在用户的 platformio.ini 中添加：
echo    platform = https://github.com/您的用户名/%REPO_NAME%.git#v%VERSION%
echo.
echo 🎉 恭喜！您的框架已经可以供其他人使用了！
pause


