# Pomodoro Timer in C++
Dieses C++-Programm implementiert einen einfachen Pomodoro-Timer, der die Pomodoro-Technik zur Verbesserung der Produktivität anwendet.

## Lizenz
Open-Source, frei für private und gewerbliche Zwecke.

## Verwendung
Das Programm durchläuft vier Pomodoro-Phasen, wobei jede Phase 25 Minuten Arbeit mit kurzen Pausen von 5 Minuten zwischen den Phasen und einer längeren Pause von 15 Minuten nach der vierten Phase kombiniert. Die verbleibende Zeit wird jede Minute in der Konsole angezeigt, und die Textfarben ändern sich basierend auf der verbleibenden Zeit.

## Kompilieren und Ausführen
Das Programm verwendet ANSI Escape Codes für die Farbänderungen und die `windows.h`-Bibliothek für die `Sleep`-Funktion auf Windows-Systemen. Beim Kompilieren sollten Sie sicherstellen, dass die ANSI Escape Codes und die `windows.h`-Bibliothek auf Ihrem System unterstützt werden.

### Kompilieren
```bash
g++ pomodoro.cpp -o pomodoro.exe

### Ausführen
./pomodoro.exe
