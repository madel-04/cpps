/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:11:52 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/16 13:11:52 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceAndWrite(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string outfileName = filename + ".replace";
    std::ofstream outfile(outfileName.c_str());

    if (!outfile)
    {
        std::cerr << "Error: Could not create file " << outfileName << std::endl;
        return;
    }

    std::string line;
    while(std::getline(infile, line))
    {
        size_t position = 0;
        while ((position = line.find(s1, position)) != std::string::npos && !s1.empty())
        {
            line.erase(position, s1.length());
            line.insert(position, s2);
            position += s2.length();
        }
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
    }
}

int main(int argc, char* argv[]) {

    if (argc != 4)
    {
        std::cerr << "To use this program, \"[./replacing]\" [file name] [str 1] [str 2]" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: String 1 cannot be empty!" << std::endl;
        return 1;
    }

    replaceAndWrite(filename, s1, s2);
    return 0;
}
/*
· ✓ Include Libraries: <fstream> for file handling, 
  ✓ <iostream> for input/output, 
  ✓ and <string> for handling text lines.
· Open Files: Use std::ifstream for reading and std::ofstream for writing.
· Error Handling: Check if the files are successfully opened.
· Copy Content: Use std::getline to read each line from the source file and write it to the destination file.
 ! Close Files: Always close files to release resources.
*/