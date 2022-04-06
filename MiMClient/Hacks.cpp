#include "Hacks.h"

std::string Hacks::Hack(const std::string &std)
{
    std::string Std = "";
    Std.clear();
    for(int c = 0;c<std.size();c++)
    {
        if(c>7)
        {
            if(
            (&std[c-6] == "H" || &std[c-6] == "h") &&
            (&std[c-5] == "T" || &std[c-5] == "t") &&
            (&std[c-4] == "T" || &std[c-4] == "t") &&
            (&std[c-3] == "P" || &std[c-3] == "p") &&
            &std[c-2] == ":" &&
            &std[c-1] == "/" &&
            &std[c] == "/"
            )
            {
                Std += std[c];
                Std += "127.0.0.1/";
            }
            else
            {
                Std += std[c];
            }
        }
        else
        {
            Std += std[c];
        }
    }

    return Std;
}
