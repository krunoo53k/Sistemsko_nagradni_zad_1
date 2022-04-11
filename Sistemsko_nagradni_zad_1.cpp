// Sistemsko_nagradni_zad_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
void listFiles(fs::directory_entry entry, int count);
int levels[10000] = {};
int main()
{
    //std::string path = "C:";
    char path[64];
    printf("Enter path:");
    scanf_s("%63s", &path, 64);
    puts("\n");
    for (int i = 0; i < 10000; i++)
        levels[i] = 0;
    for (const auto& entry : fs::directory_iterator(path))
        if (entry.is_directory()) {
            levels[0]++;
            listFiles(entry, 0);
        }
    int i = 0;
    while (levels[i] != 0)
    {
        printf_s("Level %d has %d directories.\n", i, levels[i]);
        i++;
    }
}


void listFiles(fs::directory_entry entry, int count)
{
    count++;
    for (const auto& entry1 : fs::directory_iterator(entry.path()))
        if (entry1.is_directory())
        {
            listFiles(entry1, count);
            levels[count]++;
        }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
