@echo off
set "targetDir=%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
set "currentDir=%cd%"

echo Создание ярлыка автозагрузки...
powershell "$s=(New-Object -COM WScript.Shell).CreateShortcut('%targetDir%\TrollClock.lnk');$s.TargetPath='%currentDir%\run_server.bat';$s.Save()"

echo Готово! Теперь часы будут "врать" после каждого перезапуска.
pause
