
osascript -e 'tell application "Dropbox" to quit'
particle compile core ../GRID_LED_SEARCH --saveTo grid.bin
open -a "Dropbox"
