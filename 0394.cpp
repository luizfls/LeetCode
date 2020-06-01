class Solution {
public:
    string decodeString(string s) {
        int endBracket = s.find(']');
        while(endBracket != std::string::npos)
        {
            // positioning opening bracket
            int startBracket = s.rfind('[', endBracket);

            // extract substring inside bracket, the "section"
            std::string section = s.substr(startBracket + 1, endBracket - startBracket - 1);

            // positioning number start
            int startNumber = startBracket - 1;
            while(startNumber >= 0 && std::isdigit(s[startNumber]))
                --startNumber;
            ++startNumber;

            // parse k
            int k = std::stoi(s.substr(startNumber, startBracket - startNumber));

            // expand section k times
            std::string expandedSection;
            while(k-- > 0)
                expandedSection.append(section);

            s.replace(startNumber, endBracket - startNumber + 1, expandedSection);

            endBracket = s.find(']');
        }

        return s;
    }
};
