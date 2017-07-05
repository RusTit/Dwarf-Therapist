#ifndef CUSTOMHTMLWORDWRAP_H
#define CUSTOMHTMLWORDWRAP_H
#include <QString>

const int MAX_CHARACTERS_IN_LINE = 100;
class CustomHtmlWordWrap
{
public:
    static QString ProcessString(const QString& longString, const int& maxCharCount = MAX_CHARACTERS_IN_LINE)
    {
        QString result = QString("<p style=\"white-space:pre\">");
        const auto reserve_chars = longString.length() < maxCharCount ? longString.length() + 50 : ((longString.length() / maxCharCount) + 1) * maxCharCount;
        result.reserve(reserve_chars);
        size_t counter = 0;
        bool is_tag = false;
        for (int i = 0; i < longString.length(); ++i) {
            const auto& ch = longString[i];
            if (ch == "<") {
                is_tag = true;
            } else {
                if (counter > maxCharCount) {
                    if (ch == " " && is_tag == false) {
                        result.append("<br />");
                        counter = 0;
                        continue;
                    }
                }
            }
            result.append(ch);
            if (!is_tag) {
                ++counter;
            }
            if (ch == ">") {
                is_tag = false;
            }
        }
        result.append("</p>");
        return result;
    }
private:
    CustomHtmlWordWrap() {}
};

#endif // CUSTOMHTMLWORDWRAP_H
