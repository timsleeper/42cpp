#include <fstream>
#include <iostream>
#include <string>

std::string replace_all(const std::string &source, const std::string &search, const std::string &replace)
{
    std::string result = source;
    std::string::size_type pos = 0;
    while ((pos = result.find(search, pos)) != std::string::npos)
    {
        result.erase(pos, search.length());
        result.insert(pos, replace);
        pos += replace.length();
    }
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    std::ifstream input_file(filename.c_str());
    if (!input_file)
    {
        std::cerr << "Error: Unable to open input file '" << filename << "'" << std::endl;
        return 1;
    }

    std::string output_filename = filename + ".replace";
    std::ofstream output_file(output_filename.c_str());
    if (!output_file)
    {
        std::cerr << "Error: Unable to open output file '" << output_filename << "'" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line))
    {
        output_file << replace_all(line, s1, s2) << std::endl;
    }

    input_file.close();
    output_file.close();

    return 0;
}