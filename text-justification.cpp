#include <math.h>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth)
    {
        int numWords = words.size();
        // current line size of the words that are appended until now, contains single spaces between words also
        int tempLineSize = 0;
        // how many words are already processed
        int tempIndex = 0;
        // lines that contain words just like in the result but with no spaces between them
        std::vector<std::vector<std::string>> lines;
        // current line
        std::vector<std::string> line;
        while (true)
        {
            if (tempIndex == numWords)
                break;

            int currentWordSize = words[tempIndex].size();

            // size of the word if it's first word, size of the word + 1 space if it's any other word
            int newElementSize = currentWordSize;
            if (line.size() != 0)
            {
                newElementSize += 1;
            }

            // see if it's possible to add current word to the current line
            if (tempLineSize + newElementSize <= maxWidth)
            {
                tempLineSize += newElementSize;
            }
            else
            {
                // if not possible current line is finished and new begins
                lines.push_back(line);
                line.clear();
                tempLineSize = currentWordSize;
            }
            line.push_back(words[tempIndex]);
            tempIndex++;
        }
        // if there are any words left in the last line, add that line
        if (line.size() != 0)
        {
            lines.push_back(line);
        }

        int linesSize = lines.size();
        std::vector<std::string> adjustedWords;
        for (int r = 0; r < linesSize; r++)
        {
            auto row = lines[r];
            int wordsInRow = row.size();

            // total length of the words in current line
            int wordsSize = 0;
            for (auto word : row)
            {
                wordsSize += word.size();
            }

            // epmpty space that must be split as even as possible to justify words in line
            int unusedSpace = maxWidth - wordsSize;

            std::vector<int> spaces;
            // calculate how big are spaces between words
            while (true)
            {
                float res;
                if (wordsInRow == 1)
                {
                    res = unusedSpace;
                }
                else
                {
                    // unused space must be split between words and can be uneven
                    res = (float)unusedSpace / (wordsInRow - 1 - spaces.size());
                    if (res != std::floor(res))
                    {
                        res = std::ceil(res);
                    }
                }
                unusedSpace -= (int)res;
                spaces.push_back((int)res);
                if (unusedSpace <= 0)
                    break;
            }

            // copy words in their resulting strings and add spaces
            std::string rowStr(maxWidth, ' ');
            int index = 0;
            for (int i = 0; i < wordsInRow; i++)
            {
                for (int j = 0; j < row[i].size(); j++)
                {
                    rowStr[index] = row[i][j];
                    index++;
                }

                // last line has special spacing, justified to left, single space between words
                if (spaces.size() != 0 && i < spaces.size())
                {
                    if (r == linesSize - 1)
                    {
                        index++;
                    }
                    else
                    {
                        index = index + spaces[i];
                    }
                }
            }
            adjustedWords.push_back(rowStr);
        }
        return adjustedWords;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> words{"This", "is", "an", "example", "of", "text", "justification."};
    words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    // words = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    // words = {"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country"};
    int maxWidth = 16;
    // maxWidth = 20;
    auto res = s.fullJustify(words, maxWidth);
    for (auto r : res)
    {
        std::cout << r << std::endl;
    }
    return 0;
}