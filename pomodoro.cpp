#include <iostream>
#include <windows.h>

void setColor(int colorCode) 
{

    WORD attributes = static_cast<WORD>(colorCode);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes);
}

void resetColor() 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void startPomodoroTimer(int duration) 
{
    std::cout << "Pomodoro Timer gestartet!" << std::endl;

    // Schleife für die Pomodoro-Phasen
    for (int i = 1; i <= 4; ++i) 
    {
        int pomodoroDuration = duration; // Pausendauer in Sekunden für das Pomodoro

        for (int minute = 1; minute <= pomodoroDuration / 60; ++minute) 
        {
            int remainingTime = pomodoroDuration / 60 - minute;

            // Farben je nach verbleibender Zeit setzen
            if (remainingTime >= 20) {
                setColor(5); // lila
            } else if (remainingTime >= 15) {
                setColor(12); // Rot
            } else if (remainingTime >= 10) {
                setColor(14); // Gelb
            } else if (remainingTime >= 5) {
                setColor(11); // Blau
            } else {
                setColor(10); // Grün
            }

            std::cout << "Pomodoro Phase " << i << " - Arbeit (" << pomodoroDuration / 60 << " Minuten)" << std::endl;
            std::cout << "Verbleibende Zeit: " << remainingTime << " Minuten" << std::endl;

            Sleep(60 * 1000);
        }

        // Pausenzeit zwischen den Pomodoros, außer nach der letzten Phase
        if (i < 4)
        {
            std::cout << "Kurze Pause (5 Minuten)" << std::endl;
            for (int minute = 1; minute <= 5; ++minute) 
            {
                setColor(7); // Standardfarbe
                std::cout << "Verbleibende Zeit: " << 5 - minute << " Minuten" << std::endl;

                Sleep(60 * 1000);
                
            }
        } else {
            resetColor();
            std::cout << "Pomodoro abgeschlossen!" << std::endl;
        }
    }

    resetColor();
}

int main() 
{
    startPomodoroTimer(25 * 60); // 25 Minuten Pomodoro-Phase
    return 0;
}
