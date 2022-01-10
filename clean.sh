find -type d -name Debug -exec rm -rv {} +
find -type d -name Release -exec rm -rv {} +
find -type d -name .vscode -exec rm -rv {} +
find -type f -name *.pro.user -delete
find -type f -name *.exe -delete
find -type f -name *.o -delete
