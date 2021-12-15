#include <iostream>
#include <fstream>
#include <iomanip>


int tex2wiki(int argc, const char* argv[]) {
    if (argc < 3)
        return 1;

    // Open input file
    std::ifstream tex(argv[1]);
    if (!tex.is_open())
        return 2;
    // Create output file
    std::ofstream wiki(argv[2]);
    if (!wiki.is_open())
        return 3;

    char c;
    int k = 0;
    bool is_tag_opened = false;
    while ((c = tex.get()) != EOF) {
        if (c != '$') {
            wiki << c;
            continue;
        }
        if (is_tag_opened)
            wiki << "</math>";
        else
            wiki << "<math>";
        is_tag_opened = !is_tag_opened;
        if (tex.peek() == '$') {
            tex.get();
        }
    }
    tex.close();
    wiki.close();
    return 0;
}


int file2hex(int argc, const char* argv[]) {
    if (argc == 1)
        return 1;

    std::ifstream file(argv[1], std::ifstream::in);


    if (!file.is_open())
        return 2;



    unsigned char c;
    std::string str_output = "";
    int counter = 0, global_counter = 0;
    while ((c = file.get()) != (unsigned char)EOF)
    {
        if (counter == 0)
            std::cout << std::setfill('0') << std::setw(10) << std::hex << 16 * global_counter << ": ";

        str_output += c;

        std::cout << std::setfill('0') << std::setw(2) << std::hex << (unsigned int)c << " ";
        counter++;

        if (counter == 7)
            std::cout << " |  ";
        else if (counter == 15) {
            std::cout << "  " + str_output << std::endl;
            counter = 0;
            str_output = "";
            global_counter++;
        }
    }
    if (counter != 0) {
        while (counter < 16)
        {
            std::cout << "   ";
            if (counter == 7)
                std::cout << " |  ";
            counter++;
        }
        std::cout << "  " + str_output << std::endl;
    }

    file.close();
    return 0;
}

int main(int argc, const char* argv[]) {
    return file2hex(argc, argv);
}