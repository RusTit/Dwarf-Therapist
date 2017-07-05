#ifndef CUSTOMHTMLWORDWRAP_H
#define CUSTOMHTMLWORDWRAP_H

const int MAX_CHARACTERS_IN_LINE = 100;
class CustomHtmlWordWrap
{
public:
    static QString ProcessString(const QString& longString, const int& maxCharCount = MAX_CHARACTERS_IN_LINE)
    {
        QString result = QString("<p style=\"white-space:pre\">");
            if (longString.length() > maxCharCount) {
                int position_start = 0;
                int position = maxCharCount;
                while (true) {
                    position = longString.indexOf(" ", position);
                    if (position_start != 0) {
                        result.append("<br />");
                    }
                    if (position == -1) {
                        position = longString.length() - 1;
                    }
                    result.append(longString.mid(position_start, position - position_start));
                    ++position;
                    const auto len = longString.length();
                    if (position >= len) {
                        break;
                    }
                    position_start = position;
                    position += maxCharCount;
                }
            } else {
                result.append(longString);
            }
            result.append("</p>");
            return result;
    }
private:
    CustomHtmlWordWrap() {}
};

#endif // CUSTOMHTMLWORDWRAP_H
