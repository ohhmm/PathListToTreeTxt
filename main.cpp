#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

// Function to sort the lines
void sortLines(std::vector<std::string>& lines) {
    std::sort(lines.begin(), lines.end());
}

// Function to replace parent matches with tabs
void replaceParentMatches(std::vector<std::string>& lines) {
    for (size_t i = 1; i < lines.size(); ++i) {
        size_t j = i;
        while (j > 0) {
            if (lines[i].find(lines[j - 1]) == 0) {
                lines[i] = std::string(j, '\t') + lines[i].substr(lines[j - 1].length());
                break;
            }
            --j;
        }
    }
}

int main() {
    std::ifstream inputFile(SRC_DIR "path_list.txt");
    std::ofstream outputFile("tree_structure.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Error: Could not open files." << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Step 1: Sort the lines
    sortLines(lines);

    // Step 2: Replace parent matches with tabs
    replaceParentMatches(lines);

    // Write the formatted lines to the output file
    for (const std::string& formattedLine : lines) {
        outputFile << formattedLine << std::endl;
    }

    return 0;
}
