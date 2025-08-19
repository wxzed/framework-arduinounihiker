#!/bin/bash

# Framework Arduino UNIHIKER 部署脚本
# 使用方法: ./deploy.sh [版本号]

VERSION=${1:-1.0.0}
REPO_NAME="framework-arduinounihiker"

echo "🚀 开始部署 Framework Arduino UNIHIKER v$VERSION"

# 检查 Git 是否已初始化
if [ ! -d ".git" ]; then
    echo "📁 初始化 Git 仓库..."
    git init
    git add .
    git commit -m "Initial commit: $REPO_NAME v$VERSION"
    git branch -M main
    echo "⚠️  请手动添加远程仓库:"
    echo "   git remote add origin https://github.com/您的用户名/$REPO_NAME.git"
    echo "   git push -u origin main"
    exit 1
fi

# 检查是否有未提交的更改
if [ -n "$(git status --porcelain)" ]; then
    echo "📝 提交更改..."
    git add .
    git commit -m "Update: $REPO_NAME v$VERSION"
fi

# 创建标签
echo "🏷️  创建版本标签 v$VERSION..."
git tag -a "v$VERSION" -m "Release version $VERSION"

# 推送到远程仓库
echo "📤 推送到远程仓库..."
git push origin main
git push origin "v$VERSION"

echo "✅ 部署完成！"
echo ""
echo "📋 下一步操作："
echo "1. 在 GitHub 上创建 Release v$VERSION"
echo "2. 在用户的 platformio.ini 中添加："
echo "   platform = https://github.com/您的用户名/$REPO_NAME.git#v$VERSION"
echo ""
echo "🎉 恭喜！您的框架已经可以供其他人使用了！"


