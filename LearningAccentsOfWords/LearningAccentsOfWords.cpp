// A program for learning the accents of Russian words

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>


void process(std::vector<std::wstring>& words);
char rus_tolower(wchar_t c);
void fill_vector(std::vector<std::wstring>& words, std::wfstream& file);
void terminate_program();


int main()
{
    std::wfstream file("base.txt");
    std::vector<std::wstring> words;

    if (!file.is_open()) { // checking out if the file exists
        std::cout << "Failed to open the base file. Create it in the directory where the executable is and run the program again\n";
        terminate_program();
        return 0;
    }

    fill_vector(words, file);
    process(words);
    return 0;
}

void process(std::vector<std::wstring>& words)
{
    std::srand(std::time(0));
    while (true) {
        std::wstring s;
        std::wstring word = words[std::rand() % words.size()];
        for (wchar_t c : word)
            std::wcout << rus_tolower(c);
        std::wcout << L' ';
        std::wcin >> s;
        if (s != word)
            std::wcout << L"correctly: " << word << L'\n';
    }
}

char rus_tolower(wchar_t c)
{
    if (c >= L'À' && c <= L'ß')
        c += L'à' - L'À';
    return c;
}

void fill_vector(std::vector<std::wstring>& words, std::wfstream& file)
{
    std::wstring s;
    while (file >> s)
        words.push_back(s);
}

void terminate_program()
{
    std::cin.get();
}

