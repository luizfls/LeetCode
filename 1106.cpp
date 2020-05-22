class Solution {
public:
    bool parseBoolExpr(string expression) {
        auto close = expression.find(')');
        while(close != std::string::npos)
        {
            auto open = expression.rfind('(', close);
            auto op = open - 1;
            if(expression[op] == '!')
            {
                expression.replace(op, close - op + 1, expression[open + 1] == 't' ? "f" : "t");
            }
            else if(expression[op] == '&')
            {
                bool hasFalse = std::any_of(expression.begin() + open, expression.begin() + close,
                                            [](char c){ return c == 'f'; });
                expression.replace(op, close - op + 1, hasFalse ? "f" : "t");
            }
            else if(expression[op] == '|')
            {
                bool hasTrue = std::any_of(expression.begin() + open, expression.begin() + close,
                                           [](char c){ return c == 't'; });
                expression.replace(op, close - op + 1, hasTrue ? "t" : "f");
            }

            close = expression.find(')');
        }

        return expression == "t";
    }
};
