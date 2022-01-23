class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };
    enum CharType {
        CHAR_TYPE_INTEGER,
        CHAR_TYPE_DOT,
        CHAR_TYPE_SIGN,
        CHAR_TYPE_E,
        CHAR_TYPE_SPACE,
        CHAR_TYPE_ILLEGAL
    };
    CharType toCharType(char c){
        if((c>='0')&&(c<='9'))
            return CHAR_TYPE_INTEGER;
        else if(c == '.')
            return CHAR_TYPE_DOT;
        else if(c == 'e'||c == 'E')
            return CHAR_TYPE_E;
        else if(c == '+'||c == '-')
            return CHAR_TYPE_SIGN;
        else if(c == ' ')
            return CHAR_TYPE_SPACE;
        else
            return CHAR_TYPE_ILLEGAL;
    }
    bool isNumber(string s) {
        unordered_map<State,unordered_map<CharType,State>> transfer =
        {
            {
                STATE_INITIAL, {
                    {CHAR_TYPE_INTEGER,STATE_INTEGER},
                    {CHAR_TYPE_SPACE,STATE_INITIAL},
                    {CHAR_TYPE_SIGN,STATE_INT_SIGN},
                    {CHAR_TYPE_DOT,STATE_POINT_WITHOUT_INT}
                }
            },
            {
                STATE_INTEGER, {
                    {CHAR_TYPE_INTEGER,STATE_INTEGER},
                    {CHAR_TYPE_DOT,STATE_FRACTION},
                    {CHAR_TYPE_E,STATE_EXP},
                    {CHAR_TYPE_SPACE,STATE_END}
                }
            },
            {
                STATE_POINT,{
                    {CHAR_TYPE_INTEGER,STATE_FRACTION},
                    {CHAR_TYPE_E,STATE_EXP},
                    {CHAR_TYPE_SPACE,STATE_END}
                }
            },
            {
                STATE_INT_SIGN,{
                    {CHAR_TYPE_INTEGER,STATE_INTEGER},
                    {CHAR_TYPE_DOT,STATE_POINT_WITHOUT_INT}
                }
                
            },
            {
                STATE_POINT_WITHOUT_INT,{
                    {CHAR_TYPE_INTEGER,STATE_FRACTION}
                }
            },
            {
                STATE_FRACTION,{
                    {CHAR_TYPE_INTEGER,STATE_FRACTION},
                    {CHAR_TYPE_E,STATE_EXP},
                    {CHAR_TYPE_SPACE,STATE_END}
                }
            },
            {
                STATE_EXP,{
                    {CHAR_TYPE_SIGN,STATE_EXP_SIGN},
                    {CHAR_TYPE_INTEGER,STATE_EXP_NUMBER}
                }
            },
            {
                STATE_EXP_SIGN,{
                    {CHAR_TYPE_INTEGER,STATE_EXP_NUMBER}
                }
            },
            {
                STATE_EXP_NUMBER,{
                    {CHAR_TYPE_INTEGER,STATE_EXP_NUMBER},
                    {CHAR_TYPE_SPACE,STATE_END}
                }
            },
            {
                STATE_END,{
                    {CHAR_TYPE_SPACE,STATE_END}
                }
            }
        };
        State state = STATE_INITIAL;
        for(auto c:s)
        {
            CharType type = toCharType(c);
            //cout<<type;
            auto map = transfer[state];
            if(map.find(type) == map.end())
                return false;
            state = map[type];
        }
        return (state == STATE_INTEGER||state == STATE_FRACTION||state == STATE_POINT||state == STATE_EXP_NUMBER||state == STATE_END);
    }
};