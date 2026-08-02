/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/07/31 00:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static std::string readFile(const std::string &filename)
{
    std::ifstream input(filename.c_str());
    std::ostringstream buffer;
    char c;

    if (!input.is_open())
        return std::string();
    while (input.get(c))
        buffer << c;
    return buffer.str();
}

static std::string replaceAll(const std::string &content,
                              const std::string &s1,
                              const std::string &s2)
{
    std::string result;
    std::string::size_type start = 0;
    std::string::size_type pos = content.find(s1, start);

    while (pos != std::string::npos)
    {
        result += content.substr(start, pos - start);
        result += s2;
        start = pos + s1.length();
        pos = content.find(s1, start);
    }
    result += content.substr(start);
    return result;
}

static bool writeFile(const std::string &filename, const std::string &content)
{
    std::ofstream output(filename.c_str());

    if (!output.is_open())
        return false;
    output << content;
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return 1;
    }

    const std::string content = readFile(filename);
    if (content.empty() && !std::ifstream(filename.c_str()).good())
    {
        std::cerr << "Error: cannot open input file" << std::endl;
        return 1;
    }

    const std::string outputName = filename + ".replace";
    const std::string replaced = replaceAll(content, s1, s2);

    if (!writeFile(outputName, replaced))
    {
        std::cerr << "Error: cannot open output file" << std::endl;
        return 1;
    }
    return 0;
}
